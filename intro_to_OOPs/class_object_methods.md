C++ provides a range of fundamental data types (such as char, int, double, and others) that are sufficient for solving most relatively simple tasks. If you happen to need more, you can define your own data types that better suit the specific problems you're solving. For example, you can use structures to create your own user-defined data types. However, for solving complex problems, the functionality of these simple types may not be sufficient. C++ provides you with another tool for creating user-defined data types: classes.

## Blueprint OOP - Classes

To store specific or complex data, you can use structures, for example:

```cpp
#include <iostream>

struct DateStruct{
    int day;
    int month;
    int year;
};

void print(DateStruct &date){
    std::cout << date.year << "-" << date.month << "-" << date.day;
}

int main(){
    DateStruct today {05, 05, 2023}; // initialize the structure

    today.day = 18; // use the member selection operator
    today.month = 2;
    today.year = 2024;

    print(today);

    return 0;
}
```

Structures are not part of OOP. Here we defined a structure to store a date, initialized it, and used it to display information. You can perform actions on structures or the data stored within them through functions. However, functions are stored separately, so what if you suddenly want to display the date in a different format? And what if you have another structure called `employee` and a function `print` that displays their name and age? In such cases, OOP comes to our aid.

In object-oriented programming, user-defined data types can contain not only data but also functions that operate on that data. To organize this, you need to define a **user-defined data type** \- a **class**. C++ provides a special keyword **class** for this purpose (who would have guessed? 😆).

In C++, classes are very similar to structures, except that they provide much greater power and flexibility. In fact, the following structure and class are functionally identical:

```cpp
struct DateStruct{
    int day;
    int month;
    int year;
};

class DateClass{
public:
    int day;
    int month;
    int year;
};
```

The only difference is the presence of the keyword `public:`, which you will discuss soon. Declaring a structure does not allocate any memory (it is just a description of an entity), and the same applies to classes. However, in order to use a class, you need to initialize a variable of that type (since a class is a user-defined data type).

## Objects

In the terminology of the C++ language, a `class` is like a blueprint or a recipe. It defines a type of data, including the data's properties (like color, size, and others) and what operations can be performed on that data (like change color, resize, and so on). An `object`, on the other hand, is an **instance** of that class, just like a house built from a blueprint or a cake baked from a recipe:

```cpp
class Employee {
public:
    std::string name;
    int id;
    double salary;
};

class DateClass {
public:
    int day;
    int month;
    int year;
};
```

So if you have a class called `Employee` or `DateClass`, you can create an object of that class like `mark` or `today` and set its properties or perform operations on it (but if you don't want to, you don't have to initialize the object at all):

```cpp
Employee mark;  // Create an object of Employee class
DateClass today { 11, 11, 2011 }; // initialize the class variable DateClass
```

In this example, `DateClass` is the user data type and `today` is the variable name (object or instance name).

Just as defining a variable of a fundamental data type, such as `int num`) allocates memory for that variable, so creating an object of a class (such as `DateClass today`) allocates memory for that object. The `class` does not allocate memory. It is simply a description of future objects.

## Methods

“Alright, but so far, it doesn't differ much from structures, so why do we need classes?" The thing is, apart from storing data, classes can also contain functions to work with that data!

Functions belonging to a class are called **methods**. Methods can be defined both inside and outside the class. If a method is defined outside the class, a method prototype must be provided inside the class. Methods are used to implement the behaviors of an object. They can access and modify the attributes (variables) of a class.

Let's add two methods for displaying the date in different formats to our class:

```cpp
class DateClass{
public:
    int day;
    int month;
    int year;

    void printEU(){ // define a method (class member function)
        std::cout << day << "-" << month << "-" << year;
    }
    void printUS(){
        std::cout << year << "-" << month << "-" << day;
    }

};
```

In the same way, both struct members and class members (variables and functions) are accessed through the **member selection operator**`.`:

```cpp
int main(){
    DateClass today { 11, 11, 2011};

    today.day = 15;
    today.printEU();
    today.printUS();

    return 0;
}
```

The result of the program execution:

```no-highlight
15-11-2011
2011-11-15
```

Notice how this program is similar to the one using a structure that you saw earlier. However, there are a few differences. In the **`DateStruct`** version, you had to pass the structure variable directly to the **`print()`** function as a parameter. If you didn't do that, the **`print()`** function wouldn't know which **`DateStruct`** variable to print. You would then have to explicitly reference the structure members inside the function.

Class methods work slightly differently: you invoke a method on a specific object, implicitly passing its parameters. When you call **`today.printEU()`**, you are instructing the compiler to invoke the **`print()`** method of the **`today`** object.

You can also define a function outside the class. Let's rewrite our previous example:

```cpp
#include <iostream>

class DateClass{
public:
    int day;
    int month;
    int year;

    void printEU();
    void printUS();
};

    void DateClass::printEU(){
        std::cout << day << "-" << month << "-" << year;
    }
    void DateClass::printUS(){
        std::cout << year << "-" << month << "-" << day;
    }

int main(){
    DateClass today {11, 11, 2011};

    today.day = 15;
    today.printEU();
    today.printUS();

    return 0;
}
```

The result of the program execution:

```no-highlight
15-11-2011
2011-11-15
```

This syntax (`void DateClass::printEU()`) tells the compiler that the `printEU` and `printUS` functions belong to the `DateClass`. You can define their implementation outside the class body, as shown above, and the functions will still be associated with the DateClass class.

If you didn’t use the `DateClass::` construction, then it would not be clear what your methods refer to. Maybe these are generally simple functions.

For such a simple example, it may seem that it makes no sense to define methods outside the class, but if you have a large method and/or you have a lot of them, then the class definition will be simply unbearably large, and this will make the code more difficult to understand and maintain.

## Summary (cheatSheet)

- Typically, programmers write class names with capital letters to make it easier to identify them as classes.
- If you're trying to write a program to solve a problem or task, try looking at it from an object-oriented perspective. You'll likely find a solution quickly.
- Unlike regular functions, the order in which class methods are defined doesn't matter.
- Use the keyword `struct` for structures that are used solely for data storage. Use the keyword `class` for objects that combine both data and functions.
- The C++ standard library is full of classes created for our convenience. `std::string`, `std::vector`, and `std::array` are all class types! So, when you create an object of any of these types, you're creating an object of a class. And when you call a function using these objects, you're invoking a method of that class.