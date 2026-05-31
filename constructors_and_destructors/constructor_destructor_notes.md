In C++, **constructors** and **destructors** are special member functions of a class that you use to initialize and destroy objects, respectively. They are essential in managing resources, enhancing code maintainability, and encapsulating code. Constructors are called at the beginning of object creation, and destructors are called at the end of the object's life.

## Understanding constructors

When all class members are public, you can initialize the class directly, just like you did with structures (they are identical in this regard). You can use uniform initialization:

```cpp
#include <iostream>

class Dog {
public:
    std::string name;
    int age;
    int weight;

    void print() {
        std::cout << "My name is " << name;
        std::cout << ", I'm " << age;
        std::cout << " years old and my weight: " << weight;
        std::cout << " kg" << std::endl;
    }
};

int main() {
    Dog bars { "Barsic", 11, 25};  // initialize the class

    bars.print();
    return 0;
}
```

But you don't want to keep all variables public. It's better to place them in the `private` or `protected` section. If you do this, you won't be able to initialize them directly. The logic is simple: if a variable is private, you cannot directly access it and should not have the ability to initialize it directly.

One option is to create a setter and getter for each attribute, which can significantly complicate the program and unnecessarily increase the code volume. So, how do you initialize a class with private member variables? You use **constructors**.

A **constructor** is a special method of a class that is automatically called when an object of that class is created. Constructors are used for:

- Initializing class member variables with default values or values provided by the user.
- Performing any preliminary setup steps necessary for the class being used, such as opening a specific file or database.

Unlike regular methods, constructors have specific naming rules:

- Constructors must always have the same name as the class (case sensitivity matters).
- Constructors do not have a return type, not even `void`.

⚠️ Constructors should typically be placed in the public section (there are cases where a constructor can be made private, but this is a highly specialized use case).

Let's modernize our `Dog` class:

```cpp
#include <iostream>

class Dog {
private:
    std::string m_name;
    int m_age;
    int m_weight;

public:
    Dog() {  // Here we create our constructor (name like the class)
        m_name = "Barsic";  // Set default values
        m_age = 11;
        m_weight = 25;
    }

    void print() {
        std::cout << "My name is " << m_name;
        std::cout << ", I'm " << m_age;
        std::cout << " years old and my weight: " << m_weight;
        std::cout << " kg" << std::endl;
    }

};

int main(){
    Dog bars; // initialize the class
    bars.print();

    return 0;
}
```

You created a `Dog` constructor, in which you assigned some values to private variables:

```cpp
Dog(){
    m_name = "Barsic";
    m_age = 11;
    m_weight = 25;
}
```

Now, when you create an object in the main function (`Dog bars;`), the constructor is automatically called, executing all the code within it. You can easily verify this by placing a print statement inside the constructor:

```cpp
Dog(){
    std::cout << "I am a constructor and I was called by default." << std::endl;
}
```

As a result, you will receive the following in the console:

```cpp
I am a constructor and I was called by default.
My name is Barsic, I'm 11 years old and my weight: 25 kg
```

## Constructor types

There are three types of constructors in C++: default constructor, parameterized constructor, and copy constructor.

- A **default constructor** is a constructor that doesn't take any arguments.

```cpp
class Car {
public:
    Car() { // default constructor
        std::cout << "Car created!" << std::endl;
    }
};
```

- A **parameterized constructor** is a constructor that takes arguments to initialize an object.

```cpp
class Car {
public:
    Car(std::string b) { // parameterized constructor
        m_brand = b;
        std::cout << "Car " << m_brand << " created!" << std::endl;
    }
private:
    std::string m_brand;
};
```

How to use a constructor with parameters? It's simple! Direct initialization:

```cpp
Car car("BMW"); //As a result, we get Car BMW created!
```

- A **copy constructor** is a constructor that creates an object by initializing it with another object of the same class, which is passed as an argument (essentially creating a copy of the object).

```cpp
class Car {
public:
    Car(const Car &obj) { // copy constructor
        m_brand = obj.m_brand;
        std::cout << "Car " << m_brand << " copied!\\\\n";
    }
private:
    std::string m_brand;
};
```

Please note that you are passing a constant reference to the object to the constructor (`Car(const Car &obj)`). `const` in order to protect the transferred object from changes.

## Multiple constructors

If you need, you can make several constructors:

```cpp
#include <iostream>

class Car {
public:
    Car() { // default constructor
        std::cout << "Car created!" << std::endl;
    }

    Car(std::string b) { // parameterized constructor
        m_brand = b;
        std::cout << "Car " << m_brand << " created!" << std::endl;
    }

    Car(const Car &obj) { // copy constructor
        m_brand = obj.m_brand;
        std::cout << "Car " << m_brand << " copied!\n";
    }

private:
    std::string m_brand;
};

int main(){
    Car bmw;

    Car gm("Buick");

    Car copyGM(gm);

    return 0;
}
```

The result of your code will be:

```no-highlight
Car created!
Car Buick created!
Car Buick copied!
```

Please note that now you have three constructors:

- The default constructor will be called if you do not provide any values.
- The parameterized constructor will be called if you provide brand values.
- The copy constructor will be called if you pass an object of our type.

Thanks to function overloading, these three constructors can coexist peacefully in the same class. In fact, you can define any number of constructors as long as they have unique parameters (considering both their quantity and type).

⚠️ If our class doesn't have constructors, the C++ language compiler will automatically generate a public default constructor for our class. This is sometimes referred to as an **implicit constructor** or an **implicitly generated constructor**. At this stage, it's not the most critical information, but keep in mind that every class has a constructor, even if you didn't explicitly define one.

## Understanding destructors

A **destructor** is a special member function of a class executed whenever an object of its class goes out of scope or when the `delete` expression is applied to a pointer to the object of that class. A destructor will have the exact same name as the class prefixed with a tilde (~), and it can neither return a value nor can it take any parameters.

```cpp
class Car {
public:
    Car(){
        std::cout << "Car created!\n";

    }
    ~Car() { // destructor
        std::cout << "Car destroyed!\n";
    }
};

int main(){
    Car car;

    std::cout << "And here is the end of the main() function\n";
    return 0;
}
```

The result of our code:

```no-highlight
Car created!
And here is the end of the main() function
Car destroyed!
```

Please note that the constructor is executed at the very end (in fact, even after the `return 0`).

Destructors are called in the following situations:

- When an object goes out of scope. This happens when an object is declared inside a block, and the block ends. For example, in the body of a loop or function.
- When an object is explicitly deleted. This happens when the `delete` operator is called on an object.

Here's what you can use destructors for:

- Free the memory that was allocated to the heap. If you have allocated space in the heap, then you need to take care of cleaning up the memory yourself.
- Close the file that was opened.
- Free any resources that the object has acquired. This could be specific hardware, input/output sources, and so on.