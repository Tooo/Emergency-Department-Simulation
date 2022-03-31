# Emergency Department Simulation
Discrete event simulation of a major hospital's emergency department.
Set the lambda and mu exponential distribution rate of the patients.
Set the amount of capacity, rooms, nurses, and janitors.

## Installation
1. Download proj1.tar.gz

2. Unzip the tar.gz:
```bash
tar xvzf proj1.tar.gz
```

3. Make the executable file:
```bash
make proj1
```

## Run
```
./proj1 λ_h λ_m λ_l μ_e μ_h μ_m μ_l μ_c B R m1 m2 S
```

### Parameters
| Parameter | Description|
|:---------: | :----------|
| λ_h | Mean interarrival time of high-priority patients |
| λ_m | Mean interarrival time of medium-priority patients |
| λ_l | Mean interarrival time of low-priority patients |
| μ_e | Mean evaluation time |
| μ_h | Mean treatment time for high-priority patients |
| μ_m | Mean treatment time for medium-priority patients |
| μ_l | Mean treatment time for low-priority patients |
| μ_c | Mean cleanup time |
| B | Capacity of hospital |
| R | Rooms for emergency department |
| m1 | Triage nurses for evaluation |
| m2 | Janitors for clean up |
| S | Seed for randomizer |

## Simulation Information
### Background
You are in charge of resource management and staffing at a major metropolitan hospital's Emergency Department. 
The department has an occupancy of B total patients including R single-occupancy patient rooms and B-R patients in the waiting area.
The department runs 24 hours a day, 7 days a week. 
If the emergency department is at capacity when a new patient arrives, the arrival is turned away and transferred to a different hospital.
Patients who arrive to the emergency department are first evaluated for their condition severity and classified into three groups:
1. High-Priority: Patients with critical or life-threatening conditions 
2. Medium Priority: Adult patients with high pain levels and children with medium to high pain levels (but not life-threatening)
3. Low Priority: All other patients with medium to low pain levels for adults, and low pain levels for children

Inter-arrival times for patients in different priority groups are exponentially distributed, with a mean interarrival time.
All patients entering the emergency department need to have this initial evaluation performed. 
For this purpose, all arrivals get into a single queue to be evaluated by "m1" nurses.
This initial evaluation time is exponentially distributed  with a mean time.
After being classified into the above three groups, all patients wait in a priority queue to be assigned a room when one is freed up. 
 
Patients in the priority queue are ordered based on their priority (high-priority first then medium and then low priority). 
Within each priority group, patients are ordered based on their arrival time.

After being assigned a room, patients spend some time to be treated. 
Treatment time is exponentially distributed with a mean time.

When a patient departs from one of the patient rooms, the room needs to be cleaned by one of the hospital janitors before the patient at the head of the priority queue is admitted to it. 
The hospital employs "m2" janitors. 
Once a janitor starts cleaning the room, the cleanup time is exponentially distributed with a mean time.

### Start and End of Simulation
Simulation Starts at 12 AM and ends at 12AM the next day.

### Report Generation
A report will be generated each hour of the simulation. The report includes...
- Total number of departures
- Average number of patients in system
- Average response time for all patients, and average response time for patients of each priority group
- Average waiting time in the E queue
- Average waiting time in the P queue for all patients, and the average waiting time for patients of each priority group
- Average cleanup time for each room
- Number of patients who leave the system because it's at full capacity when they arrive.

## Implementation Information
### Classes
| Class | Description|
|:---------: | :----------|
| Main | Handles inputs for simulation |
| HospitalSimulation | Handles main simulation while loop and functions |
| PatientManager | Handles patient generation |
| QueueManager | Handles all queues |
| StatsManager | Handle report |
| Patient | Holds all patient information |
| EventNode | Holds all event information |

### Event Routine
| Event | Description|
|:---------: | :----------|
| PRINT_STATS | Print Report|
| ARRIVE_EVALUATION | Paitent arrives at hospital|
| START_EVALUATION | Triage nurse evaluates patient|
| DEPART_EVALUATION | Patient leaves evaluation |
| ARRIVE_EMERGENCY | Patient arrives at emergency room |
| START_EMERGENCY | Patient enters in emergency room |
| DEPART_EMERGENCY | Patient leaves emergency room |
| ARRIVE_CLEAN | Room needs cleaning |
| START_CLEAN | Janitor starts cleaning |
| DEPART_CLEAN | Janitor finish cleaning |

### Random Variate Generation
Patient's interarrival time and service time distributions are exponential.
Arrivals are generated based on the mean interarrival times 
minutes for the three priority groups.
Service time of the "E" queue is based on a service time distribution with mean service time 1/μ_e minutes.
Service time of the "P" queue is based on a service time distribution with mean service time minutes for the three priority groups 1/μ_c.