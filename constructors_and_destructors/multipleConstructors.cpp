#include <iostream>
using namespace std;

class Car {
    private:
        string name;
        int model;

    public:
        Car() {
            cout << "Default constructor called" << endl;
        }

        Car(string a, int b) {
            cout << "Parameterized constructor called" << endl;
            name = a;
            model = b;
        }

        Car(const Car& obj) {
            cout << "Copy constructor called " << endl;
            name = obj.name;
            model = obj.model;
        }
};

int main() {
    Car McLaren;

    Car Pagani("Pagani", 2016);

    Car CopyPagani(Pagani);
}