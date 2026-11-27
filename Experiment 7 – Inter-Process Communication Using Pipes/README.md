# Experiment 7: IPC Using Pipes

## Aim

To demonstrate Inter-Process Communication
using pipes in C++.

## Theory

A pipe is an Inter-Process Communication
mechanism that allows processes to exchange
data through a communication channel.

An ordinary pipe provides unidirectional
communication between processes.

A pipe contains two file descriptors:

- fd[0]: Read end of the pipe.
- fd[1]: Write end of the pipe.

One process writes data into the pipe,
and another process reads the data.

## Types of Pipes

1. Unnamed Pipe:
   Generally used for communication between
   related processes.

2. Named Pipe (FIFO):
   Can be used for communication between
   unrelated processes.

## System Calls Used

- pipe(): Creates a pipe.
- fork(): Creates a child process.
- write(): Writes data into the pipe.
- read(): Reads data from the pipe.
- close(): Closes a file descriptor.
- wait(): Waits for child process completion.

## Algorithm

1. Create a pipe using pipe().
2. Create a child process using fork().
3. Close the unused read end in the parent.
4. Write a message into the pipe.
5. Close the unused write end in the child.
6. Read the message from the pipe.
7. Display the received message.
8. Close the remaining file descriptors.
9. Wait for the child process to complete.

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces
- POSIX System Calls

## Compilation

g++ Pipe.cpp -o pipe_demo

## Execution

./pipe_demo

## Result

Inter-Process Communication between parent
and child processes is demonstrated using pipes.
