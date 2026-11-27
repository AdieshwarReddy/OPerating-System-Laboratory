#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    vector<int> block(m);

    cout << "Enter block sizes:\n";
    for (int i = 0; i < m; i++)
        cin >> block[i];

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> process(n);
    vector<int> allocation(n, -1);

    cout << "Enter process sizes:\n";
    for (int i = 0; i < n; i++)
        cin >> process[i];

    // First Fit Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation\n";
    cout << "Process\tSize\tBlock\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << process[i] << "\t";

        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";

        cout << endl;
    }

    return 0;
}


Sample output:
Enter number of memory blocks: 5
Enter block sizes:
100 500 200 300 600

Enter number of processes: 4
Enter process sizes:
212 417 112 426

First Fit Allocation
Process Size    Block
P1      212     2
P2      417     5
P3      112     2
P4      426     Not Allocated
