# Experiment 1: CPU Scheduling Algorithms

## Aim
To implement CPU scheduling algorithms using C++ and compare their average waiting time, turnaround time and response time.

## Description
CPU scheduling is an operating system mechanism that selects a process from the ready queue for execution.

## Scheduling Algorithms

### 1. First Come First Served (FCFS)
Processes are executed in their arrival order.

### 2. Shortest Job Next (SJN)
The process with the shortest burst time is executed first.

### 3. Round Robin (RR)
Each process receives a fixed time quantum for execution.

### 4. Priority Scheduling
Processes are executed according to their priority.

## Formulae
- Turnaround Time = Completion Time - Arrival Time
- Waiting Time = Turnaround Time - Burst Time
- Response Time = First Execution Time - Arrival Time

## Assumptions
- All processes arrive at time zero.
- Burst times are positive.
- SJN and Priority Scheduling are non-preemptive.
- A lower priority number indicates higher priority.

## Software Requirements
- C++ Compiler
- GitHub Codespaces or Linux

## Compilation and Execution
g++ FCFS.cpp -o fcfs
./fcfs

g++ SJN.cpp -o sjn
./sjn

g++ Round_Robin.cpp -o rr
./rr

g++ Priority.cpp -o priority
./priority

## Result
The CPU scheduling algorithms calculate waiting time,
turnaround time and response time for each process.
