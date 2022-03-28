#include "PatientManager.h"
#include <random>

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

int PatientManager::getNextPriority() {
    int min = 0;
    int min_index = 0;

    for (int i = 1; i < 2; i++) {
        if (this->last_arrival_time[i] < min) {
            min = last_arrival_time[i];
            min_index = i;
        }
    }
    return min_index;
}

double PatientManager::getExponentialDistribution(double time) {
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1-u) / time);
}

Patient PatientManager::getNextPatient() {
    int priority = getNextPriority();

} 