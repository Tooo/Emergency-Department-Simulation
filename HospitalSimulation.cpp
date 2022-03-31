#include "HospitalSimulation.h"

HospitalSimulation::HospitalSimulation(PatientManager* patient_manager, int capacity, int rooms, int triage_nurses, int janitors) {
    this->patient_manager = patient_manager;
    queue_manager = new QueueManager();
    stats_manager = new StatsManager();
    this->capacity = capacity;
    this->rooms = rooms;
    this->triage_nurses = triage_nurses;
    this->janitors = janitors;
    
    current_time = 0;
    
    // 24 hours is 1440min
    closing_time = 1440; 
}

HospitalSimulation::~HospitalSimulation() {
    delete queue_manager;
    delete stats_manager;
}

/*
    Patient Arrives for Evaluation
  - Enqueue next arrival of next patient
  - If Hospital full -> transfer patient 
  - If triage_nurses avaliable -> Enqueue start_ev event 
  - Else Enqueue patient to EQueue
*/
void HospitalSimulation::arriveEvaluation(Patient* patient) {
    Patient next_patient = patient_manager->getNextPatient();
    double next_time = next_patient.arrival_time;
    queue_manager->enqueueEventQueue(next_time, Event::ARRIVE_EVALUATION, next_patient);

    if (stats_manager->patient_hospital_count < capacity) {
        stats_manager->patient_hospital_count++;

        if (triage_nurses > 0) {
            double event_time = current_time;
            queue_manager->enqueueEventQueue(event_time, Event::START_EVALUATION, *patient);
        } else {
            patient->waited_e = true;
            queue_manager->enqueueEQueue(*patient);
        }

    } else {
        stats_manager->patient_transfered_count++;
    }
}

/*
    Patient Starts Evaluation
  - Decrement triage_nurses
  - If patient waited_e -> calculate waiting_e
  - Enqueue depart_ev event
*/
void HospitalSimulation::startEvaluation(Patient* patient) {
    triage_nurses--;

    if (patient->waited_e) {
        patient->waiting_e = current_time - patient->arrival_time;
    }

    double event_time = current_time + patient->evaluation_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_EVALUATION, *patient);
}

/*
    Patient Departs Evaluation
  - Increment triage_nurses
  - Enqueue arrive_em
  - If e waiting patient -> enqueue start_ev
*/
void HospitalSimulation::departEvaluation(Patient* patient) {
    triage_nurses++;

    queue_manager->enqueueEventQueue(current_time, Event::ARRIVE_EMERGENCY, *patient);

    if (!queue_manager->isEmptyEQueue()) {
        Patient waiting_patient = queue_manager->dequeueEQueue();
        queue_manager->enqueueEventQueue(current_time, Event::START_EVALUATION, waiting_patient);
    }
}

/*
    Patient Arrives for Emergency
  - If rooms avaliable -> start_em
  - Else Enqueue patient to PQueue
*/
void HospitalSimulation::arriveEmergency(Patient* patient) {
    patient->arrival_emergency = current_time;

    if (rooms > 0) {
        queue_manager->enqueueEventQueue(current_time, Event::START_EMERGENCY, *patient);
    } else {
        patient->waited_p = true;
        queue_manager->enqueuePQueue(*patient);
    }
}

/*
    Patient Starts Emergency
  - Decrement rooms
  - If patient waited_p -> calculate waiting_p
  - Enqueue depart_em event
*/
void HospitalSimulation::startEmergency(Patient* patient) {
    rooms--; 

    if (patient->waited_p) {
        patient->waiting_p = current_time - patient->arrival_emergency;
    }

    double event_time = current_time + patient->service_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_EMERGENCY, *patient);
}

/*
    Patient Departs Emergency
  - Enqueue arrive_clean event
  - Patients leaves (Add stats to stats_manager)
*/
void HospitalSimulation::departEmergency(Patient* patient) {
    queue_manager->enqueueEventQueue(current_time, Event::ARRIVE_CLEAN, *patient);
    
    int priority = (int)patient->priority;
    stats_manager->departure_count[priority]++;
    stats_manager->patient_hospital_count--;
    stats_manager->total_response_time[priority] += current_time - patient->arrival_time;
    stats_manager->total_waiting_e += patient->waiting_e;
    stats_manager->total_waiting_p[priority] += patient->waiting_p;
}

/*
    Room Avaliable to Clean
  - If janitors avaliable -> start_clean
  - Else Enqueue room to CleanQueue
*/
void HospitalSimulation::arriveClean(Patient* patient) {
    if (janitors > 0) {
        queue_manager->enqueueEventQueue(current_time, Event::START_CLEAN, *patient);
    } else {
        queue_manager->enqueueCleanQueue(*patient);
    }
}

/*
    Room Starts Cleaning
  - Decrement janitors
  - Enqueue depart_clean event
*/
void HospitalSimulation::startClean(Patient* patient) {
    janitors--; 
    double event_time = current_time+patient->clean_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_CLEAN, *patient);
}

/*
    Room Finish Cleaning
  - Increment janitors
  - Increment rooms
  - Add cleaning stats to stats_manager
  - If p waiting patient -> Enqueue start_em event
*/
void HospitalSimulation::departClean(Patient* patient) {
    janitors++;
    rooms++;

    stats_manager->total_clean_time += patient->clean_time;
    stats_manager->total_clean_count++;

    if (!queue_manager->isEmptyPQueue()) {
        Patient waiting_patient = queue_manager->dequeuePQueue();
        queue_manager->enqueueEventQueue(current_time, Event::START_EMERGENCY, waiting_patient);
    }
}

/*
    Start Simluation
  - IntializeEventQueue with stat prints
  - Get first patient and Enqueue arrive_ev event
  - While loop for simulation until 24 hours
  - Print report at 24 hours
*/
void HospitalSimulation::start() {
    queue_manager->intializeEventQueue();

    Patient patient = patient_manager->getNextPatient();
    EventNode current_event = EventNode(patient.arrival_time, Event::ARRIVE_EVALUATION, patient);
    queue_manager->enqueueEventQueue(current_event);
    
    while(current_time < closing_time){
        current_event = queue_manager->dequeueEventQueue();
        patient = current_event.patient;

        current_time = current_event.event_time;

        switch(current_event.event_type){
            case Event::PRINT_STATS:
                stats_manager->printReport(current_time);
                break;
            case Event::ARRIVE_EVALUATION:
                arriveEvaluation(&patient);
                break;
            case Event::START_EVALUATION:
                startEvaluation(&patient);
                break;
            case Event::DEPART_EVALUATION:
                departEvaluation(&patient);
                break;
            case Event::ARRIVE_EMERGENCY:
                arriveEmergency(&patient);
                break;
            case Event::START_EMERGENCY:
                startEmergency(&patient);
                break;
            case Event::DEPART_EMERGENCY:
                departEmergency(&patient);
                break;
            case Event::ARRIVE_CLEAN:
                arriveClean(&patient);
                break;
            case Event::START_CLEAN:
                startClean(&patient);
                break;
            case Event::DEPART_CLEAN:
                departClean(&patient);
                break;
        }

    }
    stats_manager->printReport(1444);
}