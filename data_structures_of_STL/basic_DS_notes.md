The Standard Template Library (STL) in C++ is a collection of template classes and functions designed to provide general-purpose solutions for common programming problems. Among its many offerings, the STL includes a wide range of data structures that are essential for various programming tasks. In this topic, we will explore the STL's basic data structures like vectors and lists, and introduce "Big O" notation to evaluate their algorithmic complexity.

## Algorithmic complexity

To describe algorithmic complexity, we use the following terminology, based on the "big O" notation:

1. O(111): Constant time complexity - The algorithm's runtime is not dependent on the input size; it always takes the same amount of time to execute, regardless of the input size, for example, accessing an element in an array by index.

2. O(log(n)log(n)log(n)): Logarithmic time complexity - The algorithm's runtime grows slowly as the input size increases, following a logarithmic curve, for example, binary search in a sorted list.

3. O(nnn): Linear time complexity - The algorithm's runtime is directly proportional to the input size; if the input size doubles, the runtime approximately doubles as well, for example, linear search in an unsorted list.

4. O(n∗log(n)n\*log(n)n∗log(n)): Linearithmic time complexity - The runtime grows slightly faster than linear time, typically seen in efficient sorting algorithms like merge sort and quicksort.

5. O( n2n^2n2): Quadratic time complexity - The runtime increases quadratically with the input size, often seen in nested loops.

6. O( 2n2^n2n): Exponential time complexity - The algorithm's runtime grows rapidly as the input size increases, making it highly inefficient for large inputs.


The below image represents the graph of algorithmic complexity:

![](https://ucarecdn.com/80d15ba0-61ed-4d83-97f8-9dcae305f061/)

You can learn more about Algorithms and algorithmic complexity in the Data Structures and Algorithms course.

## Basics of STL data structures

Before we delve into specific containers, it's essential to understand some common advantages shared by all STL containers:

- Header Inclusion: To use a specific container, you need to include the appropriate header file. For example, `#include <vector>` for vectors, `#include <list>` for lists.

- size() Method: Every container in the STL has a `size()` method, allowing you to determine the number of elements it holds. This method simplifies managing container sizes and offers consistency across different container types.

- empty() method: The `empty()` method is available for most STL containers and allows you to check whether the container is empty. It returns a boolean value, `true` if the container has no elements and `false` if it contains one or more elements. This method is particularly useful when you want to verify if a container has any data before performing operations on it.

- clear() method: The `clear()` method is available for many STL containers and is used to remove all elements from the container, effectively making it empty. This operation is useful when you need to release the resources held by the container or when you want to reset the container to its initial state.


## Vectors

In C++, a `std::vector` is a versatile and fundamental data structure that represents a dynamic array. Unlike traditional arrays in C++, vectors can dynamically adjust their size, allowing you to manage collections of elements efficiently. This flexibility makes `std::vector` one of the most commonly used data structures in C++ programming.

**Syntax to declare a vector:**

```cpp
std::vector<DataType> vectorName;
```

Here, `DataType` is the type of data the vector will hold (e.g. `int`, `double`, `string`).

Now, let's see the key features of vectors and why should you use vectors:

- Fast access to elements via indexing and the complexity of doing this is O(1).
- Automatic resizing when elements are added or removed.
- Ideal for use cases where elements need to be accessed frequently, and the size of the container may change.

Now, let's explore how to perform essential operations: adding elements, accessing elements, and finding the size of the vector.

**Adding Elements to a Vector:** One of the key advantages of using `std::vector` is its ability to grow dynamically. You can add elements to the vector using the `push_back` method, as demonstrated below:

```cpp
numbers.push_back(6);  // Add an element to the end
```

Adding elements to the end of a vector is a fast and efficient operation ( O(1) ), while adding elements to the middle of a vector is less effective and has a time complexity of O(N) because when you add an element to the middle of a vector, all elements that come after the insertion point need to be shifted to accommodate the new element. This requires copying each element to a new memory location, which takes O(N) time, where N is the number of elements that need to be shifted.

**Accessing an element by index:** The indexing operator allows for direct and quick access to an element in the vector. However, it does not perform bounds checking. If you attempt to access an index outside the valid range of the vector, your program may exhibit undefined behavior or crash.

```cpp
int element = numbers[2];  // Access the third element (index 2)
```

The `at()` method, on the other hand, provides an additional layer of safety by performing bounds checking. It checks whether the index is within the valid range (between 0 and `size() - 1`). If the index is out of bounds, it will throw an `std::out_of_range` exception.

```cpp
int element = numbers.at(2);  // Access the third element (index 2) with bounds checking
```

**Finding the size (number of elements) of the vector:**

```cpp
int size = numbers.size();  // Get the size of the vector
```

The below example discusses how the above operations are performed on a vector:

```cpp
#include <iostream>
#include <vector>

int main() {

    // Creating a vector of integers
    std::vector<int> myVector;

    // Adding elements to the vector
    myVector.push_back(10);   // Adds 10 to the end of the vector
    myVector.push_back(20);   // Adds 20 to the end of the vector
    myVector.push_back(30);   // Adds 30 to the end of the vector

    // Accessing an element by index (zero-based index)
    int secondElement = myVector[1];  // Accessing the element at index 1

    // Finding the size (number of elements) of the vector
    int vectorSize = myVector.size();  // Returns the size, which is 3 in this case

    for (int i = 0; i < vectorSize; i++) {
        std::cout << "Element at index " << i << ": " << myVector[i] << std::endl;
    }

    std::cout << "Size of the vector: " << vectorSize << std::endl;

    return 0;
}
```

Here's the result of the above code snippet:

```bash
Element at index 0: 10
Element at index 1: 20
Element at index 2: 30
Size of the vector: 3
```

Keep in mind that while vectors offer dynamic resizing, adding or removing elements from the front or middle can be less efficient than at the end. If frequent insertions or deletions at arbitrary positions are a requirement, other data structures like `std::list` or `std::deque` maybe more appropriate.

## List

In C++, a `std::list` is a doubly-linked list container from the Standard Template Library (STL). Unlike arrays or vectors, `std::list` stores elements in nodes that are connected in a bidirectional manner, offering efficient insertions and deletions at both ends, making it an ideal choice for scenarios with frequent modifications.

However, it's not suitable for direct random access, and elements are not stored contiguously in memory. `std::list` provides iterators (which you'll study later) to traverse its elements, and it's known for its flexibility in managing and manipulating data.

**Syntax to declare a list:**

```cpp
std::list<DataType> listName;
```

Here `DataType` is the type of data the list will hold (e.g., `int`, `string`).

Now, let's see the key features of lists:

- Efficient insertions and deletions anywhere in the container.
- Not suitable for direct random access (slower than vectors) as it has a time complexity of O(N).
- No contiguous memory allocation.
- Bi-directional traversal. It means you can move through the elements of the list in two ways: Forward Traversal: You can start at the beginning (using the `begin()` iterator) and move through the list element by element until you reach the end (using the `end()` iterator). Backward Traversal: You can start at the end (using the `rbegin()` iterator) and move through the list in the reverse order, element by element, until you reach the beginning (using the `rend()` iterator).

You'll learn about these iterators and how to work with them in the next topics.

Now, let's explore how to perform essential operations: adding elements, and finding the size of the list.

**Adding Elements to a List:** To add elements to a `std::list`, you typically use the `push_back()` or `push_front()` methods to add elements to the back or front of the list, respectively. For example:

```cpp
myList.push_back(6);  // Add an element to the end
myList.push_front(3); // Add an element to the front
```

Unlike vectors, lists are efficient at adding elements at both the front and the back because they do not require shifting elements.

**Finding the size (number of elements) of the List:** To find the number of elements in a `std::list`, you can use the `size()` method, just like with vectors:

```cpp
int size = myList.size(); // Get the size of the list
```

Both vectors and lists provide an O(1) operation for finding their sizes.

Here's an example of how you can work with a `std::list`:

```cpp
#include <iostream>
#include <list>

int main() {

    // Creating a list of strings
    std::list<std::string> myList;

    // Adding elements to the list
    myList.push_back("apple");
    myList.push_back("banana");
    myList.push_back("cherry");
    myList.push_front("watermelon"); // Insert an element at the front (beginning) of a container

    // Using a range loop to iterate through the list with a copy of elements
    for (std::string fruit : myList) {
        std::cout << fruit << " ";
    }

    return 0;
}
```

Here's the result of the above code snippet:

```bash
watermelon apple banana cherry
```

In this code snippet, we first include the `<list>` header to use the `std::list` container. Then, we create a `std::list` called `myList`. Afterward, we use the `push_front` and `push_back` method to add the strings to the front and back of the list. Finally, we iterate through the list and print its contents.

## Container selection

In C++, selecting between lists and vectors as container types depends on the specific needs of your program, considering factors like insertion/deletion operations, and time complexity. Here's a comparison of lists and vectors:

**1\. Lists**

- Time Complexity:
  - O(1) for inserting/removing elements at the beginning/end.
  - O(n) for accessing elements by index since you may need to traverse the list.
  - O(1) for insertions and deletions anywhere in the list (if you have an iterator).
- When to Use:
  - When frequent insertions and deletions are necessary, especially in the middle of the container.
  - When you don't require fast random access to elements.

**2\. Vectors**

- Time Complexity:
  - O(1) for accessing elements by index.
  - O(1) for inserting/removing elements at the end.
  - O(n) for inserting/removing elements in the middle (due to shifting elements).
- When to Use:
  - When you need fast random access to elements.
  - When most of your operations involve reading elements by index.
  - When you want to minimize memory overhead, as vectors have a smaller memory footprint compared to lists due to contiguous storage.

Select a list when you need efficient insertions and deletions in the middle of your container or when the actual number of elements in the container is not known in advance, and you want to minimize memory reallocation.

Choose a vector when you need fast random access to elements, and the majority of your operations involve reading elements by index. Vectors are memory-efficient for large datasets and are generally faster than lists for sequential access.

Below is the time complexity of vectors and lists of different operations:

![Time complexity of vectors and list in different operations](https://ucarecdn.com/73a8be30-ea0e-47e2-800e-eb1fa2f895e4/)