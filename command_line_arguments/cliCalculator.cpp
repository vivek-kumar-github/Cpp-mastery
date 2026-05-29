#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Invalid number of arguments!" << endl;
        cout << argc << endl;
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    char op = argv[3][0];

    int result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case 'm':
            result = num1 * num2;
            break;
        default:
            cout << "Invalid operator!" << endl;
            return 1;
    }

    cout << result << endl;

    return 0;
}