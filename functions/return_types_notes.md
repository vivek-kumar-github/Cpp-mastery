Most functions return some value at the end of their work (but some "return" void). A critical aspect of functions is comprehending how to define their return types and how to effectively employ the return statement to relay outcomes to the calling code. This topic details the various ways to pass results from functions.

## Understanding return types

Before you dive into how the return statement works, let's first understand the idea of **return types**. In C++, a return type simply tells what kind of information a function will give back when it's done running. This lets functions share important data or answers that you can use for other calculations.

When creating a function prototype or when describing a function, specify the return type (even if the function does not return anything, specify a `void`):

```cpp
void len(double x);
int sum(int a, int b);

int sum(int a, int b) {
    // function implementation code
}

void len(double x) {
    // function implementation code
}
```

When calling a function, you expect (and the compiler, too) that it will return exactly the type that you have defined. If it suddenly turns out that the type is different, then the compiler will definitely give you an error, because it checks the return type and prevents you from returning something else.

```cpp
int s;
s = sum(10, 3);
```

But what if there is a branch in the function and you want to exit early, and at the same time, the return type of the function is `void`? It's pretty simple:

```cpp
#include <iostream>

void print_message(int value) {
    if (value < 0) {
        std::cout << "Value is negative." << std::endl;
        return;  // It's important to return here to avoid output on the next line
    }
    std::cout << "Value is non-negative." << std::endl;
}

int main() {

    print_message(-5);
    print_message(10);

    return 0;
}
```

```no-highlight
Output:
Value is negative.
Value is non-negative.
```

## The return statement

The **return statement** emerges as a pivotal tool for transmitting results from a function to the calling code. It's employed within the function's body to specify the value that will be transmitted back as the function's outcome. The return statement also signifies the culmination of the function's execution.

```cpp
int add(int a, int b) {
    return a + b; // Returns the sum of a and b
}
```

In this example, the function `add` possesses a return type of `int`. The return statement `return a + b;` computes the sum of `a` and `b` and transmits it back as the outcome of the function.

Just like passing values to a function, there are three ways to return a value from a function to the calling code:

- by value;
- by reference;
- by pointer;

## Return by value

The traditional method of **returning values by value** involves transmitting a copy of the value itself. This is useful when you don't want the caller to modify the original value and need a distinct copy.

```cpp
std::string greet() {
    return "Hello, World!"; // Returns a string
}
```

The function `greet` returns a copy of the string containing the greeting message.

Here, the same problem can arise when passing values to a function, namely with the overhead for large objects.

## Return by reference

C++ allows returning values by reference. This implies that instead of returning a copy of a value, a reference to the original value is returned. This can be very useful when you want to allow the calling code to modify the original value directly.

However, when a function concludes, it discards local variables. Consequently, any reference that points to these variables becomes precarious as it now references reclaimed memory. This phenomenon is referred to as a 'dangling reference,' and employing it to access or modify the variable can trigger erratic outcomes, crashes, or memory corruption.

To avert such perils, it's essential to abstain from returning references to local variables. Instead, consider more secure alternatives such as returning values.

```cpp
int &getLarger(int &a, int &b) {
    return (a > b) ? a : b;
}
```

The function `getLarger` returns a reference to the larger of the two integers provided, enabling the caller to modify the larger value.

Return by reference is typically used to return arguments passed to a function by reference.

## Return by pointer

Returning values **by pointer** is another avenue in C++ to transmit data back to the caller. This involves returning a pointer to the original data. It offers similar capabilities to returning by reference, with added flexibility for pointing to different memory locations. Since returning by address simply copies the address from the function to the caller, this process is also very fast.

However, just like returning by reference, you must not return local variables by address.

```cpp
int *findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return &arr[i];
        }
    }
    return nullptr; // If element is not found
}
```

The function `findElement` returns a pointer to the target element. If the element is not found, it returns a `nullptr`. Here we use two `return` to exit the function under different conditions (actually, you can use as many as you want).