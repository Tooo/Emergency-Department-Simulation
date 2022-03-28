#include <queue>
#include <Patient.h>
#include <EventNode.h>

class QueueManager {
    private:
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> high_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> medium_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> low_queue;
        std::priority_queue<EventNode, std::vector<EventNode>, CompareEventNode> event_queue;

        double lambda_l;
        double lambda_m;
        double lambda_h;

        double mu_l;
        double mu_m;
        double mu_h;

    public:
        void enqueuePQueue(Patient patient);
        Patient dequeuePQueue();

        void enqueueEventQueue(EventNode event_node);
        EventNode dequeueEventQueue();
};