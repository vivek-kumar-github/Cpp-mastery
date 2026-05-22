#include <iostream>
// using namespace std;
int main() {

    // The declaration, also known as the function prototype, provides information about the function's
    // name, return type, and parameters without specifying the implementation details
    
    int sum(int a, int b);
    int a, b;
    std::cin >> a >> b;
    int result = sum(a, b);
    std::cout << result;
    return 0;
}

int sum(int a, int b) {
    int result = a + b;
    return result;
}