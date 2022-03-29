#include "HospitalSimulation.h"
#include <iostream>

using namespace std;

double current_time = 0;
double closing_time = 1440; //24hrs is 1440min

HospitalSimulation::HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers) {
    this->patient_manager = patient_manager;
    this->queue_manager = new QueueManager();
    this->capacity = capacity;
    this->r_servers = r_servers;
    this->m1_servers = m1_servers;
    this->m2_servers = m2_servers;
}


/*
***** Patient Arrives for Evaluation
*/
void HospitalSimulation::arriveEvaluation(Patient p) {

    double time;
    Event nextEvent = Event::START_EVALUATION;

    EventNode newEvent(time, nextEvent, p);
    
    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Starts Evaluation
*/
void HospitalSimulation::startEvaluation(Patient p) {

    double time;
    Event nextEvent = Event::DEPART_EVALUATION;

    EventNode newEvent(time, nextEvent, p);

    EventNode newEvent();

    queue_manager->enqueueEventQueue(newEvent);
}

/*
***** Patient Departs Evaluation
*/
void HospitalSimulation::departEvaluation(Patient p) {

    double time;
    Event nextEvent = Event::ARRIVE_EMERGENCY;

    EventNode newEvent(time, nextEvent, p);

    EventNode newEvent();

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::arriveEmergency(Patient p) {

    double time;
    Event nextEvent = Event::START_EMERGENCY;

    EventNode newEvent(time, nextEvent, p);

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::startEmergency(Patient p) {

    double time;
    Event nextEvent = Event::DEPART_EMERGENCY;

    EventNode newEvent(time, nextEvent, p);

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::departEmergency(Patient p) {

    double time;
    Event nextEvent = Event::START_CLEAN;

    EventNode newEvent(time, nextEvent, p);

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::startCleaning(Patient p) {

    double time;
    Event nextEvent = Event::END_CLEAN;

    EventNode newEvent(time, nextEvent, p);

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::endCleaning(Patient p) {

    double time;
    Event nextEvent = Event::END_CLEAN;

    EventNode newEvent(time, nextEvent, p);

    queue_manager->enqueueEventQueue(newEvent);
}

void HospitalSimulation::start() {

    for (int i = 0; i < 10; i++) {
        Patient patient = patient_manager->getNextPatient();
        cout << "P" << i;
        cout << " Priority: " << int(patient.priority);
        cout << " Arrival: " << patient.arrival_time;
        cout << " Service: " << patient.service_time;
        cout << " Evaluation: " << patient.evaluation_time;
        cout << " Clean: " << patient.cleanup_time;
        cout << endl;
    }
    
    while(current_time < closing_time){
        EventNode current_event = queue_manager->dequeueEventQueue();
        Patient p = current_event.patient;

        current_time = current_event.event_time;
        
        switch(current_event.event_type){
            
            case Event::ARRIVE_EVALUATION:
                arriveEvaluation(p);
            case Event::START_EVALUATION:
                startEvaluation(p);
            case Event::DEPART_EVALUATION:
                departEvaluation(p);
            case Event::ARRIVE_EMERGENCY:
                arriveEmergency(p);
            case Event::START_EMERGENCY:
                startEmergency(p);
            case Event::DEPART_EMERGENCY:
                departEmergency(p);
            case Event::START_CLEAN:
                startCleaning(p);
            case Event::END_CLEAN:
                endCleaning(p);
        }

    }
}