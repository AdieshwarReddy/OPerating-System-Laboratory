# Experiment 8: Memory Allocation Algorithms

## Aim

To implement First Fit, Best Fit and Worst Fit
memory allocation algorithms using C++.

## Theory

Memory allocation is the process of assigning
available memory to processes for execution.

The operating system uses different allocation
strategies to manage memory efficiently.

## Memory Allocation Algorithms

### 1. First Fit

Allocates the first available memory block
that is large enough to accommodate a process.

### 2. Best Fit

Allocates the smallest available memory block
that is large enough to accommodate a process.

### 3. Worst Fit

Allocates the largest available memory block
that is large enough to accommodate a process.

## Fragmentation

- Internal Fragmentation:
  Unused memory inside an allocated partition.

- External Fragmentation:
  Free memory is divided into separate holes,
  making large allocations difficult.

## Files

- First_Fit.cpp
- Best_Fit.cpp
- Worst_Fit.cpp
- OUTPUT.md

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces

## Compilation and Execution

g++ First_Fit.cpp -o first_fit
./first_fit

g++ Best_Fit.cpp -o best_fit
./best_fit

g++ Worst_Fit.cpp -o worst_fit
./worst_fit

## Result

First Fit, Best Fit and Worst Fit memory
allocation algorithms are implemented and
compared using C++.
