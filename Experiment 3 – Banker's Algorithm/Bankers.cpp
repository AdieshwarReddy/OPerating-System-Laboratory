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
    vector<vector<int>> maximum(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));

    vector<int> available(m);
    vector<int> safeSequence;
    vector<bool> finish(n, false);

    cout << "Enter Allocation Matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "Enter Maximum Matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maximum[i][j];

    cout << "Enter Available Resources:\n";

    for (int j = 0; j < m; j++)
        cin >> available[j];

    // Calculate Need Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (allocation[i][j] < 0 ||
                maximum[i][j] < allocation[i][j]) {
                cout << "Invalid resource allocation.\n";
                return 0;
            }

            need[i][j] = maximum[i][j]
                       - allocation[i][j];
        }
    }

    cout << "\nNeed Matrix:\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";

        for (int j = 0; j < m; j++)
            cout << need[i][j] << " ";

        cout << endl;
    }

    // Safety Algorithm
    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {
                bool possible = true;

                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {

                    for (int j = 0; j < m; j++)
                        available[j] += allocation[i][j];

                    safeSequence.push_back(i);
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        cout << "\nSystem is in a Safe State.\n";
        cout << "Safe Sequence: ";

        for (int i = 0; i < n; i++) {
            cout << "P" << safeSequence[i];

            if (i != n - 1)
                cout << " -> ";
        }

        cout << endl;
    } else {
        cout << "\nSystem is in an Unsafe State.\n";
        cout << "No safe sequence exists.\n";
    }

    return 0;
}
