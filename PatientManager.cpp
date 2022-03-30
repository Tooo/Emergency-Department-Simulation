#include "PatientManager.h"
#include <random>

PatientManager::PatientManager() {

}

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

    for (int i = 0; i < 3; i++) {
        if (lambda_priority[i] == 0) {
            this->last_arrival_time[i] = MAXFLOAT;
        } else {
            this->last_arrival_time[i] = getExponentialDistribution(lambda_priority[i]);
        }
        
    }
}

int PatientManager::getNextPriority() {
    double min = last_arrival_time[0];
    int min_index = 0;

    for (int i = 1; i < 3; i++) {
        if (this->last_arrival_time[i] < min) {
            min = last_arrival_time[i];
            min_index = i;
        }
    }
    return min_index;
}

double PatientManager::getExponentialDistribution(double value) {
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1-u) / value);
}

Patient PatientManager::getNextPatient() {
    int priority = getNextPriority();
    int id = id_count++;
    double arrival_time = last_arrival_time[priority];
    last_arrival_time[priority] = arrival_time + getExponentialDistribution(this->lambda_priority[priority]);
    double service_time = getExponentialDistribution(this->mu_priority[priority]);
    double evaluation_time = getExponentialDistribution(this->mu_evaluation);
    double clean_time = getExponentialDistribution(this->mu_cleaning);
    return Patient(id, arrival_time, evaluation_time, service_time, clean_time, (Priority)priority);
} 