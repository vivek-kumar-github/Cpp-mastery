#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;

    int* arr = new int[q];
    
    for (int i = 0; i < q; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}