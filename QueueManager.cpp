#include "QueueManager.h"
#include "Patient.h"
#include "EventNode.h"

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

Patient QueueManager::dequeuePQueue() {
    Patient patient;

    //check if high is not empty
    //then if med is not empty
    //then if low is not empty

    //return null if all are empty
    if (!high_queue.empty()){
        patient = high_queue.top();
        high_queue.pop();
    }
    else if (!medium_queue.empty()){
        patient = medium_queue.top();
        medium_queue.pop();
    }
    else if (!low_queue.empty()){
        patient = low_queue.top();
        low_queue.pop();
    }

    return patient;
}

//need to check for node validity?
void QueueManager::enqueueEventQueue(EventNode event_node) {
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