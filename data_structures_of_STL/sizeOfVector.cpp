#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVec;
    while (1) {
        int i;
        cin >> i;
        if (i) {
            myVec.push_back(i);
        } else {
            break;
        }
    }
    cout << "Size of the vector: " << myVec.size();
    return 0;
}