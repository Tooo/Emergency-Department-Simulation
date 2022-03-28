#include "PatientManager.h"

PatientManager::PatientManager(double lambda_h, double lambda_m, double lambda_l, 
                               double mu_h, double mu_m, double mu_l, 
                               double mu_evaluation, double mu_cleaning) {
    this->lambda_priority[0] = lambda_h;
    this->lambda_priority[1] = lambda_m;
    this->lambda_priority[2] = lambda_l;

    this->mu_priority[0] = mu_h;
    this->mu_priority[1] = mu_m;
    this->mu_priority[2] = mu_l;

    this->mu_evaluation = mu_evaluation;
    this->mu_cleaning = mu_cleaning;

}

Patient PatientManager::getNextPatient() {
    
} 