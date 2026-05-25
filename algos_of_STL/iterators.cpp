#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::vector<int>::iterator it; // Declare an iterator

    for (it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << " "; // Dereference the iterator to access the element
    }

    return 0;
}