#include <iostream>
using namespace std;

class Car {
    private:
        string name;
        int model;
    
    public:
        Car(string a, int b) {
            name = a;
            model = b;
        }

        void print() {
            cout << "Name " << name << " Model " << model << endl;
        }
};

int main() {
    Car car("Maserati", 2022); // Direct initialization

    car.print();

    return 0;
}