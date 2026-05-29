#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    float height;
};

void printPersonInfo(Person person) {
    cout << "Name:-   " << person.name << endl;
    cout << "Age:-    " << person.age << endl;
    cout << "Height:- " << person.height << endl << endl;
}

int main() {
    Person mike { "Mike Wazowski", 45, 1.2 };
    Person james { "James P. Sullivan", 47, 2.2 };

    printPersonInfo(mike);
    printPersonInfo(james);

    return 0;
}