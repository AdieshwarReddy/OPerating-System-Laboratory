# Experiment 5: Reader-Writer Problem Output

## Input Configuration

- Number of Readers: 3
- Number of Writers: 2
- Initial Shared Data: 0
- Initial Reader Count: 0
- Mutex Semaphore: 1
- Write Semaphore: 1
- Increment per Writer: 10

## Sample Output

Reader-Writer Problem
Initial Shared Data: 0
Number of Readers: 3
Number of Writers: 2

Reader 1 reads data: 0
Reader 2 reads data: 0
Reader 3 reads data: 0
Writer 1 writes data: 10
Writer 2 writes data: 20

Final Shared Data: 20
Reader-Writer Execution Completed.

## Semaphore Operations

| Semaphore | Initial Value | Purpose |
|-----------|---------------|---------|
| Mutex | 1 | Protects reader count |
| Write | 1 | Controls access to shared data |

## Access Conditions

| Operation | Status |
|-----------|--------|
| Reader and Reader | Allowed |
| Reader and Writer | Not Allowed |
| Writer and Writer | Not Allowed |
| Single Writer | Allowed |

## Final Status

| Parameter | Value |
|-----------|-------|
| Total Readers | 3 |
| Total Writers | 2 |
| Initial Shared Data | 0 |
| Final Shared Data | 20 |
| Final Reader Count | 0 |

## Observations

- Multiple readers can access shared data.
- Writers require exclusive access.
- Semaphores prevent conflicting data access.
- The first reader blocks writers.
- The last reader releases the write semaphore.
- Execution order may vary due to thread scheduling.
- Reader preference may cause writer starvation.

## Result

The Reader-Writer Problem was demonstrated
using POSIX threads and semaphores in C++.
