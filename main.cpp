#include <iostream> 
using namespace std;

#include "PatientManager.h"
#include "QueueManager.h"
#include "HospitalSimulation.h"

int main (int argc, char* argv[]) {
    // ./proj1 lambda_h lambda_m lambda_l mu_e mu_h mu_m mu_l mu_c B R m1 m2 S
    if (argc < 14) {
        cout << "Insufficient number of arguments provided!" << endl;
        return 0;
    }

    // Arrival rate
    double lambda_h = atof(argv[1]); // high-priority
    double lambda_m = atof(argv[2]); // medium-priority
    double lambda_l = atof(argv[3]); // low-priority
    
    // Service rate
    double mu_e = atof(argv[4]); // initial evaluation
    double mu_h = atof(argv[5]); // high-priority
    double mu_m = atof(argv[6]); // medium-priority
    double mu_l = atof(argv[7]); // low-priority
    double mu_c = atof(argv[8]); // cleaning 
    
    if (mu_e <= 0) {
        cout << "Invalid evaluation service rate! Service rate must be greater than 0!" << endl;
        return 0;
    }

    if (lambda_h > 0 && mu_h <= 0) {
        cout << "Invalid service rate for arriving high priority patient! Service rate must be greater than 0!" << endl;
        return 0;
    }

    if (lambda_l > 0 && mu_l <= 0) {
        cout << "Invalid service rate for arriving low priority patient! Service rate must be greater than 0!" << endl;
        return 0;
    }
    if (lambda_m > 0 && mu_m <= 0) {
        cout << "Invalid service rate for arriving medium priority patient! Service rate must be greater than 0!" << endl;
        return 0;
    }
    if (mu_c <= 0) {
        cout << "Invalid cleaning service rate! Service rate must be greater than 0!" << endl;
        return 0;
    }

    // Servers
    int capacity = atoi(argv[9]); // maximum capacity
    int r_servers = atoi(argv[10]); // rooms
    int m1_servers = atoi(argv[11]); // triage nurse 
    int m2_servers = atoi(argv[12]); // janitors

    if (capacity <= 0) {
        cout << "Invalid Capacity! Capacity must be greater than 0!" << endl;
        return 0;
    }

    if (r_servers <= 0) {
        cout << "Invalid number of rooms! Number of rooms must be greater than 0!" << endl;
        return 0;
    }

    if (m1_servers <= 0) {
        cout << "Invalid number of triage nurses! Number of rooms must be greater than 0!" << endl;
        return 0;
    }

    if (m2_servers <= 0 ){
        cout << "Invalid number of janitors! Number of janitors must be greater than 0!" << endl;
        return 0;
    }

    int seed = atoi(argv[13]);
    srand(seed);

    cout << "Simulating Major Hospital Emergency Department" << endl;
    printf("Lambda_h: %f, Lambda_m: %f, Lambda_l: %f \n", lambda_h, lambda_m, lambda_l);
    printf("Mu_e: %f, Mu_h: %f, Mu_m: %f, Mu_l: %f, Mu_c: %f \n", mu_e, mu_h, mu_m, mu_l, mu_c);
    printf("B: %d, R: %d, m1: %d, m2: %d, S: %d \n", capacity, r_servers, m1_servers, m2_servers, seed);
    
    PatientManager* patient_manager = new PatientManager(lambda_h, lambda_m, lambda_l, mu_h, mu_m, mu_l, mu_e, mu_c);
    HospitalSimulation* simulation = new HospitalSimulation(patient_manager, capacity, r_servers, m1_servers, m2_servers);

    simulation->start();

    delete patient_manager;
    delete simulation;
}