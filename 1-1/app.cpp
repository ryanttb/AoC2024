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

    int a, b, total{0}, totalDist{0};

    while (ist >> a >> b) {
        col1.push_back(a);
        col2.push_back(b);
        ++total;
    }

    cout << "total: " << total << endl;

    for (auto times = 0; times < total; ++times) {
        auto col1SmallestIt = min_element(col1.begin(), col1.end());
        std::size_t col1Index = distance(col1.begin(), col1SmallestIt );
        auto col2SmallestIt = min_element(col2.begin(), col2.end());
        std::size_t col2Index = distance(col2.begin(), col2SmallestIt );
        
        cout << "col1 smallest: " << *col1SmallestIt;
        cout << ", col2 smallest: " << *col2SmallestIt;

        auto diff = abs(*col1SmallestIt - *col2SmallestIt);
        cout << ", diff: " << diff << endl;

        totalDist += diff;

        col1[col1Index] = INT_MAX;
        col2[col2Index] = INT_MAX;
    }


    cout << "Total distance: " << totalDist << endl;

    return 0;
}
