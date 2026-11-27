#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, q;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<int> bt(n), rem(n), wt(n),
                tat(n), rt(n, -1);

    cout << "Enter burst times: ";

    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        if (bt[i] <= 0) return 0;
        rem[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> q;

    if (q <= 0) return 0;

    int time = 0, completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {

                if (rt[i] == -1)
                    rt[i] = time;

                int run = min(q, rem[i]);

                time += run;
                rem[i] -= run;

                if (rem[i] == 0) {
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                    completed++;
                }
            }
        }
    }

    double totalWT = 0, totalTAT = 0, totalRT = 0;

    cout << "\nProcess\tBT\tWT\tTAT\tRT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\t"
             << rt[i] << endl;

        totalWT += wt[i];
        totalTAT += tat[i];
        totalRT += rt[i];
    }

    cout << fixed << setprecision(2);
    cout << "Average WT: " << totalWT/n << endl;
    cout << "Average TAT: " << totalTAT/n << endl;
    cout << "Average RT: " << totalRT/n << endl;

    return 0;
}


Sample output:

Enter number of processes: 3
Enter burst times: 5 3 8
Enter time quantum: 2

Process BT  WT  TAT RT
P1      5   7   12  0
P2      3   6   9   2
P3      8   8   16  4

Average WT: 7.00
Average TAT: 12.33
Average RT: 2.00
