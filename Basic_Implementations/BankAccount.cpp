#include <iostream>
using namespace std;

class BankAccount {
    private:
        int balance;

    public:
        BankAccount(int initialBalance) {
            if (initialBalance >= 0) {
                balance = initialBalance;
            } else {
                balance = 0;
                cout << "Invalid initial balance set to 0" << endl;
            }
        }

        void deposit(int amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposited " << amount << endl;
            } else {
                cout << "Invalid deposit " << endl;
            }
        }

        void withdraw(int amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdrew " << amount << endl;
            } else {
                cout << "Invalid withdrawal " << endl;
            }
        }

        void getBalance() {
            cout << "Balance : " << balance << endl;
        }
};

int main() {
    BankAccount myAccount(121);
    myAccount.deposit(10);
    myAccount.getBalance();
    myAccount.withdraw(150);
    myAccount.getBalance();
}