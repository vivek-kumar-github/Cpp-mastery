#include <iostream>
using namespace std;

class Calc {
    public:
        int a;
        int b;

        int addition() {
            return a + b;
        }

        int multiplication() {
            return a * b;
        }

        int division() {
            return a / b;
        }

        int subtraction() {
            return a - b;
        }
};

int main() {
    Calc c1 {2, 2};

    cout << c1.addition() << endl;
    cout << c1.multiplication() << endl;
    cout << c1.division() << endl;
    cout << c1.subtraction() << endl;

    return 0;
}