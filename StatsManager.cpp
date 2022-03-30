#include "StatsManager.h"
#include <iostream>
using namespace std;

void StatsManager::PrintPatient(Patient* patient) {
    cout << "P" << patient->id;
    cout << " Priority: " << int(patient->priority);
    cout << " Arrival: " << patient->arrival_time;
    cout << " Service: " << patient->service_time;
    cout << " Evaluation: " << patient->evaluation_time;
    cout << " Clean: " << patient->clean_time;
    cout << endl;
}

void StatsManager::PrintReport(double current_time) {
    cout << current_time << endl;
}