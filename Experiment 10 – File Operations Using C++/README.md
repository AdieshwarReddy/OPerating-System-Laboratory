# Experiment 10: File Operations Using C++

## Aim

To demonstrate various file operations using C++.

## Theory

File handling allows programs to store and
retrieve data from secondary storage.

C++ provides the fstream header for performing
file input and output operations.

## File Stream Classes

1. ofstream:
   Used to create and write data into files.

2. ifstream:
   Used to read data from files.

3. fstream:
   Used for both reading and writing files.

## File Operations Implemented

- Creating a file
- Writing data into a file
- Reading data from a file
- Appending data to a file
- Renaming a file
- Deleting a file

## File Opening Modes

| Mode | Purpose |
|------|---------|
| ios::in | Reading |
| ios::out | Writing |
| ios::app | Appending |
| ios::ate | Move to end after opening |
| ios::trunc | Remove existing contents |
| ios::binary | Binary file operations |

## Functions Used

- open(): Opens a file.
- close(): Closes a file.
- getline(): Reads a line from a file.
- rename(): Renames a file.
- remove(): Deletes a file.
- is_open(): Checks whether a file is open.

## Software Requirements

- C++ Compiler
- Linux or GitHub Codespaces

## Compilation

g++ File_Operations.cpp -o file_operations

## Execution

./file_operations

## Result

Various file operations are demonstrated
successfully using C++ file streams.
