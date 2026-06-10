#include <iostream>
using namespace std;

class Box {
    private:
        int length;
        int width;
    
    public:
        Box &setLength(int length) {
            this->length = length;
            return *this;
        }

        Box &setWidth(int width) {
            this->width = width;
            return *this;
        }

        int getLength() {
            return this->length;
        }
        
        int getWidth() {
            return this->width;
        }
};

int main() {
    Box box;
    
    box.setLength(10).setWidth(20);

    cout << "Length is " << box.getLength() << endl << "Width is " << box.getWidth() << endl;

    return 0;
}