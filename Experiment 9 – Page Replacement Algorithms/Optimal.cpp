#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of pages: ";
    cin >> n;

    if (n <= 0) return 0;

    vector<int> pages(n);

    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> capacity;

    if (capacity <= 0) return 0;

    vector<int> frames;

    int faults = 0, hits = 0;

    cout << "\nOptimal Page Replacement\n";
    cout << "Page\tFrames\t\tStatus\n";

    for (int i = 0; i < n; i++) {

        int page = pages[i];

        bool hit = find(frames.begin(),
                        frames.end(), page)
                   != frames.end();

        if (hit) {
            hits++;
        } else {
            faults++;

            if (frames.size() < capacity) {
                frames.push_back(page);
            } else {

                int farthest = -1;
                int replaceIndex = 0;

                for (int j = 0;
                     j < frames.size(); j++) {

                    int k;

                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j])
                            break;
                    }

                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }

                frames[replaceIndex] = page;
            }
        }

        cout << page << "\t";

        for (int frame : frames)
            cout << frame << " ";

        cout << "\t\t"
             << (hit ? "Hit" : "Fault")
             << endl;
    }

    cout << "\nTotal Page Faults: " << faults;
    cout << "\nTotal Page Hits: " << hits;

    cout << fixed << setprecision(2);

    cout << "\nPage Fault Rate: "
         << faults * 100.0 / n << "%";

    cout << "\nPage Hit Rate: "
         << hits * 100.0 / n << "%\n";

    return 0;
}


Sample output:

Enter number of pages: 13
Enter page reference string:
7 0 1 2 0 3 0 4 2 3 0 3 2
Enter number of frames: 3

Optimal Page Replacement
Page    Frames          Status
7       7               Fault
0       7 0             Fault
1       7 0 1           Fault
2       2 0 1           Fault
0       2 0 1           Hit
3       2 0 3           Fault
0       2 0 3           Hit
4       2 4 3           Fault
2       2 4 3           Hit
3       2 4 3           Hit
0       2 0 3           Fault
3       2 0 3           Hit
2       2 0 3           Hit

Total Page Faults: 7
Total Page Hits: 6
Page Fault Rate: 53.85%
Page Hit Rate: 46.15%
