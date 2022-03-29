#include <queue>
#include "Patient.h"
#include "EventNode.h"

#ifndef QUEUEMANAGER_H_
#define QUEUEMANAGER_H_
class QueueManager {
    private:
        std::queue<Patient> e_queue;
        std::queue<Patient> high_queue;
        std::queue<Patient> medium_queue;
        std::queue<Patient> low_queue;
        std::queue<Patient> clean_queue;
        std::priority_queue<EventNode, std::vector<EventNode>, CompareEventNode> event_queue;

    public:
        void enqueueEQueue(Patient patient);
        Patient dequeueEQueue();

        void enqueuePQueue(Patient patient);
        Patient dequeuePQueue();

        void enqueueEventQueue(EventNode event_node);
        void enqueueEventQueue(double event_time, Event event_type, Patient* patient);
        EventNode dequeueEventQueue();

        void enqueueCleanQueue(Patient patient);
        Patient dequeueCleanQueue();
};
#endif