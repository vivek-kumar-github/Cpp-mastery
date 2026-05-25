#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        cout << num << " ";
    }
    
    return 0;
}