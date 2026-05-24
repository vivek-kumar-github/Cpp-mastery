#include <iostream>
#include <list>
using namespace std;

int main() {
    // std::list is a doubly-linked list container. It stores elements in nodes that are connected in a bidirectional manner
    // offering efficient insertions and deletions at both ends

    list<string> myList;

    myList.push_front("Vivek"); // Add an element to the front
    myList.push_back("Kumar"); // Add an element to the end
    myList.push_front("Hello");

    cout << myList.size() << endl;
    cout << myList.empty() << endl;

    for (string x : myList) {
        cout << x << " ";
    }

    myList.clear();
}