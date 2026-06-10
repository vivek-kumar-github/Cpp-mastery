#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr(new int(34));

    int *rawPtr = ptr.get();
    cout << "Value " << *rawPtr << endl;

    int &ref = *ptr;
    cout << "Value " << ref << endl;

    return 0;
}