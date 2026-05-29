#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int width;
};

int main() {
    int len, wid;
    cin >> len >> wid;

    Rectangle rectangle {len, wid};

    int area = rectangle.length * rectangle.width;

    cout << area;

    return 0;
}