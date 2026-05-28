#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStk;

    myStk.push(1);
    myStk.push(2);
    myStk.push(3);

    cout << "Top of stack " << myStk.top() << endl;

    cout << "Stack Elements " << endl;
    while (!myStk.empty()) {
        cout << myStk.top() << " ";
        myStk.pop();
    }

    return 0;
}