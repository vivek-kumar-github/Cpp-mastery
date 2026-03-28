#include <iostream>
#include <fstream>
int main() {
    std::string filename = "file.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error in opening file for read" << std::endl;
        return 1;
    }
    std::string word;
    std::cout << "File content:--" << std::endl;
    while (file >> word) {
        std::cout << word << " ";
    }
    return 0;
}