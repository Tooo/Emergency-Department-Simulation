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
        
        double waiting_e[3];
        double waiting_p[3];
        double total_cleanup;
        int patient_transfered_count;

        StatsManager();
        void printPatient(Patient* patient);
        void printReport(double current_time);

};
#endif