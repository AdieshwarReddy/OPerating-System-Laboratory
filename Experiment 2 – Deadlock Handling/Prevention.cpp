This program demonstrates deadlock prevention by enforcing an ascending resource acquisition order.

  #include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    if (n <= 0 || m <= 0) return 0;

    vector<int> highest(n, 0);

    int operations;
    cout << "Enter number of resource requests: ";
    cin >> operations;

    cout << "Enter process ID and resource ID:\n";

    for (int i = 0; i < operations; i++) {
        int p, r;
        cin >> p >> r;

        if (p < 0 || p >= n || r < 1 || r > m) {
            cout << "Invalid request.\n";
            continue;
        }

        if (r > highest[p]) {
            highest[p] = r;

            cout << "P" << p
                 << " request for R" << r
                 << " accepted.\n";
        } else {
            cout << "P" << p
                 << " request for R" << r
                 << " rejected.\n";

            cout << "Resource ordering violated.\n";
        }
    }

    cout << "Circular wait prevented.\n";

    return 0;
}


Sample output:

Enter number of processes: 2
Enter number of resource types: 2
Enter number of resource requests: 4

Enter process ID and resource ID:
0 1
P0 request for R1 accepted.

1 2
P1 request for R2 accepted.

0 2
P0 request for R2 accepted.

1 1
P1 request for R1 rejected.
Resource ordering violated.

Circular wait prevented.
