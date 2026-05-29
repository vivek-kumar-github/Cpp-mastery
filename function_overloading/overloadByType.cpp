#include <iostream>
using namespace std;

int add(int a, int b) {
    cout << "Integer addition" << endl;
    return a + b;
}

double add(double a, double b) {
    cout << "Double addition" << endl;
    return a + b;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2.0, 3.0) << endl;

    return 0;
}