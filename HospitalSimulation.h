#include "PatientManager.h"
#include "QueueManager.h"
#include "StatsManager.h"

#ifndef HOSPITALSIMULATION_H_
#define HOSPITALSIMULATION_H_
class HospitalSimulation {
    private:
        PatientManager* patient_manager;
        QueueManager*  queue_manager;
        StatsManager* stats_manager;

        int capacity;
        int rooms;
        int triage_nurses;
        int janitors;
        double current_time;
        double closing_time;

        void arriveEvaluation(Patient* patient);
        void startEvaluation(Patient* patient);
        void departEvaluation(Patient* patient);
        void arriveEmergency(Patient* patient);
        void startEmergency(Patient* patient);
        void departEmergency(Patient* patient);
        void arriveClean(Patient* patient);
        void startClean(Patient* patient);
        void departClean(Patient* patient);
    public:
        HospitalSimulation(PatientManager* patient_manager, int capacity, int rooms, int triage_nurses, int janitors);
        ~HospitalSimulation();
        void start();
};
#endif