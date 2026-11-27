# Experiment 2: Deadlock Handling Output

## Program 1: Deadlock Detection

### Test Case 1 - Deadlock Present

Number of Processes: 2
Number of Resources: 2

Allocation Matrix:

| Process | R0 | R1 |
|---------|----|----|
| P0 | 1 | 0 |
| P1 | 0 | 1 |

Request Matrix:

| Process | R0 | R1 |
|---------|----|----|
| P0 | 0 | 1 |
| P1 | 1 | 0 |

Available Resources: 0 0

### Expected Output

Deadlock detected!
Deadlocked Process: P0
Deadlocked Process: P1

### Test Case 2 - No Deadlock

Number of Processes: 3
Number of Resources: 2

Allocation Matrix:

| Process | R0 | R1 |
|---------|----|----|
| P0 | 1 | 0 |
| P1 | 0 | 1 |
| P2 | 1 | 1 |

Request Matrix:

| Process | R0 | R1 |
|---------|----|----|
| P0 | 0 | 1 |
| P1 | 1 | 0 |
| P2 | 0 | 0 |

Available Resources: 0 0

### Expected Output

No deadlock detected.

## Program 2: Deadlock Prevention

### Input

Number of Processes: 2
Number of Resource Types: 2
Number of Requests: 4

| Process | Resource |
|---------|----------|
| P0 | R1 |
| P1 | R2 |
| P0 | R2 |
| P1 | R1 |

### Expected Output

P0 request for R1 accepted.
P1 request for R2 accepted.
P0 request for R2 accepted.
P1 request for R1 rejected.
Resource ordering violated.
Circular wait prevented.

## Program 3: Deadlock Recovery

### Input

Number of Processes: 2
Number of Resources: 2

Allocation Matrix:

1 0
0 1

Request Matrix:

0 1
1 0

Available Resources:

0 0

### Expected Output

Deadlock detected!
Terminating process P0
Resources released.
P1 completed.
System is free from deadlock.
Available Resources: 1 1

## Comparison

| Method | Purpose |
|--------|---------|
| Detection | Identifies existing deadlocks |
| Prevention | Prevents circular wait |
| Recovery | Resolves existing deadlocks |

## Observations

- Deadlock detection identifies affected processes.
- Resource ordering prevents circular wait.
- Process termination releases allocated resources.
- Released resources allow other processes to complete.

## Result

Deadlock detection, prevention and recovery
methods were demonstrated using C++ simulations.
