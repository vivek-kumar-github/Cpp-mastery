## What is a dynamic array?

Dynamic arrays are a more flexible alternative to static arrays because they can grow or shrink as needed, adapting to changing data requirements.

Here are several practical uses of dynamic arrays in C++ programming:

1. **Dynamic data storage:** Dynamic arrays prove handy when the number of elements to store is not known during compile time, or might change during program execution. This is often the case when you're reading data from a file or capturing input from the user.
 
2. **Dynamic resizing:** Dynamic arrays make it possible to resize arrays based on runtime conditions. This capability is especially beneficial when working with data structures that should grow or shrink dynamically, such as lists, stacks, queues, or hash tables. Dynamic resizing promotes efficient memory usage and prevents wastage of memory or running out of memory.
 
3. **Managing large datasets:** For applications dealing with large datasets, dynamic arrays can help manage and process data efficiently. By dynamically allocating memory as needed, these arrays enable the handling of vast amounts of data without imposing rigid size limitations.
 
4. **Working with complex, potentially large, custom data structures:** If you have a sizable custom class, and you need to store a significant number of objects of this type, placing them on the heap (using a dynamic array), rather than the stack, is a good idea to avoid overflow.
 

Dynamic arrays are implemented with pointers and memory allocation functions like `new` and `delete` in C++.

In C++, the Standard Template Library (STL) provides container classes that offer high-level data structures, such as vectors, lists, queues, stacks, and maps.

We will explore these concepts in more detail in later topics.

Take for example, the `std::vector` container. It is implemented using dynamic arrays, providing an interface similar to dynamic arrays. However, it manages memory and resizing automatically. When the number of elements in a vector exceeds its current capacity, it dynamically allocates a new, larger array, copies the existing elements to the new array, and deallocates the old one. This feature enables vectors to grow and shrink dynamically without the need for manual memory management.

## Initializing dynamic arrays

To initialize a dynamic array, you need to dynamically allocate memory using the `new` operator. This operator returns a pointer to the allocated memory, which you can then use to access the elements of the array.

Assume you are writing a program that calculates the average of a set of numbers entered by the user. But, you don't know beforehand how many numbers the user will provide. See below how you can employ a dynamic array to store and calculate the average:

```cpp
#include <iostream>

int main() {
    int *numbers = nullptr; // Initialize the dynamic array pointer
    int size = 0;

    int input;
    char choice;

    do {
        std::cout << "Enter a number: ";
        std::cin >> input;

        // Increase the size of the dynamic array by 1
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = numbers[i];
        }
        temp[size] = input;

        delete[] numbers; // Deallocate the old array
        numbers = temp; // Assign the new array

        size++; // Increment the size

        std::cout << "Do you want to enter another number? (Y/N): ";
        std::cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    // Calculate the average
    double sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += numbers[i];
    }
    double average = sum / size;

    std::cout << "Average: " << average << std::endl;

    delete[] numbers; // Deallocate the dynamic array

    return 0;
}
```

In this example, a dynamic array `numbers` is used to store the user's inputs. The array is initially set to `nullptr`, and its size is tracked using the `size` variable. However, since there is no built-in size-tracking method, we track this manually.

You'll notice that `nullptr` is handy for verifying that we don't have a dangling pointer.

As the user enters numbers, the array is dynamically resized to accommodate this new input. The program ends by printing the numbers entered by the user and deallocating the dynamic array.

## Removing a dynamic array

Once you're done with a dynamic array, it's crucial to free the allocated memory to prevent memory leaks. This action is done using the `delete[]` operator. Not deallocating memory can lead to memory leaks, causing performance issues and even crashing your program. Remember always to pair each `new` operator with a corresponding `delete[]` operator.

For example, suppose you want to let your program store and manipulate student grades for a particular course. You would need three arrays:

- one to store student names;
 
- one to store the corresponding grades;
 
- and another one to track the number of entered grades.
 

Let's see how you can use dynamic arrays to manage this requirement:

```cpp
#include <iostream>

int main() {
    std::string *names = nullptr;
    int *grades = nullptr; 
    int *count = nullptr; 

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Allocate memory for the arrays
    names = new std::string[numStudents];
    grades = new int[numStudents];
    count = new int[numStudents];

    for (int i = 0; i < numStudents; i++) {
        std::cout << "Enter the name of student " << i + 1 << ": ";
        std::cin >> names[i];

        std::cout << "Enter the grade for " << names[i] << ": ";
        std::cin >> grades[i];

        count[i] = i + 1;
    }

    // Display the entered data
    std::cout << "\\nEntered data:\\n";
    for (int i = 0; i < numStudents; i++) {
        std::cout << "Student " << i + 1 << ": " << names[i] << ", Grade: " << grades[i] << std::endl;
    }

    // Deallocate the arrays
    delete[] names;
    delete[] grades;
    delete[] count;

    return 0;
}
```

When you test the program by adding three students, you should see the following result:

```no-highlight
Enter the number of students: 3
Enter the name of student 1: Maria
Enter the grade for Maria: 4
Enter the name of student 2: Martin
Enter the grade for Martin: 4
Enter the name of student 3: Merkush
Enter the grade for Merkush: 5

Entered data:
Student 1: Maria, Grade: 4
Student 2: Martin, Grade: 4
Student 3: Merkush, Grade: 5
```

All three dynamic arrays were deallocated using the `delete[]` operator to free up the allocated memory.

This example highlights the need to properly deallocate dynamic arrays with delete\[\] when they are not needed. By doing so, you avoid memory leaks and ensure efficient memory usage.

## Conclusion

Dynamic arrays provide the flexibility to handle varying amounts of data in C++ programs. They allow for the allocation and deallocation of memory at runtime, enabling arrays to be resized as needed. Key aspects of dynamic arrays include their initialization using the `new` operator, removal using the `delete[]` operator, and size alteration by allocating a new array and copying the elements.