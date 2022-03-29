#include "Patient.h"

Patient::Patient() {
    
}

Patient::Patient(int id, double arrival_time, double evaluation_time, double service_time, double cleanup_time, Priority priority) {
    this->id = id;
    this->arrival_time = arrival_time;
    this->evaluation_time = evaluation_time;
    this->service_time = service_time;
    this->cleanup_time = cleanup_time;
    this->priority = priority;
}

bool ComparePatient::operator()(Patient & n1, Patient & n2) {
    return n1.arrival_time < n2.arrival_time;
}