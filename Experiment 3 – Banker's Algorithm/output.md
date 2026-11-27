# Experiment 3: Banker's Algorithm Output

## Test Case 1 - Safe State

Number of Processes: 5
Number of Resources: 3

### Allocation Matrix

| Process | A | B | C |
|---------|---|---|---|
| P0 | 0 | 1 | 0 |
| P1 | 2 | 0 | 0 |
| P2 | 3 | 0 | 2 |
| P3 | 2 | 1 | 1 |
| P4 | 0 | 0 | 2 |

### Maximum Matrix

| Process | A | B | C |
|---------|---|---|---|
| P0 | 7 | 5 | 3 |
| P1 | 3 | 2 | 2 |
| P2 | 9 | 0 | 2 |
| P3 | 2 | 2 | 2 |
| P4 | 4 | 3 | 3 |

Available Resources: 3 3 2

### Need Matrix

| Process | A | B | C |
|---------|---|---|---|
| P0 | 7 | 4 | 3 |
| P1 | 1 | 2 | 2 |
| P2 | 6 | 0 | 0 |
| P3 | 0 | 1 | 1 |
| P4 | 4 | 3 | 1 |

### Expected Output

System is in a Safe State.

Safe Sequence: P1 -> P3 -> P4 -> P0 -> P2

### Resource Availability

| Completed Process | Available Resources |
|-------------------|---------------------|
| Initial | 3 3 2 |
| P1 | 5 3 2 |
| P3 | 7 4 3 |
| P4 | 7 4 5 |
| P0 | 7 5 5 |
| P2 | 10 5 7 |

## Test Case 2 - Unsafe State

Number of Processes: 2
Number of Resources: 2

### Allocation Matrix

| Process | A | B |
|---------|---|---|
| P0 | 1 | 0 |
| P1 | 0 | 1 |

### Maximum Matrix

| Process | A | B |
|---------|---|---|
| P0 | 1 | 1 |
| P1 | 1 | 1 |

Available Resources: 0 0

### Need Matrix

| Process | A | B |
|---------|---|---|
| P0 | 0 | 1 |
| P1 | 1 | 0 |

### Expected Output

System is in an Unsafe State.
No safe sequence exists.

## Observations

- Need is calculated by subtracting
  Allocation from Maximum.
- A process can complete when its remaining
  Need does not exceed available resources.
- Completed processes release their resources.
- An unsafe state does not necessarily mean
  that a deadlock has already occurred.

## Result

Banker's safety algorithm was implemented
using C++ to identify safe and unsafe states
and determine a safe sequence.
