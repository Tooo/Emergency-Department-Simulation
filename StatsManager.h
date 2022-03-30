#include "Patient.h"
#include <string>
using namespace std;


#ifndef STATSMANAGER_H_
#define STATSMANAGER_H_
class StatsManager {
    private: 
        int getTime(string& abbr, double current_time);
    public:
        int total_departure;
        int patient_hospital_count;
        int patient_transfered_count;

        void printPatient(Patient* patient);
        void printReport(double current_time);

};
#endif