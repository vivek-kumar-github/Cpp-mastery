In C++, data manipulation often requires efficient and organized structures. Stacks, queues, sets and maps are fundamental data structures provided by the Standard Template Library (STL) other than vectors, and lists, each serving a unique purpose. Stacks allow for last-in, first-out (LIFO) data handling, queues follow the first-in, first-out (FIFO) principle, sets manage distinct, sorted elements whereas maps allow you to store key-value pairs. Now, let's jump into understanding stacks, queues, sets, and maps in STL.

## Maps

Maps are a type of associative container in STL, and they allow you to store key-value pairs. Each element in a map consists of a key and an associated value, providing efficient lookup and retrieval of data.

A crucial characteristic of maps is that each key must be distinct; there cannot be duplicate keys. However, multiple keys can map to the same value.

The map automatically organizes elements by key, allowing you to quickly perform search operations by key. When a map organizes elements, it ensures that when a specific key is requested, the search will be performed efficiently and quickly. The search time in `std::map` has a complexity of O(log(N))O(log(N))O(log(N)), where N is the number of elements in the container. This makes `std::map` useful for searching and manipulating data where the order of the keys matters.

To utilize `std::map`, you first need to include the `<map>` header in your C++ program. Once that's done, you can create a map with a specified key type and value type. In the example provided, we're using a `std::map<std::string, int>`, which means our map associates strings (keys) with integers (values).

**Syntax to declare a map:**`std::map<KeyType, ValueType> mapName;` Here, `KeyType` is the data type of the keys, and `ValueType` is the data type of the associated values. (e.g., `std::string`, `int`).

Now, let's see the key features of maps:

- Elements are organized based on unique keys.

- Fast key-based access and retrieval.

- Ideal for use cases where you need to associate data with unique identifiers.


Let's explore how to perform two essential operations: inserting data into the map and retrieving data from it.

**Inserting Key-Value Pairs:**

```cpp
ages["Alice"] = 25;   // Insert a key-value pair
```

- In this line, we're using the subscript operator (`[]`) to insert a key-value pair into the `ages` map. The key is `"Alice"`, and the associated value is `25`.

- If the key `"Alice"` doesn't exist in the map, it will be added, and the value `25` will be associated with it. If the key already exists, its associated value will be updated.


**Retrieving Values by Keys:**

```cpp
int aliceAge = ages["Alice"];  // Retrieve a value by key
```

- Here, we use the subscript operator again to retrieve a value from the `ages` map. We specify "Alice" as the key and the associated value (Alice's age) is returned and stored in the variable `aliceAge`.

- Remember that if you attempt to access a key in a `std::map` that does not exist, the map will insert an element with that key and a default value. The default value depends on the type of the value associated with the `std::map`. For primitive data types, the default value is typically 0 (for integers) or an empty value (for strings).


Let's take an example of maps to understand better:

```cpp
#include <iostream>
#include <map>

int main() {
    // Creating a map of students and their ages
    std::map<std::string, int> studentAges;

    // Adding elements to the map
    studentAges["Maria"] = 29;
    studentAges["Adam"] = 25;
    studentAges["David"] = 27;

    // Accessing elements by key
    std::cout << "David's age: " << studentAges["David"];

    return 0;
}
```

Here's the result of the above code snippet:

```bash
David's age: 27
```

## Stacks and Queues

In C++, both stacks and queues are commonly used data structures to manage elements in specific orders. They offer fast and efficient access to elements according to the Last-In-First-Out (LIFO) and First-In-First-Out (FIFO) principles, respectively.

A `std::stack` in C++ follows the Last-In-First-Out (LIFO) principle. This means that the last element added to the stack is the first one to be removed. Stacks are commonly used in scenarios where you need to manage elements in a specific order, such as tracking function calls or managing the history of an application.

**Syntax to declare a stack:**`std::stack<DataType> stackName;` Here, `DataType` is the type of data the stack will hold (e.g., `int`, `double`, `string`).

Operations on a stack: `push()`, `pop()`, `top()`.

A `std::queue` in C++ follows the First-In-First-Out (FIFO) principle, meaning that the first element added is the first one to be removed. It's useful for implementing algorithms like breadth-first search (BFS) and various other scenarios where you need to process items in the order they were added.

**Syntax to declare a queue:**`std::queue<DataType> queueName;` Here, `DataType` is the type of data the queue will hold (e.g., `int`, `double`, `string`).

Operations on a queue: `push()`, `pop()`, `front()`, `back()`.

Here's a simple example that demonstrates both stack and queue operations:

```cpp
#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::stack<int> myStack;  //  Create a stack of integers
    std::queue<std::string> myQueue;  //  Create a queue of strings

    //  Stack operations
    myStack.push(1);  //  Push 1 onto the stack
    myStack.push(2);  //  Push 2 onto the stack
    int topStack = myStack.top();  //  Access the top element (2) without removing it
    myStack.pop();  //  Remove the top element (2)

    //  Queue operations
    myQueue.push("apple");  //  Push "apple" to the back of the queue
    myQueue.push("banana");  //  Push "banana" to the back of the queue
    std::string frontQueue = myQueue.front();  //  Access the front element ("apple")
    myQueue.pop();  //  Remove the front element ("apple")

    // Print the stack
    std::cout << "Stack elements: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Print the queue
    std::cout << "Queue elements: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
```

Here's the output:

```bash
Stack elements: 1
Queue elements: banana
```

## Sets

Sets are containers designed to hold a collection of unique elements. Each element within a set must be distinct, ensuring that there are no duplicate values. Sets are ideal for applications where maintaining a collection of distinct values is crucial. Unlike other containers, the specific order of elements in a set is not significant.

By default, sets store elements in ascending order, which might give the impression of sorting. However, the key feature of sets is their guarantee of uniqueness rather than a strict requirement for sorting.

In essence, you can think of a set as a data structure that behaves similarly to a map, but without associated values.

**Syntax to declare a set:**`std::set<DataType> setName;` Here, `DataType` is the type of data the set will hold (e.g., `int`, `double`, `char`).

You can also perform the below operations on a set:

- `insert()`: Add elements to the set.

- `erase()`: Remove elements from the set.

- `find()`: Search for elements efficiently.

- `size()`: Get the number of elements in the set.


```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers;

    uniqueNumbers.insert(1);
    uniqueNumbers.insert(5);
    uniqueNumbers.insert(1);  // Won't insert, as it's a duplicate.

    for (const int& number : uniqueNumbers) {
        std::cout << number << " ";
    }

    return 0;
}
```

Here's the result,

```cpp
1 5
```

In the above example, a `std::set` named `uniqueNumbers` is created. We insert three integers: 1, 5, and 1. However, the set only retains unique values, so the second insertion of 1 is ignored as it's a duplicate. Finally, we iterate through the `uniqueNumbers` set and print the values. The output will be `1 5` as duplicates are automatically removed, resulting in a collection of distinct, sorted elements.

Here are the key features of sets in C++ and why you should use them:

- Sets in C++ automatically maintain a sorted order of elements and ensure that only unique values are stored, simplifying tasks that require data organization and consistency.

- Searching for an element or checking its availability in a set is fast due to the binary search tree structure (that you'll study in advanced topics), making sets an efficient choice for data retrieval.

- Sets provide built-in support for set operations, such as intersection and union, which simplifies tasks that involve combining or comparing multiple sets of data.


## Container selection

**1\. Maps**

- Time Complexity: O(log n) for insertion, deletion, and searching operations, where n is the number of elements in the map.

- When to Use:

  - Use maps when you need to associate unique keys with values and require efficient key-based access and retrieval.

  - Maps are suitable for scenarios where data organization and quick lookups are critical.

  - If you need to maintain elements in sorted order based on keys.
- Maps vs. Other Containers:

  - Maps are different from vectors and lists as they store key-value pairs. Vectors and lists are primarily for storing sequences of elements, while maps are for key-value associations.

  - If you need fast access to data based on unique identifiers (keys), maps are a better choice compared to lists or vectors, which are not designed for key-based retrieval.

**2\. Stacks and queues**

- Time Complexity: Stacks and Queues offer O(1) time complexity for basic operations like push, pop, front, and back.

- When to Use:

  - Use a stack (LIFO) when you need to manage elements in a specific order, like tracking function calls or managing the history of an application.

  - Use a queue (FIFO) when you need to process items in the order they were added, such as implementing breadth-first search (BFS) or managing task queues.
- Stacks and Queues vs. Other Containers:

  - Stacks and queues are specialized containers designed for specific use cases where the order of elements matters.

  - Stacks are suitable for scenarios where the last-in-first-out order is essential, and queues are ideal for maintaining a first-in-first-out order.

  - If you need fast access to the most recently added or removed element, stacks and queues are efficient choices over lists or vectors.

**3\. Sets**

- Time Complexity: O(log n) for insertion, deletion, and searching operations, where n is the number of elements in the set.

- When to Use:

  - Use sets when you need to maintain a collection of unique, sorted elements.

  - Sets are useful for scenarios where you require a collection of distinct values, and the order of elements doesn't matter.

  - When you need to efficiently search for elements, check for their availability, or perform set operations like intersection and union.
- Sets vs. Other Containers:

  - Sets are distinct from vectors and lists as they focus on unique and sorted elements.

  - While vectors and lists are designed for sequences of elements, sets prioritize uniqueness and sorting.

  - If your program needs to ensure that a collection contains only distinct values, and you need to search for elements efficiently, sets are a better choice compared to vectors and lists, which don't guarantee uniqueness and have different performance characteristics.