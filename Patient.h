#ifndef PATIENT_H
#define PATIENT_H
/*
    Priority
  - Enum class for Patient priority
*/
enum class Priority {HIGH, MEDIUM, LOW};

/*
    Patient
  - Holds all information for patient
*/
class Patient {
    public:
        Patient();
        Patient(int id, Priority priority, double arrival_time, double evaluation_time, double service_time, double clean_time); 
        
        int id;
        Priority priority;
        double arrival_time;
        double evaluation_time;
        double service_time;
        double clean_time;

        double arrival_emergency;
        double leave_time;

        double waiting_e;
        double waiting_p;
        bool waited_e;
        bool waited_p;
};
#endif