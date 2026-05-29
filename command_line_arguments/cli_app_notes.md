## Getting started with CLI in C++

**Command Line Interface (CLI)** is a simple text-based interface that lets users interact with software by typing commands and receiving textual responses. CLI programs are often used for system administration, automation, and development tasks. If you've ever used a console or terminal, then you're likely familiar with what a CLI is.

You have been using CLI extensively while using `std::cin` and `std::cout`. Let's revisit the options for inputting and outputting information via the command line, or terminal:

```cpp
#include <iostream>

int main() {
    std::cout << "Enter any integer: " << std::endl;
    int num;
    std::cin >> num;
    std::cout << "The square of this number is:" << num*num << std::endl;

    return 0;
}
```

In this example, you output information to the console twice and also ask the user once to input information, specifically an integer.

But what if you want to construct a slightly more complicated program that allows users to enter different kinds of information? For example, you might want users to be able to input certain parameters when starting up our program. There are a couple of ways you could go about this:

- Build an **interactive menu** that lets the user choose some parameters;

- Utilize **command-line arguments** that you can pass to your main function and process accordingly.


Keep in mind, you're not limited to using just one of these options; you can combine them as needed.

## Interactive menu

Interactive CLI applications often need menus to direct users through various functionalities. You can create these menus using loops and switch statements to show options and respond to the user's choices.

```cpp
#include <iostream>

int main() {
    int choice;
    do {
        std::cout << "1. Option 1" << std::endl;
        std::cout << "2. Option 2" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "###################" << std::endl;

        switch (choice) {
            case 1:
                std::cout << "You have chosen option 1" << std::endl;
                break;
            case 2:
                std::cout << "You have chosen option 2" << std::endl;
                break;
            case 3:
                // Exiting the program through while
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
```

Take your time experimenting with this code in your IDE.

## Handling Command-Line Arguments

To handle command-line arguments in C++, you can read and use arguments passed to a program through the command line when it is run. Command-line arguments help to configure a program's behavior or pass information like file paths, configuration parameters, and other kinds of data.

Imagine that a friend asked you to write a program that counts words in a file. You created a program that takes the name of a file to process. You sent the program to your friend. But for your friend to use the program, they need to pass a parameter - the file name.

To do this, they can pass command-line arguments (such as data from the terminal that follows the program name being launched) to the main function for processing. In C++, the `argc` and `argv` parameters of the `main` function allow access to command-line arguments.

The `argc` parameter, short for "argument count", contains the number of arguments passed, including the program name. Then you have the `argv` parameter, short for "argument vector", which is an array of strings (`char*`) containing the arguments.

Here's a simple example:

```cpp
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Arguments count: " << argc << std::endl << std::endl;

    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

In this example, we're passing in two arguments to our main function: `int argc` and `char *argv[]`. After this, we display the number of parameters passed (the value of `argc`). Finally, we loop through all arguments received, which are stored in the `argv[]` array.

⚠️ The first argument (the value at index zero) will be the path to your program.

For command-line parameters to be processed smoothly and to configure the program's launch flexibly, you need to:

- Go to the console or terminal;

- Navigate to your working folder with the compiled program using `cd /your/work/folder` (compile the program if needed using the command `g++ myprogram.cpp -o myprogram`);

- From there, run the program with `./myprogram`


If you run the program without parameters, the result should look something like this:

```no-highlight
Argument 0: ./myprogram
```

The output shows that only one parameter was passed, namely the path (or name) of the program.

However, you can pass any number of arguments for future processing:

```no-highlight
./myprogram one two three
```

The result will then look something like this:

```no-highlight
Argument 0: ./myprogram
Argument 1: one
Argument 2: two
Argument 3: three
```

Generally, when passing key-value pair command-line arguments, flags are used. In such cases, these flags are usually prefixed with a single hyphen (-) or a double hyphen (--):

```no-highlight
./myprogram -flag1 value1 -flag2 value2 filename.txt
```

In this example, `myprogram` is the program's executable file, `-flag1` and `-flag2` are flags, and `value1`, `value2`, and `filename.txt` are arguments. Such entry is an instruction that our program should perform an action on the text file `filename.txt`. Usually, developers provide a documentation explaining what each `flag` means and what `values` can be used.

Once you have all the arguments, you can process them in your program. You may use `if/else` or `switch` statements. Additionally, C++ inherits an excellent library (`getopt.h`) and a set of functions from C for processing **Command Line Arguments (CLA)**.

## Processing of CLA

The `getopt` library simplifies the parsing of command-line options and arguments. It provides a standardized method to define and handle options, making your CLI application more user-friendly.

```cpp
#include <iostream>
#include <getopt.h>

int main(int argc, char *argv[]) {
  // Command Line Options
  char short_options[] = "hv";
  // Position of the current command line option
  int opt;

  // Looping through all command line parameters
  while ((opt = getopt(argc, argv, short_options)) != -1) {
    // Handling the current command line option
    switch (opt) {
      case 'h':
        std::cout << "Usage: myprogram [options]\n\n"
                  << "Options:\n"
                  << "  -h    Print this help message\n"
                  << "  -v    Print the version number\n";
        break;
      case 'v':
        std::cout << "myprogram v1.0.0\n";
        break;
    default:
        std::cout << "Unknown option. Use '-h' for usage information.\n";
        break;
    }
  }

  // Checking if command line parameters were passed
  if (argc == 1) {
    std::cout << "Use '-h' for usage information.\n";
  }

  return 0;
}
```

The function `getopt(argc, argv, short_options)` runs through the command line options, comparing them with the list stored in `short_options`. If it finds nothing, it returns `-1`. If the value isn't `-1`, then it checks the command (or `opt`) using a `switch` operator.