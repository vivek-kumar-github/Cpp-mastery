#include <iostream>
using namespace std;

int main() {
    int arr[3];
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    
    int div;
    cin >> div;
    
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += arr[i];
    }

    int ans = sum / div;

    cout << ans;

    return 0;
}