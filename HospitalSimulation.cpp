#include "HospitalSimulation.h"

HospitalSimulation::HospitalSimulation(PatientManager patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers) {
    this->patient_manager = patient_manager;
    this->queue_manager = QueueManager();
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

}