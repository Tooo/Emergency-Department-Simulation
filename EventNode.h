#include "Patient.h"

#ifndef EVENTNODE_H_
#define EVENTNODE_H_
enum class Event {  PRINT_STATS,
                    ARRIVE_EVALUATION, 
                    START_EVALUATION, 
                    DEPART_EVALUATION, 
                    ARRIVE_EMERGENCY, 
                    START_EMERGENCY, 
                    DEPART_EMERGENCY,
                    ARRIVE_CLEAN, 
                    START_CLEAN,
                    DEPART_CLEAN};

class EventNode {
    public:
        EventNode();
        EventNode(double event_time, Event event_type, Patient* patient);
        double event_time;
        Event event_type;
        Patient* patient;
};

class CompareEventNode {
    public:
        bool operator()(EventNode & n1, EventNode & n2);
};
#endif