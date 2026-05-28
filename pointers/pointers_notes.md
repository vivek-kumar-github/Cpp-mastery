Pointers are essential tools in C++ programming that allow us to manipulate memory addresses and access data indirectly. They provide us with power mechanisms for managing memory, creating dynamic data structures, and optimizing program efficiency.

There is a belief that pointers are quite difficult to understand and can cause errors even for experienced programmers. But you just need to be a little more careful with them.

However, once you grasp their concepts and learn how to use them effectively, you will unlock new possibilities in your programming journey.

## Address-of operator (&)

During the initialization of a variable in C++, it automatically gets a free memory address. It stores any value you assign to the variable. For example: `int age = 32;` When the processor executes this statement, it allocates a portion of the computer's memory with a specific address (let's say `0x3093cea98`). Just now, the variable is associated with the memory address.

In previous topics, you saw how to obtain the address of an object in C++. This is done using the **address-of operator**`(&)`. The **address-of operator**`(&)` allows us to determine the memory address assigned to a specific variable. It's quite simple:

```cpp
#include <iostream>
using namespace std;

int main(){
    int age = 32;
    cout << age << endl; //print the value of the variable (32)
    cout << &age << endl; //print the memory address of the variable (0x3093cea98)

    return 0;
}
```

By using the address-of operator, you can access the memory address of variables, which is a fundamental concept when working with pointers and references in C++.

## Pointers

Ok, I have a variable `age` with a value and now even its memory address. Can I store the address itself in a variable? Almost. In C++, there is another fundamental data type called a **pointer** specifically designed for storing memory addresses.

In C++, a **pointer** is a variable that stores the memory address of another variable. It allows us to indirectly access and manipulate data by referring to its memory location. Pointers provide flexibility and efficiency in memory management. They enable us to work with dynamic data structures, pass arguments by reference, and interact with low-level operations.

Pointers are declared in the same way as regular variables but with an asterisk `(*)` between the data type and the identifier:

```cpp
#include <iostream>
using namespace std;

int main(){
    int number = 11; //our variable
    int *ptr = &number; //and this's a pointer to the address of our variable

    cout << "value of number:   " << number << endl;
    cout << "address of number: " << &number << endl;
    cout << "pointer content:   " << ptr << endl; //the address of our variable stored in a pointer

    double pi = 3.14;
    double *piptr = &pi;

    cout << "value of number:   " << pi << endl;
    cout << "address of number: " << &pi << endl;
    cout << "pointer content:   " << piptr << endl; //the address of our variable stored in a pointer

    // trying to put the address of a variable of type int into the double pointer
    double *newptr = &number; //error

    return 0;
}
```

💡 It is important to remember that a pointer must be of the same data type as the object it points to.

if `int n;` then `int *iptr = &n;`

if `double m;` then `double *dptr = &m;`

How much memory do you need to store types like `int` or `double`? Does a pointer to these types also occupy space (after all, you need to store the memory address somewhere)? The `sizeof()` operator has the answers to these questions:

```cpp
#include <iostream>
using namespace std;

int main(){
    int number = 11;
    int *ptr = &number;

    cout << "int size:        " << sizeof(number) << endl;
    cout << "ptr to int size: " << sizeof(ptr) << endl << endl;

    double pi = 3.14;
    double *piptr = &pi;

    cout << "double size:        " << sizeof(pi) << endl;
    cout << "ptr to double size: " << sizeof(piptr) << endl;

    return 0;
}
```

In our case, you get the following result:

```no-highlight
int size:        4
ptr to int size: 8

double size:        8
ptr to double size: 8
```

And what's the point? For the `double` type, the memory size that the **variable** and the **pointer** occupies is the same, but for the `int` type, it is twice as much. Yes, the advantage is not particularly noticeable for basic data types, but the size of a pointer is always fixed (since you only store the address and nothing more). This is where the main advantage of a pointer lies: you can have an object of any size somewhere, even 1GB, without passing it around in our program, and always manipulate a pointer to its memory address.

The size of a pointer in C++ can vary across computer systems, depending on the underlying architecture. It is typically equal to the native word size, such as 4 bytes on a 32-bit system or 8 bytes on a 64-bit system. However, variations in pointer size exist, especially with different computer architectures or specialized systems. Consider these variations when writing C++ code for portability and compatibility.

Okay, so a pointer stores the address, but can you somehow retrieve the value from it? Of course, for that, use the **dereference operator**`(*)` with a pointer.

## Dereference operator (\*)

When you dereference a pointer, it means getting the value that is stored at the memory address it points to. You do it using the dereference operator (`*`). Dereferencing allows you to read or modify the value at that memory location:

```cpp
#include <iostream>
using namespace std;

int main(){
    int number = 11;
    int *ptr = &number;

    cout << "value of number:   " << number << endl;
    cout << "address of number: " << &number << endl;
    cout << "pointer content:   " << ptr << endl; //the address of our variable stored in a pointer

    //Aaaand...
    cout << "Value at the address pointed to by ptr: " << *ptr << endl;
    *ptr = 39;
    cout << number;

    return 0;
}
```

Understanding the dereference operator is crucial when working with pointers and references in C++. It enables us to access and manipulate data indirectly, giving us power capabilities in memory management and data manipulation.

## Null pointers

Pointers can be very tricky (more than variables) because you can declare them without initializing them (in which case the pointer will point to an unknown area of memory). You need to be extremely careful because a pointer can point to something you don't intend to change, and you won't be able to verify it. Below is a valid code example, but it can potentially lead to significant issues if you attempt to write something to such a pointer.

```cpp
int *ptr;

// Print the value of the pointer 'ptr' (may be a memory address)
cout << ptr << endl;
// Dereference and print the value (undefined behavior if uninitialized)
cout << *ptr << endl;

// Write a value to the memory location pointed by 'ptr' (potential errors if uninitialized or invalid)
*ptr = 100;
// Where do we write the data? Maybe we break the work of our OS?

// print the updated value it points to (undefined behavior due to previous potential errors)
cout << *ptr << endl;
```

To safeguard yourself, you can use a **null pointer**. A **null pointer** is a special value that indicates it is not pointing to any valid memory address. You can assign it explicitly using the value `nullptr` or by assigning a zero to the pointer.

```cpp
int *ptr = nullptr;  // assigning nullptr to the pointer
int *ptr = 0;  // used to do this, now not recommended
```

💡 Null pointers are dangerous because they do not point to a valid memory location. When you dereference a null pointer, that is, when you try to access the memory location it points to, it leads to undefined behavior. This can result in crashes, program termination, or unpredictable results. It can also lead to memory corruption if the null pointer is mistakenly used to read from or write to memory.

It is crucial to handle null pointers appropriately to avoid crashes and undefined behavior in the program.