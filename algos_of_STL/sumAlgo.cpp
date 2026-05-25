#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "The sum is " << sum;

    return 0;
}