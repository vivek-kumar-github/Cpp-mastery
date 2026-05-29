#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Point p1 { x1, y1 };
    Point p2 { x2, y2 };

    int dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    cout << dist;

    return 0;
}