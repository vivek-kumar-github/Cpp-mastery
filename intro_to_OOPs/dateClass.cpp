#include <iostream>
using namespace std;

class DateClass {
    public:
        int day;
        int month;
        int year;

        void printEU() {
            cout << day << "-" << month << "-" << year << endl;
        }

        void printUS() {
            cout << year << "-" << month << "-" << day << endl;
        }
};

void printx(DateClass date) {
    cout << "Function outside of class " << date.day << "/" << date.month << "/" << date.year << endl;
    //But this does not belong to class so we have to explicitly pass the reference of class to it.
}
int main() {
    DateClass today {30, 05, 2026};

    today.day = 31;

    today.printEU();
    today.printUS();

    printx(today);

    return 0;
}