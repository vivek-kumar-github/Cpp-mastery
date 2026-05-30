#include <iostream>
using namespace std;

class DateClass {
    public:
        int day;
        int month;
        int year;

        void printEU(); //this is prototype and must be impemented
        void printUS();
};

void DateClass::printEU() {   //Implementation of prototype
    cout << day << "-" << month << "-" << year << endl;
}

void DateClass::printUS() {
    cout << year << "-" << month << "-" << day << endl;
}

int main() {
    DateClass today {30, 5, 2026};

    today.printEU();
    today.printUS();
    
    return 0;
}