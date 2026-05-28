## Understanding memory allocation

In C++, we have three main types of memory allocation: static, automatic, and dynamic. Each type has its specific characteristics and uses.

- **Static memory allocation** takes place at compile time, before the affiliated program is run. Both the size and type of memory allocated are known at compile time. Examples of static memory allocation are **global** and **static** **variables**. Memory for these variables is allocated when the program starts and deallocated when the program stops running.

- For global variables, the compiler allocates memory **statically** before the program runs - this is to say, at the compilation stage. However, local variables declared inside functions don't behave in the same way. Instead, **automatic memory allocation** is used for these. It takes place when the program is running and is managed automatically. Memory for these variables is allocated when the function in which they're declared is called, and it's freed when the function ends. You don't need to monitor these objects. The memory area where these variables are stored is known as the **stack**.

- **Dynamic memory allocation** also occurs at runtime, but you have direct control over the memory. This means you can allocate memory when you need it and deallocate it when you're done. The `new` and `delete` operators are used for dynamic memory allocation and deallocation. The variables and objects associated with this type of memory allocation are stored in an area of memory called the heap.


⚠️ The stack and heap will be covered in more detail in the following topics. For now, just understand that the stack and the heap are different areas of memory where our variables and objects are stored.

Both static and automatic memory allocation share two properties: the variable/array's size must be known at compile time, and memory allocation and deallocation occur automatically (when a variable is created or destroyed). Dynamic memory, however, is a bit different. How it's handled lies entirely in your hands.

⚠️ Dynamic memory allocation is powerful and useful, but requires careful management. If you forget to deallocate memory, it can result in memory leaks. A memory leak happens when a program takes and fails to return a piece of memory. If this occurs frequently, you will run out of RAM, and other programs will be affected. Conversely, if you try to access memory after it's been deallocated, it can lead to undefined behavior.

Most times, the above conditions are okay. However, when managing user input, these constraints can cause problems.

Let's consider a situation where you're developing a game in which players can create their own team of heroes to fight against opponents. Each player can have any number of heroes on their team - from one to a hundred or even more.

Using automatic memory allocation to store the heroes in this scenario wouldn't be practical. Here's why:

```cpp
void startGame() {
    Hero team[100];  // Automatic memory allocation
    // ...
}
```

In the code above, we've allocated memory for a hundred heroes on the stack. But what if a player only wants to create a team of five heroes? We would have then wasted a lot of memory for 95 nonexistent heroes. What if a player wants to create a team of 101 heroes? Our array wouldn't be large enough to handle this.

That's where **dynamic memory allocation** comes to the rescue.

## Dynamic memory allocation

With dynamic memory allocation, you can ask the player how many heroes they'd like on their team and then allocate precisely that amount of memory.

```cpp
void startGame() {
    int numHeroes;
    std::cout << "Enter the number of heroes in your team: ";
    std::cin >> numHeroes;

    Hero* team = new Hero[numHeroes];  // Dynamic memory allocation

    // ... use the team ...

    delete[] team;  // Don't forget to deallocate the memory when we're done!
}
```

In this code, we're using dynamic memory allocation to create an array of `Hero` objects on the heap. The size of this array is determined at runtime based on the player's input. As a result, we use memory more efficiently by only allocating as much as we need. Plus, it provides the flexibility to handle any number of heroes a player might want on their team.

⚠️ Remember, with great power comes great responsibility. You're responsible for deallocating memory once you're done using it. If you forget to do this, as shown above with `delete[] team;`, you may encounter memory leaks, causing your program to consume more and more memory over time.

Now, let's take a closer look at working with dynamic memory and its components. In C++, we use the `new` and `delete` operators to perform dynamic memory allocation and deallocation.

```cpp
int *ptr = new int;  // Allocating memory
delete ptr;  // Deallocating memory
```

## The new operator

The `new` operator is used to allocate memory at runtime. It returns a pointer to the beginning of the allocated space.

```cpp
int *ptr = new int;
```

In this example, `new` allocates memory for an integer and returns a pointer to it. The pointer is then stored in `ptr`.

Also, you can initialize the memory at the time of allocation:

```cpp
int *ptr = new int(5);
```

Here, the allocated memory gets initialized with the value `5`. For such simple structures there's no need to allocate dynamic memory, so let's allocate for an array:

```cpp
#include <iostream>

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Allocate memory for the array
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
        std::cout << "Array element " << i << " is " << arr[i] << std::endl;
    }

    // Don't forget to deallocate the memory when you're done!
    delete[] arr;

    return 0;
}
```

In this example, we ask the user to specify the size of the array. We then use the new operator to allocate enough memory for an array of that size and use the array as we would any other array.

The user can put in any value and see the output. For instance, if we enter 5, the output will be:

```no-highlight
Array element 0 is 0
Array element 1 is 2
Array element 2 is 4
Array element 3 is 6
Array element 4 is 8
```

## Freeing up memory

It's essential to release any memory you've allocated when done using it. This is done using the `delete` operator.

```cpp
int *ptr = new int;
delete ptr;
```

If you're dealing with arrays, you should use `delete[]` to free up the memory:

```cpp
int *arr = new int[size];
delete[] arr;
```

Remember, you should not attempt to access memory once it's been deallocated. This can lead to undefined behavior.

⚠️ A **null pointer** is a pointer that doesn't point to any memory location. It's often used as a flag value to indicate that the pointer should not point to a valid location. When you use the `new` operator, if the memory allocation fails, it returns a null pointer. This can happen if your program doesn't have enough memory to fulfill the request. Checking for null pointers after allocation can help you handle memory allocation failures gracefully. You can do this using conditional statements ( `if (myPointer == nullptr)`)

## Memory leaks

A **memory leak** happens when you allocate memory but don't deallocate it. Over time, these leaks can stack up and consume a considerable amount of memory, potentially causing your program to crash or have performance issues.

To avoid memory leaks, always make sure every `new` has a matching `delete`.

```cpp
for(int i = 0; i < 100 000 000; ++i) {
    int *ptr = new int;
    // Some code...
    delete ptr;  // Without this line, there would be a memory leak
}
```

For instance, if you remove `delete ptr;` and run the code on your device, you can monitor the memory consumption (the method varies based on your operating system, you can find more details here: [check memory usage](https://www.wikihow.com/Check-Memory-Usage)) and you'll see how your program gradually takes up all your RAM. It's simple math: if the pointer size stands between 4 to 8 bytes (let's say 8), then our loop will create pointers equivalent to ~762 Mb. Add one more zero to the cycle at your own risk.

If dynamic memory allocation fails in C++, the new operator throws a std::bad\_alloc exception. If it's not caught, this exception will terminate the program. However, you can handle the exception safely with a try/catch block.