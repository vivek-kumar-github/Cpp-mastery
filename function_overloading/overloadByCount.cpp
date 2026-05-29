#include <iostream>
using namespace std;

int add(int a, int b) {
    cout << "Added two numbers" << endl;
    return a + b;
}

int add(int a, int b, int c) {
    cout << "Added three numbers" << endl;
    return a + b + c;
}

int main() {
    cout << add(2, 3) << endl;
    cout << add(2, 3, 5) << endl;

    return 0;
}