#include "QueueManager.h"

void QueueManager::intializeEQueue(double lambda_l, double lambda_m, double lambda_h, double mu_l, double mu_m, double mu_h) {

    this->lambda_l = lambda_l;
    this->lambda_m = lambda_m;
    this->lambda_h = lambda_h;

    this->mu_l = mu_l;
    this->mu_m = mu_m;
    this->mu_h = mu_h;
}

void QueueManager::enqueueEQueue(Patient patient) {
    e_queue.push(patient);
}

Patient QueueManager::dequeueEQueue() {
    Patient p =  e_queue.top();
    e_queue.pop();
    return p;
}

void QueueManager::enqueuePQueue(Patient patient) {

    switch(patient.priority){

        case Priority::HIGH:
            high_queue.push(patient);
        
        case Priority::MEDIUM:
            medium_queue.push(patient);

        case Priority::LOW:
            low_queue.push(patient);

    }
}

Patient QueueManager::dequeuePQueue() {
    Patient op;

    //check if high is not empty
    //then if med is not empty
    //then if low is not empty

    //return null if all are empty
    if(!high_queue.empty()){
        op = high_queue.top();
        high_queue.pop();
    }
    else if(!medium_queue.empty()){
        op = medium_queue.top();
        medium_queue.pop();
    }
    else if(!low_queue.empty()){
        op = low_queue.top();
        low_queue.pop();
    }

    return op;
}

//need to check for node validity?
void QueueManager::enqueueEventQueue(EventNode event_node) {
    event_queue.push(event_node);
    
}

EventNode QueueManager::dequeueEventQueue() {

    EventNode op;
    if(!event_queue.empty()){
        op = event_queue.top();
        event_queue.pop();
    }
    return op;
}