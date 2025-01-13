#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cout << "o hai" << endl;

    vector<int> col1;
    vector<int> col2;

    ifstream ist {"input.txt"};
    if (!ist) {
        cout << "can't open file" << endl;
        return 1;
    }

    int a, b, total{0}, totalTimes{0};

    while (ist >> a >> b) {
        col1.push_back(a);
        col2.push_back(b);
        ++total;
    }

    cout << "total: " << total << endl;

    for (auto val : col1) {
        int col2Count = count(col2.begin(), col2.end(), val);
        cout << val << " appears " << col2Count << " times in col2" << endl;
        totalTimes += (val * col2Count);
    }

    cout << "totalTimes: " << totalTimes << endl;
    return 0;
}
