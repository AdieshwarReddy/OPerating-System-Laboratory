#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int id, bt, priority;
};

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<Process> p(n);

    cout << "Enter burst time and priority:\n";

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].bt >> p[i].priority;
        if (p[i].bt <= 0) return 0;
    }

    stable_sort(p.begin(), p.end(),
        [](Process a, Process b) {
            return a.priority < b.priority;
        });

    int time = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nProcess\tBT\tPR\tWT\tTAT\tRT\n";

    for (int i = 0; i < n; i++) {
        int wt = time;
        int tat = wt + p[i].bt;

        cout << "P" << p[i].id << "\t"
             << p[i].bt << "\t"
             << p[i].priority << "\t"
             << wt << "\t"
             << tat << "\t"
             << wt << endl;

        totalWT += wt;
        totalTAT += tat;
        time += p[i].bt;
    }

    cout << fixed << setprecision(2);
    cout << "Average WT: " << totalWT/n << endl;
    cout << "Average TAT: " << totalTAT/n << endl;
    cout << "Average RT: " << totalWT/n << endl;

    return 0;
}

Sample output:
Enter number of processes: 3
Enter burst time and priority:
5 2
3 1
8 3

Process BT  PR  WT  TAT RT
P2      3   1   0   3   0
P1      5   2   3   8   3
P3      8   3   8   16  8

Average WT: 3.67
Average TAT: 9.00
Average RT: 3.67
