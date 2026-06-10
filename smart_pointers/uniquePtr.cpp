#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> ptr(new int(23));

    int value = *ptr;
    cout << "Value " << value << endl;

    *ptr = 20;
    cout << "New value " << *ptr << endl;

    ptr.reset();

    return 0;
}