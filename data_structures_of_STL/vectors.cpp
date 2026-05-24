#include <iostream>
#include <vector>
using namespace std;

int main() {
    // std::vector is a versatile and fundamental data structure that represents a dynamic array

    vector<int> myVec;

    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);

    cout << myVec[1] << endl;
    cout << myVec.at(2) << endl;

    cout << myVec.size() << endl;
    cout << myVec.empty() << endl;

    for (int i = 0; i < myVec.size(); i++) {
        cout << myVec[i] << " ";
    }

    myVec.clear();
}