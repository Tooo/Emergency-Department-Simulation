#include "Patient.h"
#include <string>
using namespace std;


#ifndef STATSMANAGER_H_
#define STATSMANAGER_H_
class StatsManager {
    private: 
        int getTime(string& abbr, double current_time);
    public:
        int departure_count[3];
        int patient_hospital_count;
        double total_response_time[3];
        double total_waiting_e;
        double total_waiting_p[3];
        double total_clean_time;
        int patient_transfered_count;
        int total_clean_count;

        StatsManager();
        void printPatient(Patient* patient);
        void printReport(double current_time);

};
#endif