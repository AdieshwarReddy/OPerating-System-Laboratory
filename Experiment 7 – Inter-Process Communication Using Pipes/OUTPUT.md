# Experiment 7: IPC Using Pipes Output

## Input Configuration

- Number of Processes: 2
- Pipe Type: Unnamed Pipe
- Sender: Parent Process
- Receiver: Child Process
- Communication: Unidirectional
- Message: Hello from Parent Process!

## Expected Output

IPC Using Pipes
Parent sends: Hello from Parent Process!
Child receives: Hello from Parent Process!
Communication completed successfully.

## File Descriptors

| Descriptor | Purpose |
|------------|---------|
| fd[0] | Read end |
| fd[1] | Write end |

## System Calls Used

| System Call | Purpose |
|-------------|---------|
| pipe() | Creates a pipe |
| fork() | Creates a child process |
| write() | Sends data through the pipe |
| read() | Receives data from the pipe |
| close() | Closes a file descriptor |
| waitpid() | Waits for child completion |

## Process Operations

| Operation | Parent | Child |
|-----------|--------|-------|
| Read End | Closed | Used |
| Write End | Used | Closed |
| Send Message | Yes | No |
| Receive Message | No | Yes |

## Observations

- Pipes provide communication between processes.
- An unnamed pipe supports one-way communication.
- The parent process writes data into the pipe.
- The child process reads data from the pipe.
- Unused file descriptors should be closed.
- Two pipes can provide two-way communication.

## Result

Inter-Process Communication using an unnamed
pipe between parent and child processes was
demonstrated in C++.
