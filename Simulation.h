#include <Queue.h>

class HospitalSimulation {
    private:
        void arriveEvaluation();
        void startEvaluation();
        void departEvaluation();
        void arriveEmergency();
        void startEmergency();
        void departEmergency();
    public:
        void startSimulation();
};