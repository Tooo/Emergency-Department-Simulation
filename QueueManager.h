#include <queue>
#include "Patient.h"
#include "EventNode.h"

#ifndef QUEUEMANAGER_H_
#define QUEUEMANAGER_H_
class QueueManager {
    private:
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> high_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> medium_queue;
        std::priority_queue<Patient, std::vector<Patient>, ComparePatient> low_queue;
        std::priority_queue<EventNode, std::vector<EventNode>, CompareEventNode> event_queue;

    public:
        void enqueuePQueue(Patient patient);
        Patient dequeuePQueue();

        void enqueueEventQueue(EventNode event_node);
        EventNode dequeueEventQueue();
};
#endif