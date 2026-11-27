# Experiment 9: Page Replacement Algorithms

## Aim

To implement and compare FIFO, LRU and Optimal
page replacement algorithms using C++.

## Theory

Page replacement is a memory management technique
used by operating systems when a requested page
is not available in physical memory and all
available page frames are occupied.

## Page Replacement Algorithms

### 1. FIFO (First In First Out)

Replaces the page that entered memory first.

### 2. LRU (Least Recently Used)

Replaces the page that has not been accessed
for the longest period of time.

### 3. Optimal Page Replacement

Replaces the page whose next use is farthest
in the future or which will never be used again.

## Important Terms

- Page: A fixed-size unit of virtual memory.
- Frame: A fixed-size unit of physical memory.
- Page Hit: Requested page is present in memory.
- Page Fault: Requested page is absent from memory.
- Reference String: Sequence of requested pages.

## Formulas

Page Hits = Total References - Page Faults

Page Fault Rate =
(Page Faults / Total References) * 100

Page Hit Rate =
(Page Hits / Total References) * 100

## Files

- FIFO.cpp
- LRU.cpp
- Optimal.cpp
- OUTPUT.md

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces

## Compilation and Execution

g++ FIFO.cpp -o fifo
./fifo

g++ LRU.cpp -o lru
./lru

g++ Optimal.cpp -o optimal
./optimal

## Result

FIFO, LRU and Optimal page replacement algorithms
are implemented and compared based on page faults
and page fault rates.
