
## Memory segments

The memory of a running program is segmented into different sections, each dedicated to a specific purpose. Understanding these sections will give you a clearer picture of where dynamic memory allocation fits into overall memory management. Here are the key memory segments:

1. **Code segment**: Also known as the **text segment**, this is where the compiled program is stored in memory. It contains the binary code of your compiled program.

2. **Data segment**: This segment is split into the initialized data segment and the uninitialized data segment:
   - **Initialized data segment**: This section contains global, static, and constant data initialized by the programmer.

   - **Uninitialized data segment**: This section stores uninitialized global and static variables that are set to zero or lack explicit initialization in the source code. Often, it may just contain some type of garbage data.
3. **Stack segment**: The **stack** is where local variables (those declared within functions) are allocated. It also tracks function calls and returns. When a function is called, memory is earmarked for its variables on the stack. This reserve is given back when the function exits. The process of allocating and deallocating is managed automatically by the compiler.

4. **Heap segment**: The **heap** is where dynamic memory allocation occurs. Unlike the stack, the heap is not automatically managed. So, when you allocate memory on the heap using `new`, you are responsible for deallocating it when you're done. If you don't do this, it could result in a memory leak.


Here's a visual depiction of the memory layout:

![Simplified memory device diagram](https://ucarecdn.com/60b751b0-bfe7-476c-b5ee-1a357f395776/)

On the left, you'll see a simplified representation of the entire memory. On the right is a free area of memory that can be used by the stack and heap. As you can observe:

\- the stack is smaller than the heap (in reality, the difference is much larger, in the orders of thousands);

\- the stack is orderly, with all values stored sequentially (new addresses for objects will only be issued after the previous ones are filled), thus making it faster than the heap;

\- contrary to the stack, the heap lacks order, but it lets you easily place large objects.

⚠️ The stack grows downwards (from higher memory addresses to lower), and the heap grows upwards (from lower memory addresses to higher). If they ever meet, you'll run out of memory, often leading to a program crash.

Our key interest lies in the **stack** and **heap**. The stack is organized and sequential, thus presenting a structured memory layout. On the other hand, the heap is more dispersed, leading to a scattered memory configuration. The orderliness of the stack contributes to its speed. Conversely, the scattered nature of a heap slows it down.

## Stack

The **stack** is a region of memory where local variables are stored. It follows a Last In, First Out (LIFO) structure, which means the most recently added item is the first one to be removed.

Imagine you have a stack of papers, each with a different task written on it. These sheets are stacked on your desk, one over the other. The task on the topmost sheet is the one you're currently working on.

Each time you complete a task, you remove its corresponding sheet from the top of the stack, revealing the sheet (and task) underneath. You can't remove a sheet from the middle or bottom of the stack as it would disrupt all the tasks above it.

Hence, you follow a strict rule: always remove the sheet from the top of the stack. This rule ensures that the last task added to the stack (the last sheet placed on top) is the first you complete. This is the principle of Last In, First Out (LIFO).

In a C++ context, this is similar to how the call stack functions. Every time a function is called, a new **stack frame** is added to the stack. This frame contains all the local variables and parameters of the function. Once the function returns, its stack frame is removed from the stack.

```cpp
void function() {
    int x = 10; // This variable is stored on the stack
}
```

## Call stack

The **call stack** is a specific part of the standard stack that keeps track of function calls. Each time a function is called, a new frame is added to the call stack. This frame includes information such as the function's local variables, parameters, and return address.

Does it sound complicated? It'll become clearer with this simple program that simulates a person getting ready in the morning:

```cpp
#include <iostream>

void putOnShoes() {
    std::cout << "Putting on shoes.\\n";
}

void putOnShirt() {
    std::cout << "Putting on shirt.\\n";
    putOnShoes();
    std::cout << "Finished putting on shirt.\\n";
}

void brushTeeth() {
    std::cout << "Brushing teeth.\\n";
    putOnShirt();
    std::cout << "Finished brushing teeth.\\n";
}

void wakeUp() {
    std::cout << "Waking up.\\n";
    brushTeeth();
    std::cout << "Finished waking up.\\n";
}

int main() {
    wakeUp();
    return 0;
}
```

The output of the program will be:

```no-highlight
Waking up.
Brushing teeth.
Putting on shirt.
Putting on shoes.
Finished putting on shirt.
Finished brushing teeth.
Finished waking up.
```

Here's how the call stack changes as this program executes:

1. When the program starts, `main()` is called and its stack frame is pushed onto the call stack.

2. `main()` calls `wakeUp()`. The stack frame for `wakeUp()` is pushed onto the call stack.

3. `wakeUp()` then calls `brushTeeth()`. The stack frame for `brushTeeth()` is pushed onto the call stack.

4. `brushTeeth()` calls `putOnShirt()`. The stack frame for `putOnShirt()` is pushed onto the call stack.

5. `putOnShirt()` calls `putOnShoes()`. The stack frame for `putOnShoes()` is pushed onto the call stack.


At this point, the call stack looks like this (from top to bottom):

![](https://ucarecdn.com/4042c46e-22cf-4f26-9f06-07c3baf32d3d/)

Now we can “unwind” the call stack in reverse order:

6\. `putOnShoes()` finishes executing, so its stack frame is popped from the call stack.

7\. `putOnShirt()` finishes executing, so its stack frame is popped from the call stack.

8\. `brushTeeth()` finishes executing, so its stack frame is popped from the call stack.

9\. `wakeUp()` finishes executing, so its stack frame is popped from the call stack.

10\. Finally, `main()` finishes executing, so its stack frame is popped from the call stack.

So, the call stack is empty again. As you can see from this example, the call stack demonstrates the Last In, First Out (LIFO) behavior: the last function to be called is the first to finish executing.

## Stack overflow

A **stack overflow** is an error that happens when the stack memory is exhausted. This occurs when a program uses up more stack space than the limits set for it.

In many operating systems, the default stack size for a program is set relatively small. For instance, on Linux, the default stack size is often 8 megabytes, while on Windows, it's 1 megabyte.

In a C++ setting, a stack overflow is largely due to excessive recursion. Recursion is a technique where a function calls itself as part of its execution. Each recursive call increases the stack depth, that is, it adds a new stack frame. If the recursion is too deep, the stack can exceed its capacity, leading to a stack overflow.

If a program is using excessive stack space, it could signal that the program's design needs improvement. For instances, deep recursion (this means that the function will call itself many times and the stack glass will quickly fill up with calls to this function) might be replaced with a loop, or large local variables might be moved to the heap.

When a stack overflow happens, the program will typically crash:

```cpp
void recursive() {
    int x[100000]; // This will likely cause a stack overflow
    recursive();
}

int main() {
    recursive();
}
```

In this example, we've caused a stack overflow by using a very large local variable.

## Heap

In contrast to the **stack**, the **heap** is a region of a computer's memory used for dynamic memory allocation. This means variables can be allocated and deallocated on the heap during a program's runtime. Unlike the stack, memory in the heap isn't automatically cleaned up when a function finishes executing. Heap memory needs management with the `new` and `delete` keywords in C++. When you use `new`, memory is allocated on the heap. And when you use `delete`, that memory gets deallocated.

Imagine you're planning a party and want to keep track of all your guests. However, you don't know how many people will attend until they respond. In this case, you can use the heap to dynamically allocate an array to hold the names of your guests:

```cpp
#include <iostream>

int main() {
    int numGuests;
    std::cout << "How many guests are you expecting? ";
    std::cin >> numGuests;

    // Dynamically allocate an array on the heap
    std::string *guestList = new std::string[numGuests];

    // Get the names of the guests
    for (int i = 0; i < numGuests; i++) {
        std::cout << "Enter the name of guest " << i+1 << ": ";
        std::cin >> guestList[i];
    }

    // Display the guest list
    std::cout << "\nGuest List:\n";
    for (int i = 0; i < numGuests; i++) {
        std::cout << guestList[i] << "\n";
    }

    // Don't forget to deallocate the memory when you're done with it!
    delete[] guestList;

    return 0;
}
```

In this example, we use `new` to dynamically allocate an array on the heap. We determine the size of the array at runtime, based on the user's input. We then use this array to store the names of the guests. Once we're finished using the array, we use `delete[]` to deallocate the memory.

Let's look at a simple example of how the stack and heap function:

![Diagram showing how code is distributed in memory](https://ucarecdn.com/8752efc0-60da-4166-814a-f4fe23e259f2/)

1. We create an `int` type variable. Memory is allocated for it on the stack;

2. We create an `int` type pointer. Space is allocated on the stack (right after the previous object) for the pointer itself. At this stage, it stores some random data (some strange address);

3. We allocate memory on the heap using the `new` operator. The stack now stores the address of a memory cell from the heap—they're linked;

4. We place value 20 in a cell located on the heap, the address of which is stored on the stack;

5. We free up the memory, allowing another program or the Operating System to use this memory. In this situation, our pointer becomes “dangling” and needs to be reset (`heapVar = nullptr;`). If we don't nullify the pointer, it'd be tough to check if the pointer can be used. It might point to something, but it would be hard to tell if it's garbage or useful information.