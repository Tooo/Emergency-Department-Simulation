#include "PatientManager.h"
#include "QueueManager.h"

#ifndef HOSPITALSIMULATION_H_
#define HOSPITALSIMULATION_H_
class HospitalSimulation {
    private:
        PatientManager* patient_manager;
        QueueManager*  queue_manager;
        int capacity;
        int r_servers;
        int m1_servers;
        int m2_servers;
        double current_time = 0;
        double closing_time = 1440; //24hrs is 1440min

        void arriveEvaluation(Patient* patient);
        void startEvaluation(Patient* patient);
        void departEvaluation(Patient* patient);
        void arriveEmergency(Patient* patient);
        void startEmergency(Patient* patient);
        void departEmergency(Patient* patient);
        void startCleaning(Patient* patient);
        void endCleaning(Patient* patient);
    public:
        HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers);
        void start();
};
#endif