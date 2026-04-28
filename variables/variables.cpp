#include <iostream>
using namespace std;
int main() {
    int integerVar;
    cout << integerVar << endl;  //accessing before initialization gives garbage value
    integerVar = 1;
    cout << &integerVar << endl; //The & operator before any variable prints its address
    cout << integerVar << endl;

    //multiple declaration
    int a{2}, b(3);
    cout << a << endl << b << endl;

    //constants
    const float pi = 3.1415; //proper initialization of a constant
    //pi = 3.15;             //not allowed - compilation error.
    //const double grav;     //compilation error, the constant must be initialized.

    bool x = true; //printing true gives 1 as output
    char y = 'a';
    float z = 1.1;
    cout << x << endl << y << endl << z << endl;

    return 0;
}

/*
In C++, there are several ways to initialize variables:
    Copy Initialization: You can initialize a variable using the = operator. int x = 10;
    Direct Initialization: You can use parentheses () to directly initialize a variable. int y(5);

    Uniform Initialization: C++11 standard introduced uniform initialization. int z{7};

    The key advantage of uniform initialization is that it provides a consistent syntax for initializing
    different types of objects, including built-in types, user-defined types (classes), and arrays.
    It also supports initialization of complex objects, such as containers or nested structures, in a more intuitive way.

*/