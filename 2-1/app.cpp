#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

using Report = std::vector<int>; // A single report containing levels.
using Reports = std::vector<Report>; // A collection of reports.

int main() {
    vector<int> levels;
    vector<int> report;

    Reports reports; // A collection vector of reports.

    ifstream ist {"input.txt"};
    if (!ist) {
        cout << "can't open file" << endl;
        return 1;
    }


    string line;

    while (getline(ist, line)) {
        istringstream iss(line);
        Report report;

        int prevLevel{INT_MIN}, level, direction{0};
        bool safe{true};

        while (iss >> level) {
            cout << level << " ";

            report.push_back(level);

            if (prevLevel == INT_MIN) {
                prevLevel = level;
            } else {
                // not the first, make decisions
                if (direction < 0) {
                    if (level > prevLevel) {
                        cout << "Unsafe: change in direction" << endl;
                        safe = false;
                    }
                } else if (direction > 0) {
                    if (level < prevLevel) {
                        cout << "Unsafe: change in direction" << endl;
                        safe = false;
                    }
                } else { // direction == 0 on second level, decide direction
                    if (prevLevel < level) {
                        direction = +1;
                    } else if (prevLevel > level) {
                        direction = -1;
                    } else {
                        cout << "Unsafe: no change in direction" << endl;
                        safe = false;
                    }
                }
            }

            prevLevel = level;
        }

        reports.push_back(report);
        cout << endl;
    }

    return 0;
}
