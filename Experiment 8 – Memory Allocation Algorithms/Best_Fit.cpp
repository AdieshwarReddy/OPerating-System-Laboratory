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

    // Best Fit Allocation
    for (int i = 0; i < n; i++) {

        int best = -1;

        for (int j = 0; j < m; j++) {

            if (block[j] >= process[i]) {

                if (best == -1 ||
                    block[j] < block[best]) {
                    best = j;
                }
            }
        }

        if (best != -1) {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    cout << "\nBest Fit Allocation\n";
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

Best Fit Allocation
Process Size    Block
P1      212     4
P2      417     2
P3      112     3
P4      426     5
