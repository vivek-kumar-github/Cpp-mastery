#include <iostream>
#include <fstream>
int main() {
    std::string filename = "file.txt";
    std::string content = "Hello! from file.txt\nAnother line in file.txt";
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error during opening file" << std::endl;
        return 1;
    }
    file << content;
    std::cout << "Content successfully writen in file" << std::endl;
    return 0;
}