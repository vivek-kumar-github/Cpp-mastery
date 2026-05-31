#include <iostream>
using namespace std;

class Car {
    private:
        string name;

    public:
        Car(string a) {
            name = a;
            cout << "Constructor executed for " << name << endl;
        }

        ~Car() {
            cout << "Destructor executed " << endl;
        }
};

int main() {
    Car Bugatti("Bugatti");

    return 0;
}