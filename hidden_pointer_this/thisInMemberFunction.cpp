#include <iostream>
using namespace std;

class Box {
    private:
        int length;

    public:
        void setLength(int length) {
            this->length = length;
        }

        int getlength() {
            return this->length;
        }
};

int main() {
    Box box;
    box.setLength(25);

    cout << "length of box is " << box.getlength() << endl;

    return 0;
}