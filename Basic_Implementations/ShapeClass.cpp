#include <iostream>
using namespace std;

class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a generic shape " << endl;
        }

        virtual ~Shape() {}
};

class Circle : public Shape {
    public:
        void draw() override {
            cout << "Drawing a circle " << endl;
        }
};

class Rectangle : public Shape {
    public:
        void draw() {
            cout << "Drawing a rectanle " << endl;
        }
};

int main() {
    Shape* circle = new Circle();
    Shape* rectanle = new Rectangle();

    circle->draw();
    rectanle->draw();

    return 0;
}