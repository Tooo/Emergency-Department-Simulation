#include <queue>
#include "Patient.h"
#include "EventNode.h"

#ifndef QUEUEMANAGER_H_
#define QUEUEMANAGER_H_
/*
    Queue Manager
  - Holds all patient and event queues
  - Enqueue, Dequeue, and isEmpty for queues
*/
class QueueManager {
    private:
        std::queue<Patient> e_queue;
        std::queue<Patient> high_queue;
        std::queue<Patient> medium_queue;
        std::queue<Patient> low_queue;
        std::queue<Patient> clean_queue;
        std::priority_queue<EventNode, std::vector<EventNode>, CompareEventNode> event_queue;

    public:
        QueueManager();
        ~QueueManager();

        // E Queue
        void enqueueEQueue(Patient patient);
        Patient dequeueEQueue();
        bool isEmptyEQueue();

        // P Queue
        void enqueuePQueue(Patient patient);
        Patient dequeuePQueue();
        bool isEmptyPQueue();

        // Event Queue
        void intializeEventQueue();
        void enqueueEventQueue(EventNode event_node);
        void enqueueEventQueue(double event_time, Event event_type, Patient patient);
        EventNode dequeueEventQueue();

        // Clean Queue
        void enqueueCleanQueue(Patient patient);
        Patient dequeueCleanQueue();
        bool isEmptyCleanQueue();
};
#endif