# Experiment 5: Reader-Writer Problem

## Aim

To implement the Reader-Writer Problem using
semaphores in C++.

## Theory

The Reader-Writer Problem is a classical
process synchronization problem in operating systems.

Multiple readers can read shared data simultaneously.
However, a writer requires exclusive access to
the shared data.

When a writer is writing, no other reader or
writer is allowed to access the shared data.

## Semaphores Used

1. Mutex:
   Protects the reader count variable.

2. Write Semaphore:
   Provides exclusive access to shared data
   for writers and prevents writing while
   readers are accessing the data.

## Initial Values

- Mutex = 1
- Write Semaphore = 1
- Reader Count = 0
- Shared Data = 0

## Reader Algorithm

1. Acquire the mutex semaphore.
2. Increment the reader count.
3. If it is the first reader, acquire
   the write semaphore.
4. Release the mutex semaphore.
5. Read the shared data.
6. Acquire the mutex semaphore.
7. Decrement the reader count.
8. If it is the last reader, release
   the write semaphore.
9. Release the mutex semaphore.

## Writer Algorithm

1. Acquire the write semaphore.
2. Modify the shared data.
3. Release the write semaphore.

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces
- POSIX Threads and Semaphores

## Compilation

g++ Reader_Writer.cpp -o reader_writer -pthread

## Execution

./reader_writer

## Result

The Reader-Writer Problem is implemented using
semaphores to achieve synchronization and
mutual exclusion.
