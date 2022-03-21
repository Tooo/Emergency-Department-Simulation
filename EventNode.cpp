#include "EventNode.h"

bool CompareEventNode::operator()(EventNode & n1, EventNode & n2) {
    return n1.event_time < n2.event_time;
}