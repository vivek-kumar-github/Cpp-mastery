#include <iostream>
using namespace std;

void add(int a, double b) {
    cout << "Adding int and double " << a + b << endl; 
}

void add(double a, int b) {
    cout << "Adding double and int " << a + b << endl;
}

int main() {
    add(2, 3.2);
    add(2.3, 3);

    return 0;
}