#include <iostream>
using namespace std;

void byVal(int x) {
    x += 5; // Changes here won't affect the original value
    cout << "Value of x in function " << x << endl;
}

int main() {
    int x;
    cin >> x;
    byVal(x);
    cout << "Value of x in main " << x << endl;
    return 0;
}