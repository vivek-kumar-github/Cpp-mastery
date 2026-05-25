#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> sortedNums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    bool found = binary_search(sortedNums.begin(), sortedNums.end(), target);
    if (found) {
        cout << "Element " << target << " found";
    } else {
        cout << "Element " << target << " not found";
    }
    return 0;
}