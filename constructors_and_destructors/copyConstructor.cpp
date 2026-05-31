#include <iostream>
using namespace std;

class Car {
    private:
        string name;
        int model;
    
    public:
        Car() {
            cout << "Default constructor called " << endl;
            name = "Mazda";
            model = 2018;
        }
        
        Car(const Car& obj) {
            name = obj.name;
            model = obj.model;
            cout << "Car " << name << " Copied " << endl;
        }
};

int main() {
    Car x;

    Car copiedCar(x);

    return 0;
}