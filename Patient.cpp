#include "Patient.h"

Patient::Patient() {
    
}

Patient::Patient(int id, Priority priority, double arrival_time, double evaluation_time, double service_time, double clean_time) {
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