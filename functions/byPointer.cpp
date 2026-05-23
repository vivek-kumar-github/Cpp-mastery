#include <iostream>
using namespace std;

void byPtr(int *ptr) {
    //in order not to work with the address, dereference the pointer
    *ptr += 5; // Changes here will affect the original value through the pointer
    cout << ptr << endl << *ptr << endl;
}

int main() {
    int num = 5;
    byPtr(&num); // passing the address of the variable.
    cout << num << endl << &num;
}