#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> lst;
    while (1) {
        string a;
        cin >> a;
        if (a == "end") {
            break;
        } else {
            lst.push_back(a);
        }
    }
    cout << "Elements in the list:" << endl;
    for (string x : lst) {
        cout << x << endl;
    }
}