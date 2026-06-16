**Strings** are an essential data type in programming languages that represent text. In C++, strings are essential to handle and manipulate textual data. Here is an example of a string: "Hello, World". This string is a sequence of 12 characters, including one space.

## C-Style string

As you know, C++ is a descendant of the C language (initially, C++ was an extension of the C programming language). Therefore, in C++, you can use **C-style strings**. In C++, C-style strings refer to null-terminated character arrays that represent strings of characters. These strings are often referred to as "C-strings". Here's an example of working with C-style strings:

```cpp
#include <iostream>

int main() {
    char greeting[] = "Hello, world!";  // Declare and initialize a C-style string

    std::cout << greeting << std::endl;  // Output: Hello, world!
    greeting[7] = 'C';
    std::cout << greeting << std::endl;  // Output: Hello, Corld!

    return 0;
}
```

In the above example, you declare the C-style string `greeting` as a character array and initialize it with the string "Hello, world!". C-style strings are mutable, so you can modify individual characters in the array.

C-style strings have some limitations. They are fixed in size and require manual memory management. Additionally, they lack built-in functions for common string operations such as concatenation or comparison.

In modern C++, it's often better to use `std::string` for safer and more convenient string manipulation.

## Strings (std::string)

To overcome the limitations of C-style strings, C++ provides the `std::string` class as part of the C++ Standard Library. The `std::string` class offers a more flexible and convenient way to work with strings. It provides a dynamic length, automatic memory management, and a wide range of built-in functions for string manipulation.

Here's an example of using `std::string`:

```cpp
#include <iostream>

int main() {
    std::string message = "Hello, World!";

    std::cout << message << std::endl;  // Output: Hello, world!
    message[7] = 'C';
    std::cout << message << std::endl;  // Output: Hello, Corld!

    message += " Welcome to C++!"; // So just concatenate two strings.
    std::cout << message << std::endl; // Output: Hello, Corld! Welcome to C++!

    return 0;
}
```

Like C-strings, `std::string` still allows you to access elements by index and change the value if necessary.

## Input/output strings

To output a string to the console or any output stream, you can use the `<<` operator with the string or string variable as the right operand. And to read a string from the user or an input stream, you can use the `>>` operator. This allows you to store the user's input or the content from the input stream into a string variable.

```cpp
#include <iostream>

int main() {
    std::string fullName;
    std::cout << "Enter your name: ";
    std::cin >> fullName; // Input: Mike Wazowski
    std::cout << "Hello, " << fullName << "!" << std::endl; // Output: Hello, Mike!
    
    return 0;
}
```

If you look closely at the above example (and run it on your own), you'll notice that we're typing `Mike Wazowski` and the output is `Hello, Mike!`. It's important to note that the input operation stops at the first whitespace character encountered. If you want to read an entire line of text, including spaces, use the `std::getline()` function:

```cpp
#include <iostream>

int main() {
    std::string fullName;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName); // Input: Mike Wazowski
    std::cout << "Hello, " << fullName << "!" << std::endl; // Output: Hello, Mike Wazowski!
    
    return 0;
}
```

Still, all is not well in the `std::getline()` kingdom🧐. You will look at this in more detail below.

## std::cin.ignore()

And now, let's just try to request the age, and then the name:

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;

    std::cout << "Now enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << "and your age: " << age << '\n';

    return 0;
}
```

And you get `Now enter your name: Hello, and your age: 50`. Wait, what?

When using `std::getline()` to read input with `std::cin`, there is an important consideration to keep in mind. By default, the newline character (`'\n'`) is left in the input stream after the extraction operation. This can cause issues if you have subsequent input operations that expect clean input.

In simpler words, after the entered age, you press `enter`, and it leaves its mark in the form of `'\n'`, which hangs in the stream and is transferred to `name`.

To address this, you can use `std::cin.ignore()` to clear any remaining characters in the input stream, including the newline character.

After using `std::getline()` or `std::cin`, it's a good practice to call `std::cin.ignore()` to discard any remaining characters in the input stream, particularly the newline character. This ensures that subsequent input operations behave as expected.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    std::cin.ignore();

    std::cout << "Now enter your name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << " and your age: " << age << '\n';

    return 0;
}
```

By default, `std::getline()` uses the newline character (`'\n'`) as the delimiter to determine the end of the line. However, you can specify a different delimiter if needed.

When using `std::getline()` with `std::cin`, it's important to handle the newline character in the input stream to avoid unexpected behavior. By calling `std::cin.ignore()` after using `std::getline()`, you can ensure that subsequent input operations are not affected by any remaining characters in the input stream.

## Useful methods of strings

The `std::string` class provides a rich set of member functions and operators to manipulate strings. These include functions for string concatenation, substring extraction, finding characters or substrings within a string, and many others. Here are some commonly used methods:

| 
№

 | 

Method

 | 

Description

 | 

Example Usage

 |
| --- | --- | --- | --- |
| 

1

 | 

`size()` or `length()`

 | 

Returns the size or length of the string.

 | 

int len = str.size();

int len = str.length();

 |
| 

2

 | 

`clear()`

 | 

Clears the contents of the string.

 | 

str.clear();

 |
| 

3

 | 

`append(str)`

 | 

Adds the string str to the end of the current string.

 | 

str.append("Hello");

 |
| 

4

 | 

`insert(pos, str)`

 | 

Inserts the string str at the specified position pos in the string.

 | 

str.insert(2, "world");

 |
| 

5

 | 

`erase(pos, len)`

 | 

Erases a portion of the string starting at position pos with a length of len.

 | 

str.erase(1, 3);

 |
| 

6

 | 

`substr(pos, len)`

 | 

Returns a substring of the string starting at position pos with a length of len.

 | 

string sub = str.substr(0, 5);

 |
| 

7

 | 

`find(str, pos)`

 | 

Searches for the first occurrence of the substring str in the string, starting from position pos.

 | 

int index = str.find("world");

 |
| 

8

 | 

`compare(str)`

 | 

Compares the string with another string str and returns `0` if they are equal, a positive value if the string is greater, or a negative value if the string is smaller.

 | 

int result = str.compare("Hello");

 |

These are just a few examples of the many methods available for working with strings in C++. Each method provides specific functionality that can be useful for string manipulation and processing.

## C-style vs std::string

Strings (`std::string`) in C++ offer several advantages over C-style strings:

1. Safety: Strings in C++ (`std::string`) provide safe memory handling. They automatically manage memory allocation and deallocation, avoiding buffer overflow issues commonly encountered with C-style strings.
 
2. Ease of use: Strings in C++ offer a wide range of built-in functions for string manipulation. They support concatenation, comparison, splitting, substring extraction, and more. This makes working with strings simpler and more convenient.
 
3. Dynamic resizing: Strings in C++ allow dynamic resizing during program execution.
 
4. Integration with other functions and libraries: Strings in C++ integrate well with other functions and components of the C++ Standard Library.
 
5. Unicode support: Strings in C++ support multiple encodings, including Unicode. They enable working with characters from different languages and using special symbols without issues.
 

Overall, using Strings in C++ (`std::string`) is recommended as they provide safety, convenience, and functionality, making string operations easier and more reliable compared to C-style strings.

## Conclusion

In this topic, you explored the concept of strings in C++. You looked into the limitations of C-style string constants and the advantages of using the `std::string` class provided by the C++ Standard Library. By using `std::string`, you can dynamically manage strings, perform various string operations, and write more robust and flexible C++ programs.

Understanding how to work with strings is crucial for many applications that involve text processing and manipulation. By leveraging the power of `std::string`, you can handle string data efficiently and write code that is more readable and maintainable.