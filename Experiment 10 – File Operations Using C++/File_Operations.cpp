#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

// Function to read a file
void readFile(const string& filename) {
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "Unable to open file.\n";
        return;
    }

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    string filename = "sample.txt";
    string newFilename = "renamed.txt";

    cout << "File Operations Using C++\n\n";

    // 1. Create and write into a file
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error creating file.\n";
        return 1;
    }

    outFile << "Operating Systems Lab\n";
    outFile << "File Handling Using C++\n";

    outFile.close();

    cout << "1. File created successfully.\n";
    cout << "2. Data written successfully.\n";

    // 3. Read file contents
    cout << "\n3. Reading File:\n";
    readFile(filename);

    // 4. Append data
    ofstream appendFile(filename, ios::app);

    if (!appendFile.is_open()) {
        cout << "Error opening file for appending.\n";
        return 1;
    }

    appendFile << "This is appended data.\n";
    appendFile.close();

    cout << "\n4. Data appended successfully.\n";

    cout << "\nUpdated File Contents:\n";
    readFile(filename);

    // 5. Rename file
    if (rename(filename.c_str(),
               newFilename.c_str()) == 0) {

        cout << "\n5. File renamed successfully.\n";
        cout << "New filename: "
             << newFilename << endl;

    } else {
        cout << "\nError renaming file.\n";
        return 1;
    }

    // 6. Delete file
    if (remove(newFilename.c_str()) == 0) {
        cout << "\n6. File deleted successfully.\n";
    } else {
        cout << "\nError deleting file.\n";
        return 1;
    }

    cout << "\nAll File Operations Completed.\n";

    return 0;
}

Sample output:

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
