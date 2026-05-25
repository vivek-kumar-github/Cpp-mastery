#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    auto it = find(numbers.begin(), numbers.end(), 5);

    if (it != numbers.end()) {
        cout << "Element found " << *it;
    } else {
        cout << "Element not found ";
    }

    return 0;
}