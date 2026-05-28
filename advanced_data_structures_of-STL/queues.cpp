#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> myQ;

    myQ.push("One");
    myQ.push("Two");
    myQ.push("Three");
    myQ.push("Four");

    cout << "Front of Queue " << myQ.front() << endl;
    cout << "Back of Queue " << myQ.back() << endl;

    cout << "Queue elemts:- " << endl;

    while (!myQ.empty()) {
        cout << myQ.front() << " ";
        myQ.pop();
    }

    return 0;
}