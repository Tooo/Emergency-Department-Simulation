#include "HospitalSimulation.h"
#include <iostream>
using namespace std;

HospitalSimulation::HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers) {
    this->patient_manager = patient_manager;
    this->queue_manager = new QueueManager();
    this->stats_manager = new StatsManager();
    this->capacity = capacity;
    this->r_servers = r_servers;
    this->m1_servers = m1_servers;
    this->m2_servers = m2_servers;
}


/*
***** Patient Arrives for Evaluation
*/
void HospitalSimulation::arriveEvaluation(Patient* patient) {
    // Next Arrival
    Patient* next_patient = patient_manager->getNextPatient();
    double next_time = next_patient->arrival_time;
    EventNode next_arrival (next_time, Event::ARRIVE_EVALUATION, next_patient);
    queue_manager->enqueueEventQueue(next_arrival);




}

/*
***** Patient Starts Evaluation
*/
void HospitalSimulation::startEvaluation(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::DEPART_EVALUATION;

    EventNode newEvent(time, nextEvent, patient);


    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Departs Evaluation
*/
void HospitalSimulation::departEvaluation(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::ARRIVE_EMERGENCY;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Arrives for Emergency
*/
void HospitalSimulation::arriveEmergency(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::START_EMERGENCY;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Starts Emergency
*/
void HospitalSimulation::startEmergency(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::DEPART_EMERGENCY;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Departs Emergency
*/
void HospitalSimulation::departEmergency(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::START_CLEAN;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Room Starts Cleaning with Patient P waiting
*/
void HospitalSimulation::startCleaning(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::END_CLEAN;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Room finishes cleaning with Patient P waiting
*/
void HospitalSimulation::endCleaning(Patient* patient) {

    double time = 0;
    Event nextEvent = Event::END_CLEAN;

    EventNode newEvent(time, nextEvent, patient);

    queue_manager->enqueueEventQueue(newEvent);
}

void PrintPatient(Patient* patient) {
    cout << "P" << patient->id;
    cout << " Priority: " << int(patient->priority);
    cout << " Arrival: " << patient->arrival_time;
    cout << " Service: " << patient->service_time;
    cout << " Evaluation: " << patient->evaluation_time;
    cout << " Clean: " << patient->cleanup_time;
    cout << endl;
}

void HospitalSimulation::start() {
    Patient* patient = patient_manager->getNextPatient();
    EventNode current_event = EventNode(patient->arrival_time, Event::ARRIVE_EVALUATION, patient);
    queue_manager->enqueueEventQueue(current_event);
    
    while(current_time < closing_time){
        current_event = queue_manager->dequeueEventQueue();
        patient = current_event.patient;
        PrintPatient(patient);

        current_time = current_event.event_time;

        switch(current_event.event_type){
            
            case Event::ARRIVE_EVALUATION:
                arriveEvaluation(patient);
                break;
            case Event::START_EVALUATION:
                startEvaluation(patient);
                break;
            case Event::DEPART_EVALUATION:
                departEvaluation(patient);
                break;
            case Event::ARRIVE_EMERGENCY:
                arriveEmergency(patient);
                break;
            case Event::START_EMERGENCY:
                startEmergency(patient);
                break;
            case Event::DEPART_EMERGENCY:
                departEmergency(patient);
                break;
            case Event::START_CLEAN:
                startCleaning(patient);
                break;
            case Event::END_CLEAN:
                endCleaning(patient);
                break;
        }

    }
}