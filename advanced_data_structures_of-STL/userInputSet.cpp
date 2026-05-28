#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet;

    int rep;
    cin >> rep;

    while (rep--) {
        int inp;
        cin >> inp;
        mySet.insert(inp);
    }

    cout << "Unique numbers in ascending order: ";
    for (const int& num : mySet) {
        cout << num << " ";
    }
    
    return 0;
}