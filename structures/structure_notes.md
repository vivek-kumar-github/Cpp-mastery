You already know how to store individual data (variables) and collections of homogeneous data (arrays). But what if you want to store different types of data under one roof? That's where **structures** come into play in C++. Structures allow you to store heterogeneous types of data together, providing a unified container for them. They provide a way to organize related data elements and create more complex data structures.

## Why do you need structures?

Let's explore some of the key reasons why you need structures:

1. **Grouping Related Data:** Structures allow you to group related data together. For example, if you are working with a student record that consists of attributes like name, age, and grade, you can create a structure that encapsulates all these attributes into a single entity. This makes it easier to manage and manipulate related data as a cohesive unit.

2. **Creating User-Defined Data Types:** Structures enable you to define your own data types based on your specific requirements. By defining a structure, you can create a custom data type that holds a collection of different variables. This allows you to create meaningful abstractions and represent real-world entities in our programs.

3. **Passing Complex Data to Functions:** Structures provide a convenient way to pass complex data to functions. Instead of passing multiple individual parameters, you can pass a structure that encapsulates all the necessary data.


## Structure declaration

You need to inform the compiler about the structure's design (so to speak, provide a blueprint). For this purpose, use the keyword `struct` in C++. Followed by the structure name and a block of variables that define its members. Each member can have a different data type and represents a specific attribute of the structure.

```cpp
struct Person {
    std::string name;
    int age;
    float height;
};
```

In C++, the structure definition is a statement, and like any other statement, you need to terminate it with a semicolon.

Keep in mind that this requirement for a semicolon applies not only to structure definitions but to other statements as well:

\- such as variable declarations

\- function declarations

\- function calls.

Note that `;` after `}` is very important in the context of structures.

## Accessing structure members

To use the `Person` struct, you simply need to declare a variable of type `Person`. And after that, you can access structure members using the dot (`.`) operator.

An operator is a symbol or keyword used to perform specific operations on variables or values, such as addition or comparison. In C++, the **dot operator (.)** is used to access members (variables or functions) of an object or structure. Just remember this information: you don't need to focus on it right now as we will cover all operators in the next topics.

This allows you to retrieve or modify the values of individual members of a structure.

```cpp
Person mike;
mike.name = "Mike Wazowski";
mike.age = 45;
mike.height = 1.2;

Person james;
james.name = "James P. Sullivan";
james.age = 47;
james.height = 2.2;
```

## Struct initialization

You can initialize the structure by accessing each member individually (as in the example above) or:

```cpp
Person mike = { "Mike Wazowski", 45, 1.2 };
Person james = { "James P. Sullivan", 47};

//you can use C++11 uniform (see the topic about variables for more details)
Person mike { "Mike Wazowski", 45, 1.2 };
Person james { "James P. Sullivan", 47};
```

If one or more elements are not in the initializer list (like `james.height`), then they will be assigned default values (usually 0). In the example above, the `james.height` member is set to the default value of 0 because you didn't provide any value yourself during initialization.

You can also assign values at run time (such a possibility was added in C ++ 11):

```cpp
Person mike;
mike = { "Mike Wazowski", 45, 1.2 };
```

## Nested structures

You can nest structures within other structures, which allows you to create more complex data structures. This helps in organizing related data and maintaining a logical structure.

```cpp
struct Address {
    std::string street;
    std::string city;
    std::string country;
};

struct Employee {
    std::string name;
    int age;
    Address address;
};

struct Company {
    std::string name;
    Employee CEO;
    Address address;
};
```

Now you can work with information in a convenient, and, most importantly, structured and understandable way:

```cpp
Company comp;
comp.CEO.address.street; //getting street CEO
comp.address.street; //and this is the street where the company is located.
```

## Using structures in functions

Structures can be passed as function arguments or returned from functions. This allowed you to avoid passing each variable individually. Moreover, if you ever want to add new members to the `Person` structure, you don't have to modify the declaration or function call (we will introduce the concept of functions very soon, and we hope this example is fairly simple and understandable):

```cpp
#include <iostream>

struct Person {
    std::string name;
    int age;
    float height;
};

void printPersonInformation(Person person) {
    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Age: " << person.age << std::endl;
    std::cout << "Height: " << person.height << std::endl << std::endl;
}

int main()
{
    Person mike = { "Mike Wazowski", 45, 1.2 };
    Person james = { "James P. Sullivan", 47, 2.2};

    printPersonInformation(mike); // Display information about mike
    printPersonInformation(james); // Display information about james

    return 0;
}
```

We haven't covered functions in detail yet, but for the purpose of understanding the code, here's a brief explanation:

- A function is a distinct block of code enclosed in curly braces {} and assigned a name. It serves as a reusable unit of code, which is beneficial when you need to execute the same logic multiple times.

- In this code, we created a function named 'printPersonInformation.' Inside the function, we simply output data about the structure passed as an argument.

- In the main function, we call (use) the 'printPersonInformation' function multiple times (specifically, twice), passing different structures to it. This approach allows us to write the logic only once and then easily reuse it in the future.


You will delve into functions more comprehensively later on.

💡 Structures are very important in the C++ language because understanding them is the first big step towards object-oriented programming! A little later, you will explore another user-defined data type — classes (which are an extension of the structure topic).