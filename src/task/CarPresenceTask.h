#ifndef __CARPRESENCETASK__
#define __CARPRESENCETASK__

#include "Task.h"
#include "components/Sonar.h"
#include "components/Pir.h"
//#include "components/Servo.h"
#include "components/ButtonImpl.h"
#include "components/Lcd.h"
#include "components/servo_motor.h"
#include "components/Led.h"
#include "MyNonBlockingDelay.h"

class CarPresenceTask: public Task{
    public:
        CarPresenceTask(Task* blink, Task* temperature );
        void tick();

    private:
        enum {SLEEP, CHECKIN, ENTERED, WASHING, CHECKOUT} state;
        void setState(int state);
        Sonar* sonar;
        Pir* pir;
        ServoMotor* servo;
        Button* button;
        Lcd* lcd;
        Led* G1;
        Led* G2;
        Led* R;
        Task* blink;
        Task* temperature;

        MyNonBlockingDelay* delay;



};
#endif 