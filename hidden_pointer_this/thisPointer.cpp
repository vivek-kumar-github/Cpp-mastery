#include <iostream>
using namespace std;

class MyClass {
    public:
        void display() {
            cout << "Address of the object is " << this << endl;
        }
};

int main() {
    MyClass obj;
    obj.display();

    cout << "Address of the object is " << &obj << endl;
    return 0;
}