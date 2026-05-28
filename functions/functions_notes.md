Functions are a fundamental concept in programming that allows you to encapsulate a block of code (some set of instructions that you or another programmer wrote) and execute it multiple times. They provide modularity, reusability, and improve the overall organization of your code. Now your code will move to a new level! In this topic, you will explore the key aspects of functions in C++.

## Functions – what are they?

As you have seen before, the `main()` function serves as the entry point of a C++ program. It is where the execution begins and ends. Within the `main()` function, you can write a series of statements that define the logic and operations of your program.

If you wish, you can write the entire program within the `main()` function. For small programs, this is usually done. However, if your program exceeds 20-30 lines of code (this is a very approximate measure), it's essential to consider organizing the code. Doing so simplifies development, especially when working collaboratively, improves code readability, and eases testing, debugging, and error detection. To achieve this, **functions** are used.

**Functions** in C++ are named blocks of code that you can call and execute at any point in the program. They allow you to break down complex tasks into smaller, manageable units, making the code more modular and easier to understand. You can use functions to perform specific actions, calculate values, or provide abstractions for repetitive tasks.

Think of a **function** as a small factory or tool that performs a specific task at your request. It has a name, for example (let's invent a fictional function), "makeCake()", and it knows how to bake a cake. Instead of baking a cake manually every time, you can simply call the "makeCake()" function and get your cake ready.

## Function composition

In C++, to work with functions, you need to follow several steps:

- Define the function: Describe its composition. This is a mandatory step where you specify how your function will operate.

- Call the function from your code (from the main function or another function). This is also a mandatory step since a function is like a "Chekhov's gun" (if you've created it, you should use it at least once).

- Declare the function (provide its prototype). This is an optional step, but in some situations, it's crucial.


Next, let's examine each step in detail and put everything in its place.

The **declaration**, also known as the function **prototype**, provides information about the function's name, return type, and parameters, without specifying the implementation details. The function definition includes the actual implementation of the code block.

Here is the function declaration syntax:

```cpp
return_type function_name(parameter_list);
```

`return_type` \- This specifies the data type of the value that the function will return after performing its task. For example, if the function performs a calculation and returns an integer result, the return type would be `int`. If the function doesn't return anything, the return type is specified as `void`.

`function_name` \- This is the name given to the function, which is used to call and identify the function when it is used in the program. It should be a meaningful name that reflects the purpose of the function. The rules for choosing a name are the same as for a variable.

`parameter_list` \- This is a list of input parameters (or arguments) that the function receives when it is called. Each parameter is defined with its data type and name, separated by commas. These parameters allow the function to receive data from the calling code, which it can use for its computations.

As for any expression, do not forget about ";".

And here are some examples:

```cpp
// the function does not take any parameters and does not return anything
void makeCake();

// takes two integers and returns an integer value
int sum(int one, int two);
```

Why might you need it? Imagine you're working on a big program with numerous functions and extensive code. To manage complexity and keep things organized, you might divide your code into several files, which is a common practice.

However, this division can create a challenge for the compiler. What if that function is defined in a different file? The compiler won't automatically know about it. That's where declaration comes in. In the main file, usually known as the 'entry point,' you provide what's known as a declaration for each function you're going to use.

By doing this, you're helping the compiler build a roadmap of your program's structure.

## Function definition

A function **definition** provides the actual implementation or body of a function. It defines the statements and actions that the function performs when called. A function definition consists of:

- a return type

- function name

- parameter list

- and the set of statements enclosed in curly braces.


The syntax for a function definition is as follows:

```cpp
return_type function_name(parameter_list)
{
    // Statements
}
```

And here are some examples:

```cpp
int sum(int a, int b) {
    int result = a + b; // function returns int
    return result; // exit from function and return the result
}
```

Notice there is no ";" after the closing brace, like structures.

## Call and use

And the final part of our story... **function invocation.**

**Function invocation** is an expression that instructs the processor to execute the function at that point, following these steps (conceptually):

1. Pause the execution of the current function and start executing another function. In the example below, the current function is `main()` and the other function is `sum()`.

2. The processor creates a "bookmark" at the current execution point and then executes the invoked function.

3. Once the invoked function completes execution, the processor returns to the "bookmark" and resumes execution of the interrupted function.


The function from which the call originates is referred to as the **caller**(`main()`), while the function being called is the **callee**(`sum()`), for example:

```cpp
#include <iostream>

int sum(int a, int b) { //function definition (nothing happens before calls)
    int result = a + b;
    return result;
}

int main()
{
    // stop the execution of the main() function
    // call the sum function and pass it two numbers (3 and 4)
    // wait for sum to complete
    // after completion, enter the amount into the result variable
    int result = sum(3, 4);
    std::cout << "The sum of 3 and 4 is: " << result << std::endl;

    result = sum(1, 3);
    std::cout << "The sum of 1 and 3 is: " << result << std::endl;

    result = sum(result, result);
    std::cout << "The sum is: " << result << std::endl;

    // You can even do this,
    // but you need to remember about the readability of the code
    result = sum(sum(1,2), sum(3,4));
    std::cout << "The sum is: " << result << std::endl;

    return 0;
}

```

The result of running this code:

```cpp
The sum of 3 and 4 is: 7
The sum of 1 and 3 is: 4
The sum is: 8
The sum is: 10
```

Have you been paying close attention to the code? If yes, I'm sure you've noticed another fantastic and useful feature of functions, namely, local scope. You've created variables with the same name, `result`, both in the `main()` function and the `sum()` function. However, these are completely separate variables, and this is possible because a function is like its own little world, with a single entrance (function parameters) and a single exit (return value). "What happens in Vegas, stays in Vegas," as they say.

## Time tested tips

While learning the C++ language, you'll have to write numerous programs that typically consist of three main global parts:

- Obtaining data from the user.

- Processing the data.

- Displaying the result.


Of course, you are the creator of your programs, especially in C++ (no one will stop you from shooting yourself in the foot), but eventually, through mistakes and pain, you will likely arrive at this realization on your own. So why waste time? Just incorporate these principles right from the beginning.

One of the most common challenges that beginners face is understanding where, when, and how to effectively use functions. Here are several key recommendations for writing functions:

1. Code that appears more than once in a program is better rewritten as a function. For example, if you're obtaining data from the user multiple times in the same way, it's an excellent opportunity to create a separate function.

2. Code used for sorting anything is better suited for a separate function. For instance, if you have a list of items to be sorted, you write a sorting function that takes in the data and returns an ordered list.

3. A function should perform one (and only one) task.

4. When a function becomes too large, complex, or unclear, divide it into smaller parts (smaller functions). This is called **code refactoring**.


## Benefits of using functions

I believe you have already seen the importance of functions and their various advantages, making them extremely valuable in complex programs. Here are a few more points in favor of using functions:

- Structure: As programs grow in size and complexity, keeping all the code inside `main()` becomes challenging. You can write a function as a mini-program separate from the main program, without worrying about the rest of the code. This allows you to break down complex tasks into smaller and simpler ones, significantly reducing the overall program complexity.

- Reusability: You can call a function multiple times once you've defined it. This helps avoid duplicating code and minimizes the chances of errors when copying/pasting code. You can also use functions in other programs, which reduces the amount of code you need to write from scratch each time.

- Testing: Since functions remove redundant code, testing becomes easier. As functions are self-contained units, you only need to test them once to ensure their functionality. After that, you can reuse them multiple times without the need for retesting (unless you make changes to that function).

- Upgradability: When you need to change a program or extend its functionality, functions are an excellent option. You can make changes in one place and have them work everywhere using functions.

- Abstraction: To use a function, you only need to know its name, input data, output data, and where it's located. You don't need to know how it works. This is very useful for writing code that is understandable to others (for example, the C++ Standard Library and everything within it are designed with this principle in mind).



In the realm of C++ programming, functions play a pivotal role in creating modular and organized code. Put simply, functions are like machines: you put something in (input), they process it, and something comes out (output). This topic will discuss input (passing input data to a function). Understanding how input data are passed to functions is crucial for effective program design. This topic delves into the various ways to pass input data to functions.

## Parameter and arguments in functions

To avoid confusion, you first need to understand the basic terms:

- In C++, a **parameter** is a variable that a function's prototype declares. This parameter signals the type and number of values that a function expects upon its call. It closely resembles a typical variable declaration (like int x) and operates as a regular, localized variable within the function. The main role of this parameter is to facilitate the passage of values from the calling point to the function.
- On the other hand, **arguments** are the actual values that a function receives when someone invokes it. These arguments match the defined parameters and the function uses them for computation within its body.

Here is an example of using parameters and arguments when writing functions:

```cpp
#include <iostream>

void byValue(int num) { // Here is our num parameter
    num = 10; // which is further used in our function.
}

int main() {
    int x = 5;
    byValue(x); // And here we are passing an argument to our function
    byValue(3); // we can pass the argument like this
    return 0;
}
```

You can pass any type of data to a function: variables, pointers, constants, arrays, structures, or any user data.

There are various ways to pass arguments to a function:

- passing by value;
- passing by reference;
- passing by pointer;

Now, let's consider each option in more detail.

## Passing by value

**Passing by value** involves sending a copy of the argument's value to the function. This means that any changes made to the parameter inside the function do not affect the original argument outside of the function. This method is useful when working with the argument's value without altering the original data.

```cpp
#include <iostream>

void byValue(int num) {
    num = 10; // Changes here won't affect the original value
    std::cout << num;
}

int main() {
    int x = 5;
    byValue(x);
    std::cout << x; // Outputs: 5
    return 0;
}
```

```no-highlight
Output:
10
5
```

In the example above, the function `byValue` takes an integer argument `num` and tries to modify it. However, since it's passed by value, the change is local to the function and doesn't affect the original value of `x` in the `main` function.

When passing by value, you "send" a copy of your object to the function. If you need to transfer a large amount of data (for example, an array of 1 million elements of a complex structure can weigh 1 GB), then this can be expensive and not optimal for your computer.

## Passing by reference

**Passing by reference** involves sending a reference to the argument, allowing the function to modify the original value directly. This method is particularly useful when you want to alter the original value and avoid the overhead of copying large data.

```cpp
#include <iostream>

void byReference(int &num) {
    num = 10; // Changes here will affect the original value
}

int main() {
    int x = 5;
    byReference(x);
    std::cout << x; // Outputs: 10
    return 0;
}
```

```no-highlight
Output:
10
```

In this example, the function `byReference` takes an integer reference as its argument. When the reference is modified within the function, it directly affects the original value of `x` in the `main` function.

In order to pass values by reference to a function, you need to:

1. Declare the function parameter as a reference (`int &num`).
2. Call the function, just like you would when passing parameters by value (which is very convenient) - `byReference(x)`.

## Passing by pointer

**Passing by pointer** involves sending the memory address of the argument to the function. This allows the function to access and modify the original value indirectly through the pointer. Pointers provide more control, as they can be reassigned to point to different memory locations. To do this, declare the function parameter as a pointer (`int *ptr`), call the function by passing the address (`byPointer(&x)`) of the variable. Or you can pass the value of the pointer.

```cpp
#include <iostream>

void byPointer(int *ptr) {
    //in order not to work with the address, we dereference the pointer
    *ptr = 10; // Changes here will affect the original value through the pointer
}

int main() {
    int x = 5;
    byPointer(&x); // passing the address of the variable.
    std::cout << x; // Output: 10
    return 0;
}
```

```no-highlight
Output:
10
```

In this example, the function `byPointer` takes an integer pointer as its argument. The pointer is dereferenced to access and modify the original value of `x` in the `main` function.

Working with pointers, whether in the context of arrays, functions, or memory management, offers great flexibility in programming. However, due to their direct manipulation of memory addresses, mishandling pointers can lead to memory corruption, crashes, and challenging debugging. It's crucial to grasp pointer-related concepts, initialize pointers properly, and follow best practices to prevent errors such as memory leaks and buffer overflows.

## Tips for usage

1. **Pass by Const Reference**: When you want to pass an argument without modifying it, pass by const reference to prevent accidental changes. This is particularly useful for objects that are expensive to copy (big objects);
2. **Prefer pass by reference for modification**: If a function needs to modify the argument, pass by reference to avoid unnecessary copying. Also, passing by reference is preferable to passing by pointer in most cases;
3. **Be cautious with pointers**: Passing pointers requires careful memory management. Ensure that the pointer is valid and points to valid memory to avoid issues like null pointer dereferencing.
4. **Document your code in detail**: Clearly document whether functions modify arguments or not in your code comments. This helps other developers understand how to use the functions correctly. This is important because the call for "pass by value" and "pass by reference" look exactly the same.