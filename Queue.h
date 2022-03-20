#include <queue>

enum class Priority {HIGH, MEDIUM, LOW};

class Patient {
    public:
        double arrival_time;
        double evaluation_time;
        double service_time;
        double cleanup_time;
        Priority priority;
};

class CompareArrival {
    public:
        bool operator()(Patient & n1, Patient & n2);
};

class QueueManager {
    private:
        std::priority_queue<Patient, std::vector<Patient>, CompareArrival> e_queue;
        std::priority_queue<Patient, std::vector<Patient>, CompareArrival> high_queue;
        std::priority_queue<Patient, std::vector<Patient>, CompareArrival> medium_queue;
        std::priority_queue<Patient, std::vector<Patient>, CompareArrival> low_queue;
    public:
        void intializeEQueue();
        void enqueueEQueue(Patient patient);
        void enqueuePQueue(Patient patient);
        Patient dequeueEQueue();
        Patient dequeuePQueue();
};