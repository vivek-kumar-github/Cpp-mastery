#include <iostream>
using namespace std;

const double pi = 3.14159265359;

double calculate(double a, double b) {
    return a * b;
}

double calculate(double r) {
    return pi * r * r;
}

int main() {
    double rectArea = calculate(5.0, 3.0);
    double circleArea = calculate(2.5);

    cout << "Area of rectangle " << rectArea << endl;
    cout << "Area of circle " << circleArea << endl;

    return 0;
}