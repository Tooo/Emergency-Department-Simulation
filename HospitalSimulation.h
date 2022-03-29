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
        void arriveEvaluation(Patient p);
        void startEvaluation(Patient p);
        void departEvaluation(Patient p);
        void arriveEmergency(Patient p);
        void startEmergency(Patient p);
        void departEmergency(Patient p);
        void startCleaning(Patient p);
        void endCleaning(Patient p);
    public:
        HospitalSimulation(PatientManager* patient_manager, int capacity, int r_servers, int m1_servers, int m2_servers);
        void start();
};
#endif