# Experiment 4: Producer-Consumer Output

## Input Configuration

- Buffer Size: 5
- Total Items: 10
- Initial Empty Semaphore: 5
- Initial Full Semaphore: 0
- Initial Mutex Semaphore: 1

## Sample Output

Producer-Consumer Problem
Buffer Size: 5
Total Items: 10

Producer produced: 1
Consumer consumed: 1
Producer produced: 2
Consumer consumed: 2
Producer produced: 3
Consumer consumed: 3
Producer produced: 4
Producer produced: 5
Consumer consumed: 4
Producer produced: 6
Consumer consumed: 5
Producer produced: 7
Producer produced: 8
Consumer consumed: 6
Producer produced: 9
Consumer consumed: 7
Producer produced: 10
Consumer consumed: 8
Consumer consumed: 9
Consumer consumed: 10

Production and Consumption Completed.

## Semaphore Operations

| Semaphore | Initial Value | Purpose |
|-----------|---------------|---------|
| Empty | 5 | Counts empty buffer slots |
| Full | 0 | Counts occupied buffer slots |
| Mutex | 1 | Ensures mutual exclusion |

## Final Status

| Parameter | Value |
|-----------|-------|
| Total Items Produced | 10 |
| Total Items Consumed | 10 |
| Remaining Items | 0 |
| Empty Slots | 5 |
| Buffer Overflow | Prevented |
| Buffer Underflow | Prevented |

## Observations

- The producer waits when the buffer is full.
- The consumer waits when the buffer is empty.
- The mutex prevents simultaneous buffer access.
- Semaphores provide proper synchronization.
- The circular buffer efficiently reuses slots.
- Output ordering may vary due to thread scheduling.

## Result

The Producer-Consumer Problem was demonstrated
using POSIX threads and semaphores in C++.
