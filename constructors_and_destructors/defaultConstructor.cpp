#include <iostream>
using namespace std;

class Car {
    private:
        string name;
        int model;
    
    public:
        Car() {
            cout << "Default constructor called" << endl;
            name = "BMW";
            model = 2012;
        }

        void print() {
            cout << "Name " << name << " Model " << model << endl;
        }
};

int main() {
    Car bmw;

    bmw.print();

    return 0;
}