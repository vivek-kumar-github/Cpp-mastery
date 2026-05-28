#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> stuAge;

    stuAge["Maria"] = 25;
    stuAge["Adam"] = 29;
    stuAge["David"] = 32;

    cout << "David's Age is " << stuAge["David"] << " Years" << endl;

    return 0;
}