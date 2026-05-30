#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

void print(Date date) {
    cout << date.day << "-" << date.month << "-" << date.year << endl;
}

int main() {
    Date date {30, 5, 2026};
    print(date);

    date.day = 31;
    print(date);

    return 0;
}