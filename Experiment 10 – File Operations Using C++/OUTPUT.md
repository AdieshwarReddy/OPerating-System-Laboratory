# Experiment 10: File Operations Output

## Input Configuration

- Original File Name: sample.txt
- Renamed File Name: renamed.txt
- File Type: Text File
- Programming Language: C++

## Expected Output

File Operations Using C++

1. File created successfully.
2. Data written successfully.

3. Reading File:
Operating Systems Lab
File Handling Using C++

4. Data appended successfully.

Updated File Contents:
Operating Systems Lab
File Handling Using C++
This is appended data.

5. File renamed successfully.
New filename: renamed.txt

6. File deleted successfully.

All File Operations Completed.

## File Operations Summary

| Operation | Function or Class | Expected Status |
|-----------|-------------------|-----------------|
| Create | ofstream | Successful |
| Write | ofstream | Successful |
| Read | ifstream | Successful |
| Append | ios::app | Successful |
| Rename | rename() | Successful |
| Delete | remove() | Successful |

## File Contents Before Appending

Operating Systems Lab
File Handling Using C++

## File Contents After Appending

Operating Systems Lab
File Handling Using C++
This is appended data.

## Observations

- ofstream creates and writes files.
- ifstream reads existing files.
- ios::app adds data without removing
  existing contents.
- rename() changes the name of a file.
- remove() deletes a file.
- Files should be closed after use.
- File opening errors should be handled.

## Result

File creation, writing, reading, appending,
renaming and deletion operations were
demonstrated using C++.
