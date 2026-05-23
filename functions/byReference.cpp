#include <iostream>
using namespace std;

void byRef(int &num) {
    num += 5; // Changes here will affect the original value
    cout << "Value of num in function " << num << endl;
}

int main() {
    int num;
    cin >> num;
    byRef(num);
    cout << "Value of num in main " << num << endl;
    return 0;
}