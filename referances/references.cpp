#include <iostream>
using namespace std;
int main() {
    int number = 42;
    int &ref = number; //create a "ref" link and associate it with the "number" variable
    cout << "Value of number: " << number << endl;
    cout << "Value of ref: " << ref << endl;

    ref = 99;
    
    cout << "New value of number: " << number << endl;
    cout << "New value of ref: " << ref << endl;

    //must initialize references at the time of declaration, and you cannot reassign them to refer to a different object later.
    // Once a reference links to an object, it maintains that connection for its entire lifespan
}