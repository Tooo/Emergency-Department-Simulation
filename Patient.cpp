#include "Patient.h"

Patient::Patient() {
    
}

Patient::Patient(int id, double arrival_time, double evaluation_time, double service_time, double clean_time, Priority priority) {
    this->id = id;
    this->priority = priority;
    this->arrival_time = arrival_time;
    this->evaluation_time = evaluation_time;
    this->service_time = service_time;
    this->clean_time = clean_time;
    waiting_e = 0;
    waiting_p = 0;
    waited_e = false;
    waited_p = false;
}

bool ComparePatient::operator()(Patient & n1, Patient & n2) {
    return n1.arrival_time < n2.arrival_time;
}