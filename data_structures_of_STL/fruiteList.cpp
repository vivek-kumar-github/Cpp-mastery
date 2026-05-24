#include <iostream>
#include <list>
int main() {
    std::list<std::string> fruits;
    fruits.push_back("apple");
    fruits.push_back("banana");
    fruits.push_back("cherry");
    fruits.push_front("watermelon");

    for (std::string fruit : fruits) {
        std::cout << fruit << " ";
    }

    std::cout << std::endl;
    return 0;
}