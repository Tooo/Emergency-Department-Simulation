#include "QueueManager.h"
#include "Patient.h"
#include "EventNode.h"

QueueManager::~QueueManager() {
    e_queue = {};
    high_queue = {};
    medium_queue = {};
    low_queue = {};
    clean_queue = {};
    event_queue = {};
}

// EQueues functions
void QueueManager::enqueueEQueue(Patient patient) {
    e_queue.push(patient);
}

Patient QueueManager::dequeueEQueue() {
    Patient patient = e_queue.front();
    e_queue.pop();
    return patient;
}

bool QueueManager::isEmptyEQueue() {
    return e_queue.empty();
}

// PQueues functions
/*
    Enqueue PQueue
  - Queue patient based on priority
*/
void QueueManager::enqueuePQueue(Patient patient) {
    switch (patient.priority) {
        case Priority::HIGH:
            high_queue.push(patient);
            break;
        case Priority::MEDIUM:
            medium_queue.push(patient);
            break;
        case Priority::LOW:
            low_queue.push(patient);
            break;
    }
}

/*
    Dequeue PQueue
  - Dequeue higher priority first
  - If higher priority are empty, dequeue lower ones
  - High > Medium > Low
*/
Patient QueueManager::dequeuePQueue() {
    Patient patient;

    if (!high_queue.empty()){
        patient = high_queue.front();
        high_queue.pop();
    }
    else if (!medium_queue.empty()){
        patient = medium_queue.front();
        medium_queue.pop();
    }
    else if (!low_queue.empty()){
        patient = low_queue.front();
        low_queue.pop();
    }

    return patient;
}

bool QueueManager::isEmptyPQueue() {
    return (low_queue.empty() && medium_queue.empty() && high_queue.empty());
}

// Event Queues functions
/*
    Intialize Event Queue
  - Create print events for each hour
*/
void QueueManager::intializeEventQueue() {
    for (int i = 60; i < 1440; i+= 60) {
        enqueueEventQueue(i, Event::PRINT_STATS, Patient());
    }
}

void QueueManager::enqueueEventQueue(EventNode event_node) {
    event_queue.push(event_node);
}

void QueueManager::enqueueEventQueue(double event_time, Event event_type, Patient patient) {
    EventNode event_node(event_time, event_type, patient);
    event_queue.push(event_node);
}

EventNode QueueManager::dequeueEventQueue() {
    EventNode event;
    if(!event_queue.empty()){
        event = event_queue.top();
        event_queue.pop();
    }
    return event;
}

// Clean Queue Functions
void QueueManager::enqueueCleanQueue(Patient patient) {
    clean_queue.push(patient);
}

Patient QueueManager::dequeueCleanQueue() {
    Patient patient = clean_queue.front();
    e_queue.pop();
    return patient;
}