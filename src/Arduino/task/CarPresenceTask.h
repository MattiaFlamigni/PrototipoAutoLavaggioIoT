#ifndef __CARPRESENCETASK__
#define __CARPRESENCETASK__

#include "Arduino/kernel/Task.h"
#include "Arduino/components/Sonar.h"
#include "Arduino/components/Pir.h"
//#include "components/Servo.h"
#include "Arduino/components/ButtonImpl.h"
#include "Arduino/components/Lcd.h"
#include "Arduino/components/servo_motor.h"
#include "Arduino/components/Led.h"
#include "Arduino/util/MyNonBlockingDelay.h"
#include "Arduino/util/PowerManager.h"
#include "Arduino/kernel/MsgService.h"

class CarPresenceTask: public Task{
    public:
        CarPresenceTask(Task* blink, Task* temperature );
        void tick();

    private:
        enum {SLEEP, DETECTED, CHECKIN, ENTERED, WASHING, CHECKOUT} state;
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

        PowerManager* power;
        MyNonBlockingDelay* delay;

        MsgServiceClass* msg;




};
#endif 