In C++, a **reference** is an alias or an alternative name for an existing object. **References** provide a convenient and safer alternative to pointers for indirect access and manipulation of objects. They act as an alias or an alternative name for an existing variable. References can simplify code, improve readability, and help avoid common pointer-related pitfalls. This section will explore the concept of references, their declaration and initialization, and their benefits over pointers.

## Declaration and initialization

To declare a reference, use the ampersand `(&)` symbol followed by the reference name. Once initialized, a reference acts as an alias for the variable. Any changes to this reference will then affect the original variable.

💡 The definition of a reference in C++ might remind you of the address-of operator. However, to steer clear of any confusion, keep in mind that the ampersand symbol should be on the left side of the equals sign when declaring a reference.

Here's an example that demonstrates the usage of references:

```cpp
#include <iostream>
using namespace std;

int main(){
    int number = 42;
    int &ref = number; //create a "ref" link and associate it with the "number" variable

    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;

    ref = 99;

    std::cout << "New value of number: " << number << std::endl;
    std::cout << "New value of ref: " << ref << std::endl;

    return 0;
}
```

Remember, you must initialize references at the time of declaration, and you cannot reassign them to refer to a different object later. Once a reference links to an object, it maintains that connection for its entire lifespan.

## Reference vs. pointer

References and pointers have similarities but also important differences:

- while pointers can be null and can be reassigned, references require initialization and you cannot change them to refer to a different variable.
- Pointers require explicit dereferencing to access the value, while you can use references directly as if they were the original variable.
- Using references can result in cleaner and more readable code. The syntax for accessing members of a referenced object is the same as for the original object, eliminating the need for dereferencing operators.
- References automatically handle dereferencing, allowing direct access to the referenced object without explicit dereference operations. This simplifies code and reduces the risk of errors caused by incorrect dereferencing.
- a single pointer can point to several different objects over its lifetime. In C++, a pointer is a variable that holds the memory address of an object. It can be reassigned to point to different objects during its lifetime.
- Unlike a reference, a pointer is an object in its own right. While a pointer is an object that stores the memory address of another object, a reference is not an object in itself. Instead, it acts as an alias or an alternative name for an existing object.

💡 A reference is a convenient and safer abstraction over pointers (inside, references are implemented using pointers).

Thus, in the following code, `ptr` and `ref` are treated in the same way:

```cpp
int number = 13;
int *ptr = &number; //Pointer
int &ref = number; //Reference
```

If there is a choice between a reference and a pointer, it is better to choose a reference.