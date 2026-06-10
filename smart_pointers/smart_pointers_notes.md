## Pointers and their issues

Pointers in C++ can be risky and result in bugs like memory leaks or dangling pointers. These problems can develop due to manual memory management and the lack of automatic cleanup:

- It's easy to forget to free the memory allocated for the pointer at the end;
 
- An error might happen because of an early `return`. For instance, if you have an if/else block and **if is true**, you return without deleting the pointer;
 
- Or because an exception gets triggered;
 

In all these situations, the function finishes its run before the pointer is deleted. As a result, we get a memory leak. Here's an example of such mistakes:

```cpp
#include <iostream>

void processArray(int size) {
    int* arr = new int[size];

    if (size <= 3) {
        return; // Memory not freed
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }

    if (size > 20) {
    // Exception thrown without freeing memory
        throw std::runtime_error("Array size too large"); 
    }

    // delete[] arr;
}

int main() {
    int arraySize = 50;
    processArray(arraySize);

    arraySize = -1;
    processArray(arraySize);

    return 0;
}
```

In this example, the `processArray` function dynamically creates an array of integers based on the given size. However, it introduces three errors:

- If the size parameter is less than or equal to 3, the function exits without freeing the allocated memory, leading to a memory leak.
 
- If the size parameter is over 20, an exception is thrown without freeing the allocated memory, causing a memory leak.
 
- And finally, we forgot to clear the memory at the end of the function.
 

This might be a simple example, but now think about a project with 100,000 lines of code (and a team of developers). Can you be sure that no one will make mistakes? In essence, such problems occur because pointers lack a built-in mechanism to clean up memory.

## Smart pointers

Smart pointers tackle these issues by managing the lifecycle of dynamically allocated objects. **Smart pointers** are specifically designed classes. One of the best things about classes is their destructors, which automatically execute when a class object goes out of scope.

When you allocate memory in a class constructor, you can be sure that this memory will be freed in the destructor when the class object is destroyed (whether it goes out of scope, is specifically deleted, etc.). This is the core idea of the [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) programming paradigm.

Creating smart pointers took a while (the initial versions appeared in the 98 standard), and there were several options. Presently, there are three smart pointers worth knowing (each with its own purpose). In this topic, we will focus on the most commonly used one - `std::unique_ptr`:

- `std::unique_ptr` is like owning a personal key to a house. You are the sole owner and controller of the house. When you don't need the house anymore, you automatically return the key, and the house gets cleaned up.
 
- `std::shared_ptr` is like having a shared membership to a club. Many people can access the club together. When the last person leaves the club, it automatically shuts and gets cleaned up.
 
- `std::weak_ptr` is like owning a temporary pass to a club. You can visit the club as long as it's open, but you can't keep it open. If the club closes, your pass becomes invalid, and you can't enter the club anymore.
 

## std::unique\_ptr

`std::unique_ptr` is a smart pointer that represents exclusive ownership of an object. It ensures that just one `std::unique_ptr` instance can own an object at a time. When the `std::unique_ptr` goes out of scope or is explicitly reset, it automatically deletes the associated object. Let's look at how to work with smart pointers:

```cpp
#include <memory>

int main() {
    // Creating a unique_ptr
    std::unique_ptr<int> ptr(new int(10));

    // Accessing the value using the dereference operator
    int value = *ptr;
    std::cout << "Value: " << value << std::endl;

    // Modifying the value
    *ptr = 20;
    std::cout << "Modified Value: " << *ptr << std::endl;

    // Releasing ownership and deleting the object
    ptr.reset();

    return 0;
}
```

In this example, we include the `<memory>` header to use the `std::unique_ptr` class. Inside the `main()` function, we create a `std::unique_ptr<int>` called ptr and initialize it with a dynamically allocated integer value of 10 using the new keyword.

To reach the value stored in the `std::unique_ptr`, we use the dereference operator `*`. It's just like using a regular pointer.

We can also modify the value stored in the `std::unique_ptr` by dereferencing it and assigning a new value.

To release the ownership of the dynamically allocated object and delete it, we call the `reset()` function on the `std::unique_ptr`. This ensures proper memory management and prevents memory leaks. This works similarly to the `delete` operator for regular dynamically allocated objects. But what happens if you don't call this method?

When a function in which a smart pointer was created finishes (or when our program ends, i.e., the main function), we exit the scope of that function. At this point, the smart pointer automatically frees the memory, and we don't need to remember to do it ourselves. This is the biggest advantage of a smart pointer. But, if you want to control everything yourself, you can use the `reset()` method.

You can access the object managed by a `std::unique_ptr` through the `get()` method:

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr(new int(42));

    int *rawPtr = ptr.get(); // Access the raw pointer
    std::cout << "Value: " << *rawPtr << std::endl;

    int &ref = *ptr; // Access the object using operator *
    std::cout << "Value: " << ref << std::endl;

    return 0;
}
```

Result of the program:

```no-highlight
Value: 42
Value: 42
```

You can use a `std::unique_ptr` to work with dynamic arrays:

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int[]> arr(new int[5]{1, 2, 3, 4, 5});

    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

Result of the program:

```no-highlight
1 2 3 4 5 
```

Pointer initialization may seem complicated, so let's break it down:

- `std::unique_ptr<int[]>`: this part declares a `std::unique_ptr` named `arr` that will manage a dynamic array of integers. The angle brackets `<int[]>` show that the `std::unique_ptr` will be managing an array, not a single object;
 
- `new int[5]`: this part dynamically creates an array of integers with a size of 5 using the new keyword. The new operator allocates memory on the heap for the array;
 
- `{1, 2, 3, 4, 5}`: This section initializes the elements of the dynamic array with the numbers 1, 2, 3, 4, and 5.
 

Additionally, smart pointers are suitable for storing user-defined data types like structures or classes. In this case, getting to the fields and methods within is done using the arrow operator (->):

```cpp
#include <iostream>
#include <memory>

struct MyStruct {
    int data;
};

int main() {
    std::unique_ptr<MyStruct> ptr(new MyStruct);

    // Assigning a value to the field using the arrow operator
    ptr->data = 42;

    // Accessing the field's value using the arrow operator
    std::cout << "Data: " << ptr->data << std::endl;

    return 0;
}
```

Result of the program:

```no-highlight
Data: 42
```

## std::make\_unique

`std::make_unique` is a utility function introduced in C++14 that simplifies the process of creating and initializing objects managed by `std::unique_ptr`. It lets you create a `std::unique_ptr` and initialize the managed object in just one line of code:

```cpp
#include <iostream>
#include <memory>

int main() {
    // Use make_unique to create and initialize a unique_ptr
    auto ptr = std::make_unique<int>(42);

    // Access the value using the dereference operator *
    std::cout << "Value: " << *ptr << std::endl;

    // Modify the value using the dereference operator *
    *ptr = 99;
    std::cout << "Modified value: " << *ptr << std::endl;

    // The managed object will be deleted automatically when ptr goes out of scope

    return 0;
}
```

The advantage of using `std::make_unique` is that it simplifies the code by combining the allocation and initialization of the managed object into a single line. It also ensures exception safety, as the `std::unique_ptr` will automatically delete the managed object if an exception happens during the initialization.

⚠️ Note that `std::make_unique` is available in C++14 and later versions. If you're using an older version of C++, you can still achieve similar functionality by using the `new` operator directly or by using other helper functions like `std::unique_ptr` constructor.

## Conclusion

Smart pointers in C++ offer a safer and more convenient way to manage dynamically allocated objects. `std::unique_ptr` provides exclusive ownership and automatic cleanup. By using smart pointers, developers can steer clear of memory leaks, dangling pointers, and other common pointer-related problems, which results in more reliable and robust code.