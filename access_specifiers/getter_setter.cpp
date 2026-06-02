#include <iostream>
using namespace std;

class Car {
    private:
        int m_speed;

        double convertKmph2Mph() {
            return m_speed / 1.61;
        }
    
    public:
        void setSpeed(int speed) {
            m_speed = speed;
        }

        void printSpeed() {
            cout << "Your speed is " << m_speed << endl;
        }

        void printSpeedInMph() {
            cout << "Speed in Mph " << convertKmph2Mph() << endl;
        }
};

int main() {
    Car myCar;

    myCar.setSpeed(150);

    myCar.printSpeed();

    myCar.printSpeedInMph();

    return 0;
}