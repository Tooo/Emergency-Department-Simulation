#ifndef PATIENT_H
#define PATIENT_H
enum class Priority {HIGH, MEDIUM, LOW};

class Patient {
    public:
        Patient();
        Patient(int id, double arrival_time, double evaluation_time, double service_time, double clean_time, Priority priority); 
        int id;
        double arrival_time;
        double evaluation_time;
        double service_time;
        double clean_time;
        Priority priority;
};

class ComparePatient {
    public:
        bool operator()(Patient & n1, Patient & n2);
};
#endif