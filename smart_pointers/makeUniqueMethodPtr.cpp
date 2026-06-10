#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto ptr = make_unique<int>(36);

    cout << "Value " << *ptr << endl;

    *ptr = 38;

    cout << "New value " << *ptr << endl;

    return 0;
}