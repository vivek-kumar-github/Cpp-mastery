All programs perform some kind of computation, and computations are meaningless without data. Therefore, almost all programs receive input data and/or produce output results. Input and output operations are essential for creating interactive and functional programs. They allow programs to communicate with users, read data from external sources, and display information to the user.

Effective input/output handling is crucial in many real-world scenarios, such as reading user input, processing files, and interacting with databases. Understanding the principles and techniques of I/O in C++ will empower you to create dynamic and interactive applications.

## What is input-output for?

Input information can come from an "infinite" number of devices:

- from keyboards, mouse, touchscreens, and other input devices;

- from files;

- from audio equipment: remote controls, microphones, and so on;

- from photo and video devices;

- from various sensors: temperature, pressure, position, thermal imaging, etc.;

- from other programs;

- from other parts of the same program.


Similarly, results can be output to various devices:

- to the screen;

- to a file;

- to a network connection;

- to other output devices (music synthesizers, electric motors, light bulbs and LEDs, heaters, and others);

- to other programs or parts of a program.


If we disregard this fact, our programs will be severely limited. If we had to directly access different input/output devices each time we needed to switch, we would have to rewrite a part of the program. Clearly, this is absurd. Therefore, it is best to separate the methods by which a program reads and writes data from the actual input and output devices.

Most modern operating systems delegate the management of input/output devices to specialized drivers, and then programs interact with them through input/output library facilities, which provide a uniform interface to various sources and data destinations.

![Block diagram of Input/Output flows in C++](https://ucarecdn.com/2814802c-f8f9-401e-a046-e80ff3ac85cc/)

In this case, our work as application developers boils down to the following:

1. Configure input/output streams to receive/send data from/to devices.

2. Read from and write to the streams (with all the internal implementation details handled by the input/output library and device drivers).


In this topic, we will explore the basics of input and output in C++.

## Input & output (to/from console)

First, let's include our I/O library: `#include <iostream>`

The `iostream` library in C++ provides a set of classes and functions that allow you to perform input and output operations. It is an essential part of the C++ Standard Library. It offers convenient and flexible ways to interact with the user, read input from various sources, and display output.

The `iostream` library includes the following objects:

1. `cout`: This is an object of type `ostream` used for outputting data to the console. It provides methods for outputting data, such as the operator `<<`, which allows you to write data of different types (integers, strings, characters, etc.) to the console. We have already used this method:


```cpp
cout << "Hello, World!";
```

2. `cin`: This is an object of type `istream` used for inputting data from the console. It provides methods for reading data, such as the operator `>>`, which allows you to read data of various types from the console. When receiving data from the console, you need to store them somewhere, and for that, we will use a variable (don't worry, you will soon get acquainted with them in more detail 😁).


```cpp
int age; //This is a variable, we will discuss it in detail in the following topics.
cout << "Enter your age: ";
cin >> age;
```


Why do we use `cout/cin` here, but in the topic about the first program, we used `std::cout and std::cin`? The reason is that in C++, `std::cout` is used to indicate that `cout` is part of the std **namespace**. So, what is this creature called a **namespace**? It is simply a convenient level of abstraction, a collection of names (functions, classes, variables, etc.) provided by the C++ Standard Library. Using the `std::` prefix is a good practice to ensure clarity and avoid potential naming conflicts, especially when multiple libraries are involved in a project. It helps differentiate standard library components from user-defined components or components from other namespaces. We can explicitly specify that we are using the std namespace.

But If the project is small or you don't have external libraries, you can proceed exactly like that, (just be attentive and careful):

```cpp
#include <iostream>
using namespace std;
```

In this case, our example becomes:

```cpp
#include <iostream>
using namespace std;

int main(){ //the main entry point
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age = " << age << endl;

    return 0; //don't forget about return and of course about ";"
}
```

What happens in line 8? First, you send the text **_"_** _Your age =_ **_"_** to `cout`, and then you send the value stored in the variable `age` to `cout` as well. Finally, output a new line using `endl` (the `<<` operator allows us to sequentially send any data to `cout`).

Now you can compile and run your program. It will ask you to enter your age, and after you input a number, it will store it in the variable "age" and display its contents in the console. But what if you enter a text? In that case, the program is likely to terminate with errors. It all comes down to data types (which we will discuss in the following topics). Here, there is no type checking during input, and incorrect input can lead to unexpected behavior.

## Working with files

We mentioned that streams are convenient because they allow us to unify working with different input and output sources. Yes, that's correct. Below is an example of working with files using streams (the code may seem complex, but we will definitely break it down in detail over time).

```cpp
//In this example, we are writing text data to a file
#include <iostream>
#include <fstream>

int main() {

    std::string filename = "text_file.txt";  // The name of the file
    std::string text = "Hello World!!!";  //Here we will store the information

    // creating a file stream and writing text to a file
    //the if operator is used here, we will definitely study it later
    std::ofstream file(filename); //create a file stream, now we can send data to a file
    if (!file){
        std::cout << "Failed to open file for writing." << std::endl;
        return 1;
    }
    file << text; //just like that we send our text to a file
    std::cout << "The text was successfully written to the file." << std::endl;

    return 0;
}
```

This is how you can write text data to the file. If you now find _text\_file.txt_, you will see our `Hello World!!!` text. Below is an example of how you can read data from a file (but edit the text in the file first):

```cpp
// Reading text from a file
#include <iostream>
#include <fstream>

int main() {
    std::string filename = "text_file.txt";  // The name of the file
    std::ifstream file(filename);
    if (!file){
        std::cout << "Failed to open file for reading." << std::endl;
        return 1;
    }
    std::string word;
    //because we can only read 1 word at a time, use a loop
    while (file >> word) { //send each word from the file to the stream
        std::cout << word << " "; // Outputting each word from the file to the console
    }

    return 0;
}
```

These examples may seem complex, but the key point is that the input/output operations to the console (`cout << "text"`) and file (`file << text`) are unified thanks to streams.

## << or >> What, where, and from where?

Beginners often confuse `std::cin` with `std::cout` and `<<` with `>>`. Here's a simple way to remember their difference: Imagine that the real-world objects (console, sensors, files) are located in your left hand. To send data to them, use `cout <<`, and to receive data from them, use `cin >>`. Below are illustrations that visually demonstrate this.

![cout - block diagram of the flow output direction.](https://ucarecdn.com/4552c329-9925-4895-a0e1-08d57138ad53/)

![cin - block diagram of the flow input direction.](https://ucarecdn.com/0c391c42-1c36-4f92-aa10-7d08f56e4cef/)