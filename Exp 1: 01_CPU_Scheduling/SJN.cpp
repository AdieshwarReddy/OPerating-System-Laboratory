#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<pair<int, int>> p(n);

    cout << "Enter burst times: ";

    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        if (p[i].first <= 0) return 0;
        p[i].second = i + 1;
    }

    sort(p.begin(), p.end());

    int time = 0;
    double totalWT = 0, totalTAT = 0;

    cout << "\nProcess\tBT\tWT\tTAT\tRT\n";

    for (int i = 0; i < n; i++) {
        int bt = p[i].first;
        int wt = time;
        int tat = wt + bt;

        cout << "P" << p[i].second << "\t"
             << bt << "\t"
             << wt << "\t"
             << tat << "\t"
             << wt << endl;

        totalWT += wt;
        totalTAT += tat;
        time += bt;
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
P2      3   0   3   0
P1      5   3   8   3
P3      8   8   16  8

Average WT: 3.67
Average TAT: 9.00
Average RT: 3.67
