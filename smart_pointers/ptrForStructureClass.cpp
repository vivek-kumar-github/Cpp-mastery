#include <iostream>
#include <memory>
using namespace std;

struct MyStruct {
    int value;
};

int main() {
    unique_ptr<MyStruct> ptr(new MyStruct);

    ptr->value = 35;

    cout << "Value " << ptr->value << endl;

    return 0;
}