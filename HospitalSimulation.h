
class HospitalSimulation {
    private:
        void arriveEvaluation();
        void startEvaluation();
        void departEvaluation();
        void arriveEmergency();
        void startEmergency();
        void departEmergency();
        void startCleaning();
        void endCleaning();
    public:
        void startSimulation();
};