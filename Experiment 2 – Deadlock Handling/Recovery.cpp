This program detects deadlocked processes, terminates a victim process and releases its resources until the deadlock is resolved.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    if (n <= 0 || m <= 0) return 0;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> request(n, vector<int>(m));
    vector<int> available(m);
    vector<bool> finish(n, false);

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "Enter Request Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> request[i][j];

    cout << "Enter Available Resources:\n";
    for (int j = 0; j < m; j++)
        cin >> available[j];

    for (int i = 0; i < n; i++) {
        bool holdsResource = false;

        for (int j = 0; j < m; j++)
            if (allocation[i][j] > 0)
                holdsResource = true;

        if (!holdsResource)
            finish[i] = true;
    }

    while (true) {
        bool progress;

        do {
            progress = false;

            for (int i = 0; i < n; i++) {
                if (finish[i]) continue;

                bool possible = true;

                for (int j = 0; j < m; j++) {
                    if (request[i][j] > available[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++)
                        available[j] += allocation[i][j];

                    finish[i] = true;
                    progress = true;

                    cout << "P" << i
                         << " completed.\n";
                }
            }
        } while (progress);

        int victim = -1;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                victim = i;
                break;
            }
        }

        if (victim == -1)
            break;

        cout << "Deadlock detected!\n";

        cout << "Terminating process P"
             << victim << endl;

        for (int j = 0; j < m; j++)
            available[j] += allocation[victim][j];

        finish[victim] = true;

        cout << "Resources released.\n";
    }

    cout << "System is free from deadlock.\n";

    cout << "Available Resources: ";
    for (int j = 0; j < m; j++)
        cout << available[j] << " ";

    cout << endl;

    return 0;
}

Sample output:

Enter number of processes: 2
Enter number of resources: 2

Enter Allocation Matrix:
1 0
0 1

Enter Request Matrix:
0 1
1 0

Enter Available Resources:
0 0

Deadlock detected!
Terminating process P0
Resources released.
P1 completed.
System is free from deadlock.
Available Resources: 1 1
