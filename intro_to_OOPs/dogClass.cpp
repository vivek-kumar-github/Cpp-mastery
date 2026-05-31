#include <iostream>
using namespace std;

class Dog {
    public:
        string name;
        int age;
        float weight;

        void print() {
            cout << "Hii my name is " << name;
            cout << ", and I am " << age << " years old.";
            cout << " My weight is " << weight << " kgs";
        }
};

int main() {
    Dog bars {"bar", 6, 35.5};

    bars.print();

    return 0;
}