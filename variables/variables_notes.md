In programming, variables play a crucial role as they allow us to store and manipulate data. Variables are named containers that hold values of various types, such as numbers, characters, or text. They serve as a way to label and refer to specific data stored in a computer's memory. Variables enable us to store information temporarily or permanently, perform calculations, make decisions, and create dynamic programs. Understanding how to work with variables is fundamental to programming, and in this topic, we will learn how to declare and use variables in C++ programs.

## Declare a variable

Let's remember how we can declare a variable (allocate memory for the object):

```cpp
bool ourBoolVariable; //declare a boolean variable
int ourIntVariable; // declare an integer variable
float ourFloatVariable; // declare a floating point variable
char ourCharVariable; //declare a character variable

//this code will not work because "void" cannot be used as a variable type.
void ourVoidVariable;
```

The **name** (or **identifier)** distinguishes the variable from others.

Here are a few small rules about variable names:

- The name of a variable cannot start with a digit, it usually starts with a letter.

- Always try to choose meaningful and readable names for variables to make your code easy to understand.

- Such names are chosen for clarity, there is no need to include the variable's type in its name.

- The case in the name of a variable makes a difference: `variable` is not the same as `VARiablE`.


We discussed that a variable is a label for an object that has a specific address in computer memory. We can easily verify this. In C++, there is a simple way to view the address of our object (using the address-of operator `&`, which should be placed before the variable name):

```c++
#include <iostream>
using namespace std;

int main(){
    int ourIntVariable;
    cout << &ourIntVariable << endl; //will output something like: 0x3093cea98

    return 0;
}
```

## Assign the value

After declaring a variable, we can assign it a value, which means storing a value in the memory cell associated with that variable. There is one restriction for variables: you can only assign a value of the same type as the type of the initial variable.

```c++
ourBoolVariable = false;
ourIntVariable = 100500;
ourDoubleVariable = 2.718;
ourCharVariable = 'X';
```

Once a variable has been declared, its value can be accessed and modified using the name.

The logic of assigning is as follows: first, the expression located to the right of the `=` is evaluated. Then, the resulting value is placed into the variable whose name is located to the left of the `=` sign. Let's consider a more detailed example:

```c++
int number;
number = 100; //number contains 100

//Note that if you assign a new value to an existing variable,
//it will overwrite the previous value:

//the order of arithmetic operations is preserved.
number = 2 + 2 * 2; //number contains 6, not 8
number = number + 4; //it's OK, now number contains 10
number = "twenty"; // it isn't correct! Invalid data type

//we can print our 'number' to the console.
std::cout << number;
```

## Uninitialized variables

What if we want to output the value of an uninitialized variable immediately after its declaration?

```cpp
#include <iostream>

int main()
{
    int a;
    std::cout << a;
    return 0;
}
```

If you attempt to output the value of a variable immediately after its declaration without assigning a value to it, the variable will contain an undefined (garbage) value. In C and C++, this is referred to as Undefined Behavior. C and C++ do not initialize variables by default (e.g., with zero). And this can lead to unpredictable behavior, as the value of an uninitialized variable is dependent on the initial state of the memory location allocated for that variable. Accessing and using the value of an uninitialized variable can result in unexpected or erroneous outputs in your program. It is always recommended to initialize variables with appropriate values before using them to ensure predictable and reliable behavior in your code.

## Initialization

Programmers are a lazy bunch, so to avoid having to declare a variable first and then assign a value to it (and to minimize errors in the process), they came up with the following idea: let's assign a value to the variable right at the moment of declaration, thus performing variable initialization. In C++, there are several ways to initialize variables:

1. Copy Initialization: You can initialize a variable using the `=` operator, followed by the value you want to assign. For example: `int x = 10;`

2. Direct Initialization: You can use parentheses `()` to directly initialize a variable. For example: `int y(5);`

3. Uniform Initialization: C++11 standard introduced uniform initialization, which allows you to initialize variables using braces `{}`. For example: `int z{7};`


The key advantage of uniform initialization is that it provides a consistent syntax for initializing different types of objects, including built-in types, user-defined types (classes), and arrays. It also supports initialization of complex objects, such as containers or nested structures, in a more intuitive way. You'll learn more about this in the following topics.

These methods of initialization help ensure that variables have meaningful values from the start, reducing the chances of errors caused by uninitialized variables.

This is only a part of the language capabilities (and there is no "correct" way of initialization). However, you can follow these recommendations:

- If you have an initial value for a variable, use initialization instead of assignment.

- For simple (fundamental) types, use copy initialization, as it is a syntax commonly used in most programming languages, and it is the simplest option.

- For everything else, uniform initialization is preferable.


## Multiple declaration of variables

In a single statement, you can declare multiple variables of the same data type by separating their names with commas. For example, the following two code snippets accomplish the same thing:

```cpp
int x = 100;
int y = 66;

int c(12);
int p(32);

int e{97};
int f{150};
```

```cpp
int x = 100, y = 66;
int c(12), p(32);
int e{97}, f{150};
```

## Constants

One important feature of variables is that they can be changed. You don't need to declare a variable again to change its value, just assign a new value to it using the `=` operator.

However, sometimes it is useful to use variables whose values cannot be changed – constants. To make a variable constant, use the keyword `const` before or after the variable type. Constants must be initialized at the time of declaration. It is not possible to change their values using the assignment operation. For example:

```cpp
const float pi = 3.1415; //proper initialization of a constant
pi = 3.15; //not allowed - compilation error.
const double grav; //compilation error, the constant must be initialized.
```