#include <iostream>

class DoorLock {
    private:
        std::string passcode;
    
    public:
        DoorLock(std::string a) {
            passcode = a;
        }

        bool checkPasscode(std::string inp) {
            return passcode == inp;
        }
};

int main() {
    DoorLock d1("qwerty");
    
    std::cout << d1.checkPasscode("qwerty") << std::endl;
}