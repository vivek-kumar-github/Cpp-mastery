The Standard Template Library (STL) in C++ is a collection of template classes and functions that provide essential data structures and algorithms for programmers. One of the key components of STL is its set of algorithms, which allow you to perform various operations on containers like vectors, lists, and arrays. In this topic, we will explore some of the fundamental algorithms in STL and how to use them effectively.

## What are STL algorithms

STL algorithms are a set of pre-defined functions for performing common operations on data structures like vectors, arrays, and lists. These algorithms are implemented using templates, making them versatile and adaptable to different data types. They save developers time and effort by providing efficient solutions to recurring problems.

There are numerous STL algorithms, each designed for a specific purpose. Some common ones include `std::sort``std::find`, `std::count`, `std::replace`, and `std::reverse`.

We'll discuss commonly used STL algorithms in the below sections but first, let's see what iterators are in C++, after all, almost all algorithms are based on them.

## Iterators

In C++, iterators are like pointers that allow you to traverse and manipulate elements in containers like vectors, arrays, and lists. They provide a way to access and work with the elements stored within these containers. Iterators act as a bridge between the high-level operations you want to perform, like searching or sorting, and the low-level data stored in the container.

- `begin()`: The `begin()` method returns an iterator pointing to the first element of a container. It serves as the starting point for iterating through the container's elements. Think of it as the "beginning" of your data.

- `end()`: The `end()` method returns an iterator pointing to the memory area following the last element in a container. It signifies the end of the data. It's crucial to note that the element pointed to by `end()` is not a valid element in the container; it simply points to the element after the last valid element.


```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using iterators to traverse the vector
    std::vector<int>::iterator it; // Declare an iterator

    for (it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    return 0;
}
```

In the above example,

1. We declare an iterator `it` of type `std::vector<int>::iterator`. This iterator is used to iterate over the elements in the vector.

2. We use a `for` loop to start at the `begin()` of the `numbers` vector (the first element) and continue until we reach the `end()` of the vector (which is one past the last element). The iterator `it` is used to keep track of the current position in the vector.

3. Inside the loop, we dereference the iterator with `*it` to access the current element, and then we print it. This allows us to access and process each element in the vector one by one.


So, in short, iterators like `it` combined with `begin()` and `end()` provide a way to step through the elements of a container, allowing you to access and manipulate each element as needed. This makes it possible to perform operations on the container's elements without needing to know its size or the underlying data structure.

While this topic primarily demonstrates the usage of STL algorithms with vectors for the sake of simplicity, it's important to note that these algorithms are not limited to vectors alone. They are designed to work with various C++ data structures, including arrays, lists, and more.

## Sorting elements

Sorting is a common task in programming, and STL makes it incredibly easy with the `std::sort` algorithm. Here's a simple example of how to sort a vector of integers:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

The `std::sort` algorithm is used to sort a container (in this case, a `std::vector`) in ascending order. It takes the `begin()` and `end()` iterators of the container as arguments. After sorting, the vector `numbers` will be {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9}.

## Searching elements

Searching for an element in a container is a common operation. STL provides `std::find` to simplify this task:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    auto it = std::find(numbers.begin(), numbers.end(), 5);

    if (it != numbers.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}
```

The `std::find` algorithm searches for the value 5 in the vector `numbers`. If found, it returns an iterator to the element; otherwise, it returns `numbers.end()`.

## Summing Elements

Sometimes you need to calculate the sum of elements in a container. `std::accumulate` can handle this for you:

```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
```

In the above example, `std::accumulate` adds all the elements in the vector `numbers` and stores the result in the `sum` variable and prints **44** as the result.

## Reversing Elements

To reverse the order of elements in a container, you can use `std::reverse`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::reverse(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In the above example, `std::reverse` reverses the order of elements in the vector `numbers`, resulting in {5, 3, 5, 6, 2, 9, 5, 1, 4, 1, 3}.

## Counting elements

`std::count` is used to count the occurrences of a specific element in a container. Let's take an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int target = 5;

    int times = std::count(numbers.begin(), numbers.end(), target);

    std::cout << "The number " << target << " appears " << times << " times." << std::endl;

    return 0;
}
```

In this code, `std::count` counts the occurrences of **5** within the vector, resulting in the output: "The number 5 appears 3 times".

## Complexities

In the above sections, we explored some essential algorithms provided by the C++ Standard Template Library (STL) for common operations on containers. It's worth noting the time complexity of these algorithms, which is crucial in selecting the right tool for the task. Here's a table summarizing the time complexity of the algorithms we discussed:

![](https://ucarecdn.com/d792c65e-8e82-4565-929d-ca40f613805f/)

Understanding the complexity of these algorithms is essential for choosing the most efficient solution for your specific use case. While these algorithms can be implemented independently, the STL implementations are highly optimized, making it unlikely that you'll achieve better time complexity. Therefore, it's not only useful to know how to implement them but also to leverage efficient STL implementations when working with C++ containers.