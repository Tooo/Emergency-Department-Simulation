#include <iostream> 
using namespace std;

int main (int argc, char* argv[]) {

    // ./proj1 lambda_h lambda_m lambda_l mu_e mu_h mu_m mu_l mu_c B R m1 m2 S
    if (argc < 14) {
        cout << "Insufficient number of arguments provided!" << endl;
        return 0;
    }

    double lambda_h = atof(argv[1]);
    double lambda_m = atof(argv[2]);
    double lambda_l = atof(argv[3]);
    
    double mu_e = atof(argv[4]);
    double mu_h = atof(argv[5]);
    double mu_m = atof(argv[6]);
    double mu_l = atof(argv[7]);
    double mu_c = atof(argv[8]);

    int capacity = atoi(argv[9]);
    int r_servers = atoi(argv[10]);
    int m1_servers = atoi(argv[11]);
    int m2_servers = atoi(argv[12]);

    int seed = atoi(argv[13]);


}