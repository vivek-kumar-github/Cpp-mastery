#include <iostream>

int main() {
    //std::getline()
    std::cout << "Enter your full name " << std::endl;
    std::string s2;
    std::getline(std::cin, s2);
    std::cout << "Hello " << s2 << std::endl;

    return 0;
}