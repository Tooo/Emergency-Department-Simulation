#include <iostream> 
using namespace std;

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

    // Servers
    int capacity = atoi(argv[9]); // maximum capacity
    int r_servers = atoi(argv[10]); // rooms
    int m1_servers = atoi(argv[11]); // triage nurse 
    int m2_servers = atoi(argv[12]); // janitors

    int seed = atoi(argv[13]);


}