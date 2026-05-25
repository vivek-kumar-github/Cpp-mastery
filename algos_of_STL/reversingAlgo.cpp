#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::reverse(numbers.begin(), numbers.end());

    std::cout << "Reverse order ";

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}