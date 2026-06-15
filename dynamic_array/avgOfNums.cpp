#include <iostream>
using namespace std;

int main() {
    int* nums = nullptr;
    int size = 0, input;
    char choice;

    do {
        cout << "Enter a number " << endl;
        cin >> input;

        int* temp = new int[size + 1];

        for (int i = 0; i < size; i++) {
            temp[i] = nums[i];
        }

        temp[size] = input;

        delete[] nums;

        nums = temp;

        size++;

        cout << "Do you want to enter more?" << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }

    double avg = sum / size;

    cout << "Average of these numbers is " << avg << endl;

    delete[] nums;

    return 0;
}