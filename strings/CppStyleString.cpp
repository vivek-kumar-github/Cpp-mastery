#include <iostream>

int main() {
    std::string message = "Hello, world!";
    std::cout << message << std::endl;

    message[7] = 'C';
    std::cout << message << std::endl;

    message += " Welcome to C++";
    std::cout << message << std::endl;

    return 0;
}