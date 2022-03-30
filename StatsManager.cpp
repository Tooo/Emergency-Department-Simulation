#include "StatsManager.h"
#include <iostream>
using namespace std;

StatsManager::StatsManager() {
    patient_hospital_count = 0;
    total_waiting_e = 0;
    total_clean_time = 0;
    patient_transfered_count = 0;
    for (int i = 0; i < 3; i++) {
        departure_count[i] = 0;
        total_response_time[i] = 0;
        total_waiting_p[i] = 0;
    }
    total_clean_count = 0;
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
    
    int departure_count_all = 0;
    double total_response_all = 0;
    double total_waiting_p_all = 0;

    double avg_response_times[3];

    for (int i = 0; i < 3; i++) {
        departure_count_all += departure_count[i];
        total_response_all += total_response_time[i];
        total_waiting_p_all += total_waiting_p[i];
        avg_response_times[i] = total_response_time[i]/departure_count[i];
    } 

    cout << "Simulation at " << hour << abbr << endl;
    cout << "Number of Departures: " << departure_count_all << endl;
    cout << "Average number of patients in system: "<< total_response_all/current_time << endl;
    
    cout << "Average response time - All: ";
    if (departure_count_all == 0) {
        cout << "N/A";
    } else {
        cout << total_response_all/departure_count_all;
    }

    char letter[3] = {'H', 'M', 'L'};
    for (int i = 0; i < 3; i++) {
        printf(" %c: ", letter[i]);
        if (departure_count[i] == 0) {
            cout << "N/A";
        } else {
            cout << avg_response_times[i];
        }
    }
    cout << endl;

    cout << "Average waiting time in E queue: ";
    if (departure_count_all == 0) {
        cout << "N/A" << endl;
    } else {
        cout << total_waiting_e/departure_count_all << endl;
    }

    cout << "Average waiting time in P queue - All: ";
    if (departure_count_all == 0) {
        cout << "N/A";
    } else {
        cout << total_waiting_p_all/departure_count_all;
    }

    for (int i = 0; i < 3; i++) {
        printf(" %c: ", letter[i]);
        if (departure_count[i] == 0) {
            cout << "N/A";
        } else {
            cout << total_waiting_p[i]/departure_count[i];
        }
    }
    cout << endl;
    cout << "Average cleanup time: " << total_clean_time / total_clean_count << endl;
    cout << "Number of patients who leave because of full capacity: " << patient_transfered_count << endl;
    cout << endl;
}