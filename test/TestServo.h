#ifndef __TESTSERVO__
#define __TESTSERVO

#include "components/servo_motor_impl.h"
class TestServo {
    public:
        TestServo();
        void testOpenGate();
        void testCloseGate();
    
    private:
        int pin;
        ServoMotorImpl* servo;
        
};
#endif