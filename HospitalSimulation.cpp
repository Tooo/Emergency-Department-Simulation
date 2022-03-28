#include "HospitalSimulation.h"
#include <iostream>
using namespace std;

HospitalSimulation::HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers) {
    this->patient_manager = patient_manager;
    this->queue_manager = new QueueManager();
    this->capacity = capacity;
    this->r_servers = r_servers;
    this->m1_servers = m1_servers;
    this->m2_servers = m2_servers;
}

void HospitalSimulation::arriveEvaluation() {

}

void HospitalSimulation::startEvaluation() {

}

void HospitalSimulation::departEvaluation() {

}

void HospitalSimulation::arriveEmergency() {

}

void HospitalSimulation::startEmergency() {

}

void HospitalSimulation::departEmergency() {

}

void HospitalSimulation::startCleaning() {

}

void HospitalSimulation::endCleaning() {

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
}