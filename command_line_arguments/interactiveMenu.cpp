#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        cout << "1. Option 1" << endl;
        cout << "2. Option 2" << endl;
        cout << "3. Option 3" << endl;
        cout << "4. Quit" << endl;
        cout << "enter your choice" << endl;
        cin >> choice;
        cout << "##################" << endl;

        switch (choice) {
            case 1:
                cout << "You chose option 1" << endl;
                break;
            case 2:
                cout << "You chose option 2" << endl;
                break;
            case 3:
                cout << "You chose option 3" << endl;
                break;
            case 4:
                break;
            default:
                cout << "Invalid input please choose from the menu" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}