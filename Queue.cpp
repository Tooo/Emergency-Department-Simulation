#include <queue>
#include "Queue.h"


bool ComparePatient::operator()(Patient & n1, Patient & n2) {
    return n1.arrival_time < n2.arrival_time;
}

bool CompareEventNode::operator()(EventNode & n1, EventNode & n2) {
    return n1.event_time < n2.event_time;
}