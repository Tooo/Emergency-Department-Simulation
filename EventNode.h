#include "Patient.h"

enum class Event {ARRIVE_EVALUATION, START_EVALUATION, DEPART_EVALUATION, 
                  ARRIVE_EMERGENCY, START_EMERGENCY, DEPART_EMERGENCY,
                  START_CLEAN, END_CLEAN};

class EventNode {
    public:
        double event_time;
        Event event_type;
        Patient patient;
};

class CompareEventNode {
    public:
        bool operator()(EventNode & n1, EventNode & n2);
};