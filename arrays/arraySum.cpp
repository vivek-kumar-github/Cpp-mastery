#include <iostream>
using namespace std;

int main() {
    int s = 0;
    cin >> s;

    int arr[s];
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < s; i++) {
        sum += arr[i];
    }

    cout << sum;

    return 0;
}