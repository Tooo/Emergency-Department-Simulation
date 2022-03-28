#include "Patient.h"

Patient::Patient() {
    
}

Patient::Patient(double arrival_time, double evaluation_time, double service_time, double cleanup_time, Priority priority) {
    this->arrival_time = arrival_time;
    this->evaluation_time = evaluation_time;
    this->service_time = service_time;
    this->cleanup_time = service_time;
    this->priority = priority;
}

bool ComparePatient::operator()(Patient & n1, Patient & n2) {
    return n1.arrival_time < n2.arrival_time;
}