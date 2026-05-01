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

    //the size of a pointer is always fixed (since you only store the address and nothing more).
    //You can have an object of any size somewhere, even 1GB, without passing it around in our program,
    // and always manipulate a pointer to its memory address
    double pi = 3.14;
    double *piptr = &pi;
    cout << "Size of double pointer " << sizeof(piptr) << endl;

    //When you dereference a pointer, it means getting the value that is stored at the memory address it points to.
    // You do it using the dereference operator (*). Dereferencing allows you to read or modify the value at that memory location:
    cout << "Value of piptr " << *piptr << endl;

    //A pointer only declared and not initialized is called null pointer and is dangerous because it points to any unknown
    //memory location and dereferencing and modifying it can break any program
    //e.g. int *ptr; *ptr = 100;

    //To avoid this we use null pointer A null pointer is a special value that indicates it is not pointing to any valid memory address.
    // We can assign it explicitly using the value (nullptr) or by assigning a zero to the pointer.
    int *ptr1 = nullptr;
    int *ptr2 = 0; //this is not recommended
    
    return 0;
}