In this topic, you will learn how to write a simple C++ program. We will cover the basic structure of C++ programs, including the main function, file organization, and the use of comments. By the end, you will understand the fundamental elements required to start writing C++ code.

## Hello World

We will start by creating a simple program that prints "Hello, World!" to the console. This program will demonstrate the basic syntax and structure of a C++ program.

In C++, the main() function acts as the starting point for program execution. When you run a program, it is the first function that the program calls and begins executing from. The main function sequentially executes code, allowing you to write your program's initial instructions and logic.

This is a completely self-contained program in C++. If you have an installed and configured integrated development environment (IDE) or a compiler, you can build and run this program (or share it with your friends). When executed, the program will print "Hello, World" to the console.

```cpp
#include <iostream>

// This is a single comment about our main function.
// Our function prints text to the console.
int main() {
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

Consider this text as a set of commands that the computer should execute, similar to a culinary recipe or instructions for assembling a new toy or furniture. Below, after the terminology, we will look at what each line of the program does, starting from the very beginning.

## Basic terminology

Now that you have seen the result, let's learn some basic terminology and try to understand this program.

- **Literals** represent fixed values that are directly written into the code. There are different types of literals in C++:
  - integer literals (`42`, `0b1010` (binary), `0777` (octal), and `0xFF` (hexadecimal),
  - floating-point literals (`3.14`, `1.23e-5`, and `6.0`.),
  - character literals (`'A'`, `'x'`, and `'%'`),
  - string literals (`"Hello, world!"`, `"C++"`, and `"123"`),
  - boolean literals (`true` and `false`);
- **Statement** – a single action (like printing a text) terminated by a semicolon (`;`). In programming, a statement is equivalent to a 'sentence' in English. We write sentences to express an idea; in C++, we write statements to perform a task. For example (output statement):


```cpp
std::cout << "It's output statement";
```

- **Program** – a sequence of instructions (statements) that are predictably executed one after another.

- **Expression** – a mathematical object that is constructed to perform calculations and obtain a corresponding result. For example, `(2 + 6) * (m - 3)`. Each expression has its own meaning and can be evaluated to produce a result.

- **Function** is a sequence of statements. Every program in the C++ language must contain a main() function. The execution of the entire program starts from the first statement inside the main() function. Functions typically perform a specific task. Each function is enclosed within a **block**.

- **Block** – a group of zero, one, or more statements enclosed by a pair of braces `{...}`; There is one such block in the program above.

- **Syntax** – a set of rules that define how to write a program for it to be valid;

- **Keyword** – a word that has a special meaning in the programming language (`include`, `return`, and many others). You cannot use these words as variable names for your own program;

- **Identifier or name** – a word that refers to something in a program (such as a variable or a function name);

- A **library** is a collection of compiled code (such as functions) "packaged" for reuse in other programs. You can use libraries to extend the capabilities of programs.

- **Comment** – a textual explanation of what the code does. C++ comments start with `//` or `/* … */`. You can write comments to add explanatory notes to the code. The compiler does not execute them. They serve as documentation for the programmers. C++ supports both single-line and multi-line comments. Single-line comments:


```cpp
// This is a single-line comment
// New single-line comment
// One more comment
```


Multi-line comments:


```cpp
/* This is a multi-line comment
all these lines are ignored
and of course this one too
and even this */
```


## Microscopic view of the Hello World program

Let's go back to our first program and look at it in more detail.

```cpp
#include <iostream>

// This is a single comment about our main function.
// Our function prints text to the console.
int main() {
    std::cout << "Hello, World" << std::endl;

    return 0;
}
```

- In line 1, we use a special type of instruction called a **preprocessor directive**. Preprocessor directives instruct the compiler to perform a specific task. In this case, we are telling the compiler that we want to include the contents of the **iostream** library header file (the name is derived from Input/Output Stream) in our program. In C++ (and C), there is no built-in input-output support; instead, we use a library of functions.

- Lines 3 and 4 contain single-line comments.

- In line 5, we declare our `main` function and specify the scope of the main function to the compiler. Everything between the opening curly brace `{` in line 5 and the closing curly brace `}` in line 8 is considered the content of the main function.

- Line 6 is our first statement (ending with a semicolon) – an output statement. Let's see what it consists of:


  - `std::cout` \- a special object that allows us to output data to the screen.
  - `<<` \- the output direction (and stream insertion) operator. Anything we send to `std::cout` is displayed on the screen. In this case, we are outputting the text `"Hello, World"`.
  - `std::endl` \- the line break operator. Alternatively, we can use `\n`, so the statement would look like:

    `std::cout << "Hello, World\n";`
  - And, of course, we shouldn't forget about `;`. It may seem like a relic, but it's important not to ignore it.

If something is unclear to you at this stage, don't worry (almost everyone has been through it), we will explain and show everything in detail later.

- Line 7 is the **return statement**. We will not go into details; just remember that if everything is fine, we use `return 0;`.


## Structure of C++ programs

C++ programs can be organized in different ways, and understanding how to structure your code is essential for maintaining clarity and modularity.

It is possible to put everything into a single file, but as the project grows, confusion is bound to arise, and it won't be easy to navigate (especially if you pass your code to someone else, like yourself, in a couple of months). Therefore, when working on a C++ project, it is common to have multiple files that contain different parts of the program. This allows for better organization, code reuse, and easier collaboration. A typical C++ project may consist of header files (.h or .hpp) and source files (.cpp).

By following a structured approach with header and source files, we can create well-organized and maintainable C++ projects.