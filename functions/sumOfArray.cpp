#include <iostream>

int calculate(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {1, 1, 2, 3, 4};
    int size = 5;
    int result = calculate(arr, size);
    std::cout << "Sum of array elements is " << result << std::endl;
    return 0;
}