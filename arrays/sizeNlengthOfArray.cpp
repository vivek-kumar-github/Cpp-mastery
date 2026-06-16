#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    int size = sizeof(arr);
    cout << "Size of array in bytes " << size << endl;

    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of array " << length << endl;

    return 0;
}