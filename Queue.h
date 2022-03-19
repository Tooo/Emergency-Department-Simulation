class Patient {
    public:
        double arrival_time;
        double evaluation_time;
        double service_time;
        double cleanup_time;
};

class CompareArrival {
    public:
        bool operator()(Patient & n1, Patient & n2);
};