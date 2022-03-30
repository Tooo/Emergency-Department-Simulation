#include "Patient.h"

#ifndef STATSMANAGER_H_
#define STATSMANAGER_H_
class StatsManager {
    public:
        int total_departure;
        int patient_hospital_count;
        int patient_transfered_count;

        void PrintPatient(Patient* patient);
        void PrintReport(double current_time);

};
#endif