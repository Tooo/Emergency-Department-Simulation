#include "EventNode.h"

EventNode::EventNode() {
    
}

EventNode::EventNode(double event_time, Event event_type, Patient patient) {
    this->event_time = event_time;
    this->event_type = event_type;
    this->patient = patient;
}

bool CompareEventNode::operator()(EventNode & n1, EventNode & n2) {
    return n1.event_time > n2.event_time;
}