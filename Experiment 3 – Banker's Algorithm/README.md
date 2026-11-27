# Experiment 3: Banker's Algorithm

## Aim
To implement Banker's Algorithm using C++ to
avoid deadlock and determine the safe sequence
of processes.

## Theory
Banker's Algorithm is a deadlock avoidance
algorithm that checks whether resource
allocation leaves the system in a safe state.

## Important Terms

- Allocation: Resources currently allocated
  to each process.
- Max: Maximum resources required by each process.
- Available: Resources currently available.
- Need: Remaining resources required by each process.
- Safe State: A state in which all processes
  can complete in some order.
- Unsafe State: A state in which a safe sequence
  cannot be guaranteed.

## Formula

Need[i][j] = Max[i][j] - Allocation[i][j]

## Algorithm

1. Read the number of processes and resources.
2. Read the Allocation Matrix.
3. Read the Maximum Matrix.
4. Read the Available Resources.
5. Calculate the Need Matrix.
6. Find an unfinished process whose Need
   is less than or equal to Available.
7. Release its allocated resources.
8. Add the process to the safe sequence.
9. Repeat until all processes are completed
   or no further process can execute.
10. Display whether the system is safe or unsafe.

## Software Requirements
- C++ Compiler
- Linux or GitHub Codespaces

## Compilation
g++ Bankers.cpp -o bankers

## Execution
./bankers

## Result
Banker's safety algorithm determines whether
the system is in a safe state and displays
a safe sequence if one exists.
