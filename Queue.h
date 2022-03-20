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

class ComparePatient {
    public:
        bool operator()(Patient & n1, Patient & n2);
};

enum class Event {ARRIVE_EVALUATION, START_EVALUATION, DEPART_EVALUATION, 
                  ARRIVE_EMERGENCY, START_EMERGENCY, DEPART_EMERGENCY,
                  START_CLEAN, END_CLEAN};

class EventNode {
    public:
        double event_time;
        Event event_type;
        Patient patient;
};

class CompareEventNode {
    public:
        bool operator()(EventNode & n1, EventNode & n2);
};

class QueueManager {
    private:
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> e_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> high_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> medium_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> low_queue;
        std::priority_queue<EventNode, std::vector<EventNode>, CompareEventNode> event_queue;
    public:
        void intializeEQueue();
        void enqueueEQueue(Patient patient);
        Patient dequeueEQueue();

        void enqueuePQueue(Patient patient);
        Patient dequeuePQueue();

        void enqueueEventQueue(EventNode event_node);
        EventNode dequeueEventQueue();
};