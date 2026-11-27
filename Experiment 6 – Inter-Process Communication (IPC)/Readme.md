# Experiment 6: Inter-Process Communication

## Aim

To implement Inter-Process Communication (IPC)
using Shared Memory and Message Passing in C++.

## Theory

Inter-Process Communication is a mechanism
that allows processes to exchange data
and communicate with one another.

## IPC Methods

### 1. Shared Memory

Shared memory allows multiple processes to
access a common memory region.

One process writes data into shared memory,
and another process reads the data.

### 2. Message Passing

Message passing allows processes to communicate
by sending and receiving messages through
operating system mechanisms such as message queues.

## Shared Memory System Calls

- shmget(): Creates or obtains shared memory.
- shmat(): Attaches shared memory.
- shmdt(): Detaches shared memory.
- shmctl(): Controls or removes shared memory.

## Message Queue System Calls

- msgget(): Creates or obtains a message queue.
- msgsnd(): Sends a message.
- msgrcv(): Receives a message.
- msgctl(): Controls or removes a message queue.

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces
- System V IPC

## Compilation and Execution

g++ Shared_Memory.cpp -o shared_memory
./shared_memory

g++ Message_Passing.cpp -o message_passing
./message_passing

## Result

Inter-Process Communication is demonstrated
using shared memory and message queues in C++.
