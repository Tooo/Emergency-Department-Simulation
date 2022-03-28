enum class Priority {HIGH, MEDIUM, LOW};

class Patient {
    public:
        Patient();
        Patient(double arrival_time, double evaluation_time, double service_time, double cleanup_time, Priority priority); 
        double arrival_time;
        double evaluation_time;
        double service_time;
        double cleanup_time;
        Priority priority;
};

class ComparePatient {
    public:
        bool operator()(Patient & n1, Patient & n2);
};