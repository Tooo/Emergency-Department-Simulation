#include "Patient.h"

class PatientManager {
    private:
        double lambda_priority[3];
        double mu_priority[3];
        double last_arrival_time[3];
        double mu_evaluation;
        double mu_cleaning;

        int getNextPriority();
        double getExponentialDistribution(double time);
    public:
        PatientManager(double lambda_h, double lambda_m, double lambda_l, double mu_h, double mu_m, double mu_l, double mu_evaluation, double m_cleaning);
        Patient getNextPatient();
        
};