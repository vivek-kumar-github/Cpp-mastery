#include <iostream>
using namespace std;

class Dog {
    private:
        string name;
        int age;
        float weight;

    public:
        Dog() {
            cout << "This is constructor and will be called by default when object will be created for this class " << endl;
            
            name = "Barkis";
            age = 5;
            weight = 33.3;
        }

        void print() {
            cout << "Name " << name << " Age " << age << " Weight " << weight << endl;
        }
};

int main() {
    Dog bars;

    bars.print();

    return 0;
}