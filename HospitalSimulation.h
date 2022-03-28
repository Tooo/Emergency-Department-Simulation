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
        void arriveEvaluation();
        void startEvaluation();
        void departEvaluation();
        void arriveEmergency();
        void startEmergency();
        void departEmergency();
        void startCleaning();
        void endCleaning();
    public:
        HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers);
        void start();
};
#endif