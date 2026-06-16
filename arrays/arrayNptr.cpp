#include <iostream>
using namespace std;

int main() {
    int nums[] = {1, 2, 3, 4, 5};

    int* ptr = nums;

    cout << "First element " << *ptr << endl;
    cout << "Second element " << *(ptr + 1) << endl;

    return 0;
}