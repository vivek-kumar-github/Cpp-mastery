#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> mySet;

    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(2);
    mySet.insert(4);
    mySet.insert(1);
    mySet.insert(2);

    cout << "Size of the set " << mySet.size() << endl;
    
    auto it = mySet.find(4);
    if (it != mySet.end()) {
        cout << "Found " << *it << endl;
    } else {
        cout << "Not Found " << endl;
    }

    mySet.erase(4);
    cout << "Erased 4 from the set" << endl;

    cout << "Elements in the set " << endl;
    for (const int& number : mySet) {
        cout << number << " ";
    }

    return 0;
}