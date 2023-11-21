#ifndef __CARPRESENCETASK__
#define __CARPRESENCETASK__

#include "Task.h"
#include "components/Sonar.h"
#include "components/Pir.h"
//#include "components/Servo.h"
#include "components/ButtonImpl.h"
#include "components/Lcd.h"
#include "components/servo_motor.h"

class CarPresenceTask: public Task{
    public:
        CarPresenceTask();
        void tick();

    private:
        enum {SLEEP, CHECKIN, ENTERED, WASHING, CHECKOUT} state;
        void setState(int state);
        Sonar* sonar;
        Pir* pir;
        ServoMotor* servo;
        Button* button;
        Lcd* lcd;

};
#endif 