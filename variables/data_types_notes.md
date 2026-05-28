The goal of almost any real program is to transform data from one form to another. To read data, you need a place in the computer's memory where you can input information and store it.

## Where do variables live?

Computer memory can be thought of as a large shelf, where each section (cell) can hold 1 byte of information (and each cell has its own unique address). However, we can remove any divider in a section and obtain a free cell of the desired size. This is where an **object** comes into play.

![Visualization of RAM (rack with modular shelves)](https://ucarecdn.com/f708e40d-636f-44c3-816b-69d1b6d097c3/)

An **object** is a portion of the computer's **random access** memory that stores a value (some information) of a specific type. An object can be thought of as a "box" where we can place a value of the object's type (for example, it could be not just a box, but a container for sorting garbage: glass, plastic, paper, etc.). When an object is created, a portion of the memory is allocated for that object. Most of the objects you will work with in the C++ language are variables.

A **variable** is a named object (for convenience, we can give this object a name, and thus we obtain a variable).

## Basic data types

In C++, an object stores information of a specific type (which is why each variable requires its own type). You might wonder why such complexity is necessary, and why not use a single data type for everything? The answer is that using object types allows the compiler to efficiently manage memory allocation for objects and optimize their usage. The compiler knows the size and structure of each object type, enabling it to effectively allocate, deallocate, and manage memory resources. Types are fundamental to any program: They tell us what our data mean and what operations we can perform on those data.

If we imagine an object as a garbage container, then the type of the container determines what kind of garbage we can put in it and what it signifies (organic, glass, metal). The type also signifies how we will process our garbage (metal is processed one way, glass is processed differently, and paper is handled in some other way). And the compiler watches over us to ensure that we don't attempt to melt paper or organic waste.

C++ has extensive support for types. The language defines several primitive types (characters, integers, floating-point numbers, etc.) and provides mechanisms that let us define our own data types. We or other developers (for example, when creating additional libraries) can use these mechanisms to define more complicated types such as vectors, strings, and so on.

Below is a chart and table of basic data types that we will encounter and work with in this course (in reality, there are many more data types in C++).

![Block diagram of the most used data types in C++.](https://ucarecdn.com/937d6703-bfdd-44d4-9ab1-a865f9644b61/)

The table provides a summary of the main data types in C++ that we will encounter.

| Data Type | Meaning | Size (byte) | Range | Value | Example |
| --- | --- | --- | --- | --- | --- |
| Boolean | Represents a logical value | 1 | true or false | true or false | bool isTrue = true; |
| Character | Represents a single character | 1 | -128 to 127 or 0 to 255 | Any single character | char letter = 'A'; |
| Integer | Represents whole numbers | 4 | Depends on the size | Any whole number | int number = 42; |
| Floating-point (Double) | Represents decimal numbers with double precision | 8 | Depends on the value | Any decimal number | double pi = 3.14159; |
| String | Represents a sequence of characters | Depends on length | Any sequence of characters | Enclosed in double quotes | std::string message = "Hello, World!"; |
| Vector | Represents a dynamic array | Depends on size | Any sequence of elements | Collection of elements | std::vector<int> numbers = {1, 2, 3, 4, 5}; |
| Void | Represents absence of a value |  |  |  | void printMessage(); |

## Void, what kind of animal is this?

The `void` data type in C++ represents the absence of a specific type. There are two main uses for the void type (we will learn more in the following topics):

- The `void` type is used in function declarations to indicate that the function does not return a value. For example, a function with a return type of `void` would be declared as follows: `void myFunction()`. This is useful for functions that perform actions or have side effects without producing a result.

- In addition, `void` can be used to declare pointers that do not point to a specific type. These pointers are often used in generic programming or as placeholders when the actual type is not known or relevant.


Pointers and functions are discussed in detail in subsequent topics.

It's important to note that variables of type `void` cannot be created, and `void` cannot be used as a data type for variables or objects. Its primary purpose is to indicate the absence of a specific type or to specify that a function does not return a value.

## First look at variables

Data types are closely related to variables. For now, let's take a quick look at variables.

As we mentioned earlier, a variable is an object with a name. Before we can start using a variable, we need to create it in some way. To do that, we can declare a variable (allocate memory for the object):

```cpp
bool ourBoolVariable;   //declare a boolean variable
int ourIntVariable;     // declare an integer variable
float ourFloatVariable; // declare a floating point variable
char ourCharVariable;   //declare a character variable

//this code will not work because "void" cannot be used as a variable type.
void ourVoidVariable;
```

What happens after we declare a variable? Upon declaring a variable, the compiler comes into play. It allocates a corresponding block in the computer's memory, which will be used to store the values of that variable during program execution. Later, when the program is running, the processor takes over, executing the compiled code and manipulating the data stored in the allocated memory.

For example, let's assume that the variable `ourVariable` is assigned the memory cell with the address `0x30893da94`. During program execution, when the variable name `ourVariable` is encountered, the processor knows to look into the memory cell with the address `0x30893da94`.

In other words, we have attached a label with the variable's name to our shelf, and from now on, we will work with that label.