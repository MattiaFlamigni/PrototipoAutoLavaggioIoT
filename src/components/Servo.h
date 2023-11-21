#ifndef __SERVO__
#define __SERVO__
#include "config.h"
class Servo {

    public:
        Servo(int pin);
        void openGate();
        void closeGate();

    private:
        int pin;

  
};


#endif