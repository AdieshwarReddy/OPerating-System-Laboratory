# Experiment 4: Producer-Consumer Problem

## Aim
To demonstrate the synchronization of producer
and consumer processes using semaphores in C++.

## Theory
The Producer-Consumer Problem is a classical
process synchronization problem in operating systems.

The producer generates items and places them
in a shared buffer.

The consumer removes items from the shared
buffer and consumes them.

Synchronization is required to prevent buffer
overflow, buffer underflow and race conditions.

## Semaphores Used

1. Empty:
   Counts the available empty slots in the buffer.

2. Full:
   Counts the occupied slots in the buffer.

3. Mutex:
   Ensures mutual exclusion while accessing
   the shared buffer.

## Initial Values

- Buffer Size = 5
- Empty = 5
- Full = 0
- Mutex = 1

## Producer Algorithm

1. Wait for an empty slot.
2. Acquire the mutex semaphore.
3. Produce an item and insert it into the buffer.
4. Release the mutex semaphore.
5. Signal the full semaphore.

## Consumer Algorithm

1. Wait for an available item.
2. Acquire the mutex semaphore.
3. Remove an item from the buffer.
4. Release the mutex semaphore.
5. Signal the empty semaphore.

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces
- POSIX Threads and Semaphores

## Compilation

g++ Producer_Consumer.cpp -o producer_consumer -pthread

## Execution

./producer_consumer

## Result

The Producer-Consumer Problem is implemented
using semaphores to achieve synchronization
and mutual exclusion.
