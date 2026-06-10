#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int[]> ptr(new int[5]{1, 2, 3, 4, 5});

    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " ";
    }

    return 0;
}