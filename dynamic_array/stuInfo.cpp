#include <iostream>
using namespace std;

int main() {
    string* name = nullptr;
    int* grade = nullptr;
    int* count = nullptr;

    int numStu;
    cout << "Enter number of students " << endl;
    cin >> numStu;

    name = new string[numStu];
    grade = new int[numStu];
    count = new int[numStu];

    for (int i = 0; i < numStu; i++) {
        cout << "Enter student " << i + 1 << " name:- " << endl;
        cin >> name[i];

        cout << "Enter grades of " << name[i] << ": " << endl;
        cin >> grade[i];

        count[i] = i + 1;
    }

    cout << "Entered data " << endl;

    for (int i = 0; i < numStu; i++) {
        cout << "Student " << i + 1 << ": " << name[i] << ", Grade: " << grade[i] << endl;
    }

    delete[] name;
    delete[] grade;
    delete[] count;

    return 0;
}