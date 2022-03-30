#include "HospitalSimulation.h"

HospitalSimulation::HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers) {
    this->patient_manager = patient_manager;
    this->queue_manager = new QueueManager();
    this->stats_manager = new StatsManager();
    this->capacity = capacity;
    this->r_servers = r_servers;
    this->m1_servers = m1_servers;
    this->m2_servers = m2_servers;
    current_time = 0;
    closing_time = 1440; //24hrs is 1440min
}


/*
    Patient Arrives for Evaluation
  - Enqueue next arrival
  - If Hospital full -> transfer patient 
  - If e_rooms avaliable -> Enqueue start_e event 
  - Else Enqueue EQueue
*/
void HospitalSimulation::arriveEvaluation(Patient* patient) {
    stats_manager->PrintPatient(patient);
    // Next Arrival
    Patient next_patient = patient_manager->getNextPatient();
    double next_time = next_patient.arrival_time;
    queue_manager->enqueueEventQueue(next_time, Event::ARRIVE_EVALUATION, next_patient);

    if (stats_manager->patient_hospital_count < capacity) {
        if (m1_servers > 0) {
            double event_time = current_time;
            queue_manager->enqueueEventQueue(event_time, Event::START_EVALUATION, *patient);
        } else {
            queue_manager->enqueueEQueue(*patient);
        }

    } else {
        stats_manager->patient_transfered_count++;
        delete patient;
    }
}

/*
    Patient Starts Evaluation
  - Decrement e_room
  - Enqueue depart_e event
*/
void HospitalSimulation::startEvaluation(Patient* patient) {
    m1_servers--;
    double event_time = current_time+patient->evaluation_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_EVALUATION, *patient);
}

/*
    Patient Departs Evaluation
  - Increment e_room
  - Enqueue arrive_em
  - If e waiting patient -> enqueue e_start
*/
void HospitalSimulation::departEvaluation(Patient* patient) {
    m1_servers++;

    queue_manager->enqueueEventQueue(current_time, Event::ARRIVE_EMERGENCY, *patient);

    if (!queue_manager->isEmptyEQueue()) {
        Patient waiting_patient = queue_manager->dequeueEQueue();
        queue_manager->enqueueEventQueue(current_time, Event::START_EVALUATION, waiting_patient);
    }
}

/*
    Patient Arrives for Emergency
  - If room avaliable -> em_start
  - Else enqueue PQueue
*/
void HospitalSimulation::arriveEmergency(Patient* patient) {
    if (r_servers > 0) {
        queue_manager->enqueueEventQueue(current_time, Event::START_EMERGENCY, *patient);
    } else {
        queue_manager->enqueuePQueue(*patient);
    }
}

/*
    Patient Starts Emergency
  - Decrement em_rooms
  - Enqueue depart_em event
*/
void HospitalSimulation::startEmergency(Patient* patient) {
    r_servers--; 
    double event_time = current_time+patient->service_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_EMERGENCY, *patient);
}

/*
    Patient Departs Emergency
  - Increment em_rooms
  - Enqueue arrive_clean
  - If p waiting patient -> enqueue e_start
*/
void HospitalSimulation::departEmergency(Patient* patient) {
    r_servers++;
    queue_manager->enqueueEventQueue(current_time, Event::ARRIVE_CLEAN, *patient);

    if (!queue_manager->isEmptyPQueue()) {
        Patient waiting_patient = queue_manager->dequeuePQueue();
        queue_manager->enqueueEventQueue(current_time, Event::START_EMERGENCY, waiting_patient);
    }
}

/*
    Room Avaliable to Clean
  - If room avaliable -> clean_start
  - Else enqueue CleanQueue
*/
void HospitalSimulation::arriveClean(Patient* patient) {
    if (m2_servers > 0) {
        queue_manager->enqueueEventQueue(current_time, Event::START_CLEAN, *patient);
    } else {
        queue_manager->enqueueCleanQueue(*patient);
    }
}


/*
    Room Starts Cleaning
  - Decrement m2_rooms
  - Enqueue depart_clean event
*/
void HospitalSimulation::startClean(Patient* patient) {
    m2_servers--; 
    double event_time = current_time+patient->clean_time;
    queue_manager->enqueueEventQueue(event_time, Event::DEPART_CLEAN, *patient);
}

/*
    Room Finish Cleaning
  - Increment em_rooms
  - Patient leaves
*/
void HospitalSimulation::departClean(Patient* patient) {
    m2_servers++;
}

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
                stats_manager->PrintReport(current_time);
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
}