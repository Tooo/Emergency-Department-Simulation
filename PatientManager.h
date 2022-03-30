#include "Patient.h"

#ifndef PATIENTMANAGER_H_
#define PATIENTMANAGER_H_
class PatientManager {
    private:
        int id_count;
        double lambda_priority[3];
        double mu_priority[3];
        double last_arrival_time[3];
        double mu_evaluation;
        double mu_cleaning;

        int getNextPriority();
        double getExponentialDistribution(double value);
    public:
        PatientManager();
        PatientManager(double lambda_h, double lambda_m, double lambda_l, double mu_h, double mu_m, double mu_l, double mu_evaluation, double m_cleaning);
        Patient getNextPatient();
        
};
#endif