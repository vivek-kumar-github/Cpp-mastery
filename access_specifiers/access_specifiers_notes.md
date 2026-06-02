Access specifiers in C++ are effective tools that help us manage how different parts of our code interact with each other. They are foundational to the concept of **Object Oriented Programming (OOP)**, a common programming paradigm that organizes code into `objects` to make it more understandable and manageable.

Access specifiers control what parts of our code can use or modify the data within these objects. This is crucial when building complex software systems, as it ensures that each part of our code only has access to the data and functionality it needs to perform its job. This makes our code more secure and robust by preventing unwanted side effects and making it easier to understand and maintain, as each object can be understood in isolation.

## Access specifiers

Let's create a structure and a class with similar functionality. The only difference will be in the `public` keyword.

```c++
#include <iostream>

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

int main(){
    DateStruct yesterday {05, 05, 2023}; // initialize the structure
    DateClass today {06, 05, 2023}; // initialize the class

    yesterday.day = 18;
    today.day = 19;

    return 0;
}
```

In this example, in the main function, we initialized the `yesterday` structure and the `today` object. We also changed the `day` variables in our "data stores." You might wonder: "What is the purpose of the `public` keyword, and what is it?" `public` is one of the three **Access specifiers.**

**Access specifiers** determine how you can access a class's members (attributes and methods). C++ has three types of access specifiers: `public`, `private`, and `protected`.

- `public`: members are accessible from outside the class.

- `private`: members cannot be accessed (or viewed) outside the class. Classes use this by default: the compiler will assume private if you don't specify any access level.

- `protected`: members are accessible within the same class and in classes inherited from it.


Let's take a closer look at each specifier.

## Public access specifier

The **public** access specifier allows class members to be accessible from any function, whether it resides inside or outside of the class. When a member is declared as public, it can be accessed directly using the `dot operator (.)` on the object. This applies to variables and functions (methods). Let's look at an example:

```c++
#include <iostream>

class Car {
public:
    int speed;

    void printSpeed(){
        std::cout << "your speed is: " << speed << " km/h";
    }
};

int main() {
    Car myCar;
    myCar.speed = 120; // Directly accessible
    myCar.printSpeed();
    return 0;
}
```

The result of our program's execution:

```no-highlight
your speed is: 120 km/h
```

First, describe the `Car` class, with a public variable (`speed`) and a method (`printSpeed()`). Next, in the main function, create an object of type `Car` with the name `myCar.` Because in the above example, `speed` is a public member of the `Car` class, and hence, it can be accessed directly in the `main()` function (or anywhere else in the code).

## Private access specifier

On the other hand, if you don't want this behavior, you can use the **private** access specifier, which restricts the accessibility of the members. A private member is only accessible from within the methods of the same class. The following example will throw an error:

```c++
#include <iostream>

class Car {
private:
    int speed;
};

int main() {
    Car myCar;
    myCar.speed = 120; // Error: 'speed' is private within this context
    return 0;
}
```

In this case, `speed` is a private member of the `Car` class. Thus, accessing it directly from the `main()` function will result in a compile-time error.

But how can you access if the variable is hidden? We can use special, public member functions known as getters and setters. These provide a controlled way of interacting with the internal state of an object, adhering to the principles of encapsulation in object-oriented programming. A getter function retrieves the value of a private member, while a setter function updates it. This allows you to include validation logic to ensure the object's state remains consistent. Using these functions, you can enforce data integrity and maintain flexibility to change internal implementations without affecting external code that interacts with the class.

Let's modify out example:

```c++
#include <iostream>

class Car {
private:
    int m_speed;

    double convertKmh2Mph(){
        return m_speed/1.61;
    }

public:
    void setSpeed(int new_speed){
        m_speed = new_speed;
    }

    void printSpeed(){
        std::cout << "Your speed is: " << m_speed << std::endl;
    }

    void printSpeedInMph(){
        std::cout << "Your speed in mph is: " << convertKmh2Mph();
    }
};

int main() {
    Car myCar;
    myCar.setSpeed(120);

    myCar.printSpeed();
    myCar.printSpeedInMph();
    return 0;
}
```

Here, we made several important changes:

- We renamed the variable to `m_speed` (this is a recommended improvement). It's simply a matter of good practice. In this way, other developers will know that it's a class member;

- We created a setter: `void setSpeed(int new_speed)`, located under the `public` modifier, meaning it's accessible from any part of the program (just like `printSpeedInMph()`). This method takes an integer variable and internally modifies our private variable `m_speed`. We set our speed in the main function with `myCar.setSpeed(120);`;

- We created a getter: `printSpeed();`. It prints our private variable `m_speed` to which it has access since it belongs to our class.

- The most complex example is calling `myCar.printSpeedInMph();`. When calling this function, no errors will occur because it is also located in the `public` section. It, in turn, calls the `convertKmh2Mph()` method, which is located in the `private` section. This method accesses the private variable `m_speed` and returns the processed result (speed in miles per hour).


The result of our program's execution:

```no-highlight
your speed is: 120
your speed in mph is: 74.5342
```

So, you can access private attributes (`m_speed`) and methods (`convertKmh2Mph()`) of the class only from other methods of that class. If you want to access them from the outside, you need to create so-called "wrappers" (`setSpeed()`, `printSpeed()`, and `printSpeedInMph()`), which we will discuss in detail later. This is a very good tool that you should definitely use.

## Protected access specifier

The `protected` modifier is very similar to `private`. When a class member is declared with the `protected` access modifier, it becomes accessible to all methods inside the class and methods in derived classes. However, objects of the class or other non-derived classes do not have direct access to protected members.

We will discuss this modifier in more detail a bit later, as you first need to delve into the concept of [**inheritance**](https://hyperskill.org/university/cpp/cpp-inheritance). Just remember that it is very similar to `private`.

## Tips

Here are some practical tips (they are advisory in nature but can simplify the life of a programmer):

1. It's better to make all class variables private (it's best to hide all information from the outside world). This provides additional protection, similar to local scope.

2. When you hide all the information and utility methods in the `private` section, it's a good practice to create getters and setters, an API for our classes.

3. It's a good idea to add the `m_` prefix to class attributes (variables) to indicate that they are internal variables, not global ones.

4. When describing classes, a large amount of code is generated, making it difficult to navigate over time. Be sure to document your code (methods, and so on). Even better, learn how to create comments in your Integrated Development Environment (IDE) that will automatically appear in the system's tooltips in the future. In such cases, you will be able to generate documentation later automatically.

## Accessibility Matrix

| Access Specifier | Accessible inside the same class? | Accessible inside a Child Class? | Accessible from outside code (e.g., `main`)? |
| :--- | :---: | :---: | :---: |
| **`public`** | Yes | Yes | Yes |
| **`protected`** | Yes | Yes | No |
| **`private`** | Yes | No | No |