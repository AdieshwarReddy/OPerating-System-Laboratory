# Experiment 2: Deadlock Handling

## Aim
To implement deadlock detection, prevention and
recovery methods using C++.

## Theory
A deadlock occurs when a group of processes
wait indefinitely for resources held by one another.

## Necessary Conditions for Deadlock

1. Mutual Exclusion
2. Hold and Wait
3. No Preemption
4. Circular Wait

## Methods Implemented

### Deadlock Detection
Detects deadlocks by examining resource allocation,
outstanding requests and available resources.

### Deadlock Prevention
Prevents deadlock by eliminating at least one
of its necessary conditions.

This program uses resource ordering to prevent
the circular wait condition.

### Deadlock Recovery
Recovers from deadlock by terminating a selected
deadlocked process and releasing its resources.

## Files
- Detection.cpp
- Prevention.cpp
- Recovery.cpp
- OUTPUT.md

## Software Requirements
- C++ Compiler
- Linux or GitHub Codespaces

## Compilation and Execution

g++ Detection.cpp -o detection
./detection

g++ Prevention.cpp -o prevention
./prevention

g++ Recovery.cpp -o recovery
./recovery

## Result
Deadlock detection, prevention and recovery
methods are demonstrated using C++ simulations.
