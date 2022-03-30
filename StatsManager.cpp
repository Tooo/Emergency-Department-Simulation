#include "StatsManager.h"
#include <iostream>
using namespace std;

StatsManager::StatsManager() {
    total_departure = 0;
    patient_hospital_count = 0;
    total_cleanup = 0;
    patient_transfered_count = 0;
    for (int i = 0; i < 3; i++) {
        waiting_e[i] = 0;
        waiting_p[i] = 0;
    }
}

void StatsManager::printPatient(Patient* patient) {
    cout << "P" << patient->id;
    cout << " Priority: " << int(patient->priority);
    cout << " Arrival: " << patient->arrival_time;
    cout << " Service: " << patient->service_time;
    cout << " Evaluation: " << patient->evaluation_time;
    cout << " Clean: " << patient->clean_time;
    cout << endl;
}

int StatsManager::getTime(string& abbr, double current_time) {
    int hour = current_time/60;
    if (hour < 12 || hour == 24) {
        if (hour == 24) {
            hour -= 12;
        }
        abbr = "AM";
    } else {
        if (hour != 12) {
            hour -= 12;
        }
        abbr = "PM";
    }
    return hour;
}

void StatsManager::printReport(double current_time) {
    string abbr;
    int hour = getTime(abbr, current_time);

    if (current_time == 1444) {
      cout << "End of ";  
    }

    cout << "Simulation at " << hour << abbr << endl;
    cout << "Number of Departures: " << total_departure << endl;
    cout << "Average number of patients in system: " << endl;
    cout << "Average response time - All: " << " H:" << " M:" << " L:" << endl;
    cout << "Average waiting time in E queue: " << endl;
    cout << "Average waiting time in P queue - All: " << " H:" << " M:" << " L:" << endl;
    cout << "Average cleanup time" << endl;
    cout << "Number of patients who leave because of full capacity: " << patient_transfered_count << endl;
    cout << endl;
}