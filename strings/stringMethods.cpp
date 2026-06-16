#include <iostream>

int main() {
    std::cout << "Enter a string " << std::endl;
    std::string str;
    std::getline(std::cin, str);

    std::cout << "Size of the string is " << str.length() << std::endl; //can also use str.size()

    std::cout << "'Hello' appended to the string:- " << str.append("Hello") << std::endl;

    std::cout << "'ILI' inserted at position 2:- " << str.insert(2, "ILI") << std::endl;

    std::cout << "'ILI' erased from position 2 to length 3:- " << str.erase(2, 3) << std::endl;

    std::cout << "Substring starting from 2 and of 3 length:- " << str.substr(2, 3) << std::endl;

    std::cout << "Searches for the first occurrence of 'ek' starting from position 2:- " << str.find("ek", 2) << std::endl;

    std::cout << "Compares with another string 'kumar' and returns 0 for equal, a positive value for greater, or a negative for smaller:- " << str.compare("kumar") << std::endl;

    return 0;
}