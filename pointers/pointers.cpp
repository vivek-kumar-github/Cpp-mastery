#include <iostream>
using namespace std;
int main() {
    int age = 22;
    cout << age << endl; //prints age
    cout << &age << endl; //prints memory address of age variable

    /*
    In C++, a pointer is a variable that stores the memory address of another variable.
    It allows us to indirectly access and manipulate data by referring to its memory location.
    Pointers provide flexibility and efficiency in memory management.
    They enable us to work with dynamic data structures, pass arguments by reference, and interact with low-level operations.

    Pointers are declared with an asterisk (*) between the data type and the identifier:
    */
    int number = 11;
    int *ptr = &number;
    cout << "Value of number " << number << endl;
    cout << "Address of variable " << &number << endl;
    cout << "The address of variable stored in pointer " << ptr << endl;

    //pointer must be of the same data type as the object it points to.

    
    return 0;
}