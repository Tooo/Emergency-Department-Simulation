#include "Patient.h"

#ifndef EVENTNODE_H_
#define EVENTNODE_H_
/*
    Event
  - Enum class for each type of event
*/
enum class Event {  PRINT_STATS,
                    ARRIVE_EVALUATION, 
                    START_EVALUATION, 
                    DEPART_EVALUATION, 
                    ARRIVE_EMERGENCY, 
                    START_EMERGENCY, 
                    DEPART_EMERGENCY,
                    ARRIVE_CLEAN, 
                    START_CLEAN,
                    DEPART_CLEAN
};

/*
    Event Node
  - Event queue node to hold each event
*/
class EventNode {
    public:
        EventNode();
        EventNode(double event_time, Event event_type, Patient patient);
        double event_time;
        Event event_type;
        Patient patient;
};

/*
    Compare Event Node
  - Used to compare 2 event nodes for priority queue
*/
class CompareEventNode {
    public:
        bool operator()(EventNode & n1, EventNode & n2);
};
#endif