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

    // Worst Fit Allocation
    for (int i = 0; i < n; i++) {

        int worst = -1;

        for (int j = 0; j < m; j++) {

            if (block[j] >= process[i]) {

                if (worst == -1 ||
                    block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }

    cout << "\nWorst Fit Allocation\n";
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


Sample output
Enter number of memory blocks: 5
Enter block sizes:
100 500 200 300 600

Enter number of processes: 4
Enter process sizes:
212 417 112 426

Worst Fit Allocation
Process Size    Block
P1      212     5
P2      417     2
P3      112     5
P4      426     Not Allocated

