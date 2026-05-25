#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers;
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());

    cout << "Sorted vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    
    return 0;
}