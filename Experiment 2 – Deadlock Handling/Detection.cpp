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
            }
        }
    } while (progress);

    bool deadlock = false;

    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            if (!deadlock)
                cout << "Deadlock detected!\n";

            cout << "Deadlocked Process: P" << i << endl;
            deadlock = true;
        }
    }

    if (!deadlock)
        cout << "No deadlock detected.\n";

    return 0;
}


Sample Output:
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
Deadlocked Process: P0
Deadlocked Process: P1
