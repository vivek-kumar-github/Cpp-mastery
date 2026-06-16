#include <iostream>

int main() {
    std::cout << "Enter your age " << std::endl;
    int age;
    std::cin >> age;
    std::cout << "Your age is " << age << std::endl;

    std::cin.ignore();

    std::string s3;
    std::cout << "Enter your name " << std::endl;
    std::getline(std::cin, s3);
    std::cout << "And your name is " << s3 << std::endl;

    return 0;
}