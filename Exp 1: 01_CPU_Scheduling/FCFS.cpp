#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<int> bt(n), wt(n), tat(n);
    double totalWT = 0, totalTAT = 0;

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        if (bt[i] <= 0) return 0;
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    cout << "\nProcess\tBT\tWT\tTAT\tRT\n";

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        totalWT += wt[i];
        totalTAT += tat[i];

        cout << "P" << i+1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Average WT: " << totalWT/n << endl;
    cout << "Average TAT: " << totalTAT/n << endl;
    cout << "Average RT: " << totalWT/n << endl;

    return 0;
}

Sample output:
Enter number of processes: 3
Enter burst times: 5 3 8

Process BT  WT  TAT RT
P1      5   0   5   0
P2      3   5   8   5
P3      8   8   16  8

Average WT: 4.33
Average TAT: 9.67
Average RT: 4.33//
