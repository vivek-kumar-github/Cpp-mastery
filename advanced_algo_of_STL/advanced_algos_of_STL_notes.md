Building upon the foundation of basic algorithms in the C++ Standard Template Library (STL), let's delve into more advanced algorithms that are frequently used in C++. These algorithms provide powerful tools for complex operations on containers, offering efficiency and convenience. In this topic, we will explore some advanced STL algorithms that go beyond the basics.

## Binary search

While `std::find` is handy for searching, it performs a linear search and has linear time complexity. For large sorted datasets, `std::binary_search` offers a more efficient solution. It leverages the binary search algorithm, providing logarithmic time complexity for sorted containers. Unlike linear search, binary search narrows down the search space by repeatedly dividing it in half. This algorithm is applicable to arrays, vectors, and other sorted containers.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sortedNumbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    bool found = std::binary_search(sortedNumbers.begin(), sortedNumbers.end(), target);

    if (found) {
        std::cout << "Element " << target << " found." << std::endl;
    } else {
        std::cout << "Element " << target << " not found." << std::endl;
    }

    return 0;
}
```

This code performs a binary search on the `sortedNumbers` vector to check if the `target` element is present. The result is stored in the boolean variable `found`.

You can also play with the `<chrono>` library in C++ to calculate and see the time difference between a linear search and a logarithmic search. Try to read about the library from [here](https://en.cppreference.com/w/cpp/chrono) and you can implement the same.

## Merge

The `std::merge` algorithm is used to merge two sorted ranges into a single sorted range. This is particularly useful when dealing with multiple sorted containers and needing to merge them efficiently.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> first = {1, 3, 5, 7, 9};
    std::vector<int> second = {2, 4, 6, 8, 10};
    std::vector<int> result;

    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(result));

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
```

In the above code, the `merge` function takes the ranges defined by the iterators (`first.begin()` to `first.end()` and `second.begin()` to `second.end()`) and combines them into a sorted order, inserting the result into the `result` vector using `std::back_inserter`. Finally, a loop is used to iterate through the elements of the merged vector (`result`), and each element is printed to the standard output. The output of this specific code would be "1 2 3 4 5 6 7 8 9 10," representing the sorted merge of the two original vectors.

Additionally, if the numbers in the input ranges are the same, the `std::merge` algorithm maintains the relative order of equivalent elements. This means that if there are duplicates, the order in which they appear in the merged range reflects their order in the original ranges. For example, if the 'first' vector contained {1, 3, 5, 7, 9} and the 'second' vector contained {2, 4, 6, 7, 8, 10}, the merged result would be "1 2 3 4 5 6 7 7 8 9 10" with the repeated '7' appearing in the merged sequence.

## Unique elements

The `std::unique` algorithm in the C++ is employed to eliminate consecutive duplicate elements from a sorted range. After using `std::unique`, you typically need to use the erase method to remove the excess elements. The uniqueness is determined based on the equality comparison between consecutive elements. The algorithm moves the duplicate elements to the end of the range, and it returns an iterator pointing to the last element of the unique sequence. Subsequently, the excess elements can be removed using the `erase` method.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sortedNumbers = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 8};

    auto uniqueEnd = std::unique(sortedNumbers.begin(), sortedNumbers.end());

    sortedNumbers.erase(uniqueEnd, sortedNumbers.end());

    std::cout << "Unique elements: ";
    for (int num : sortedNumbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In the above code snippet, `std::unique` is applied to the `sortedNumbers` vector, removing consecutive duplicates. The excess elements are then erased using the `erase` method, leaving behind a vector containing only the unique elements. Finally, the unique elements are displayed using a simple loop.

This `std::unique` algorithm is particularly useful when working with sorted containers, helping streamline and optimize the removal of duplicate elements. It's essential to note that while `std::unique` excels in handling sorted containers, its efficiency diminishes when dealing with unsorted ones. The algorithm relies on the order of elements for its effectiveness. In an unsorted container, duplicates may not be adjacent, and the algorithm might not identify and eliminate them as intended. Let's take an example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> unsortedNumbers = {5, 2, 8, 5, 3, 2, 4, 1, 4, 3};

    auto uniqueEnd = std::unique(unsortedNumbers.begin(), unsortedNumbers.end());

    unsortedNumbers.erase(uniqueEnd, unsortedNumbers.end());

    std::cout << "Unique elements (not effective for unsorted): ";
    for (int num : unsortedNumbers) {
        std::cout << num << " ";
    }

    return 0;
}
```

In this example, std::unique fails to effectively remove duplicates from the unsorted container. Therefore, when working with unsorted containers, alternative approaches, such as sorting the container first, may be necessary for optimal duplicate removal.

## Union

The `std::set_union` algorithm computes the union of two sets and stores the result in another container. This is particularly useful when dealing with sets and wanting to find the union efficiently.

```cpp
#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};
    std::set<int> unionSet;

    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   std::inserter(unionSet, unionSet.begin()));

    for (int num : unionSet) {
        std::cout << num << " ";
    }

    return 0;
}
```

The above code utilizes the `std::set_union` algorithm to compute the union of two sets (`set1` and `set2`). The sets contain integers, and the resulting union is stored in the `unionSet`. The `std::inserter` function is used to insert elements into the `unionSet`, ensuring that it remains sorted. Finally, a loop iterates through the `unionSet` and prints the merged, sorted elements to the console. In this specific example, the output would be "1 2 3 4 5 6 7," demonstrating the combination of unique elements from both sets while maintaining ascending order.

## Intersection

The `std::set_intersection` algorithm computes the intersection of two sets and stores the result in another container. This is useful for finding common elements between sets.

```cpp
#include <iostream>
#include <set>
#include <algorithm>

int main() {
    std::set<int> set1 = {1, 2, 3, 4, 5};
    std::set<int> set2 = {3, 4, 5, 6, 7};
    std::set<int> intersectionSet;

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          std::inserter(intersectionSet, intersectionSet.begin()));

    for (int num : intersectionSet) {
        std::cout << num << " ";
    }

    return 0;
}
```

The above code demonstrates the use of the `std::set_intersection` algorithm to find the intersection of two sets (`set1` and `set2`) and store the result in a new set (`intersectionSet`). The sets contain integers, and the algorithm efficiently identifies and inserts the common elements into the `intersectionSet`. The final step involves iterating through `intersectionSet` and printing the common elements to the console. In this specific example, the output would be "3 4 5," representing the elements that exist in both `set1` and `set2`.