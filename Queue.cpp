#include <queue>
#include "Queue.h"


bool CompareArrival::operator()(Patient & n1, Patient & n2) {
    return n1.arrival_time < n2.arrival_time;
}