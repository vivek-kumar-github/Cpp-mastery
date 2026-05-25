#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int freq = count(numbers.begin(), numbers.end(), 5);

    cout << "Frequency of 5 is " << freq;
    
    return 0;
}