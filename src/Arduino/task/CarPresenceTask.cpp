#include <Arduino.h>
#include "Arduino/task/CarPresenceTask.h"
#include "Arduino/config.h"
#include "Arduino/components/Sonar.h"
#include "Arduino/components/Pir.h"

#include "Arduino/components/Lcd.h"
#include "Arduino/components/servo_motor_impl.h"
#include "Arduino/components/Led.h"
#include "Arduino/util/MyNonBlockingDelay.h"
#include <Time.h>
#include <avr/sleep.h>
#include "Arduino/kernel/MsgService.h"

#define DEBUG 0 // 0 - disable, 1 - enable

unsigned long startTime;
unsigned long countdownDuration = 5000; //  (5 secondi)
bool countdownActive = true;
bool updateTimer;
float distance = -1;

CarPresenceTask::CarPresenceTask(Task *blink, Task *temperature){
    this->blink = blink;
    this->temperature = temperature;
    this->sonar = new Sonar(ECHO_PIN, TRIG_PIN, SONAR_TIME);
    this->pir = new Pir(PIR_PIN);
    this->servo = new ServoMotorImpl(SERVO_PIN);
    servo->on();
    servo->setPosition(0);
    this->button = new ButtonImpl(START_BUTTON_PIN);
    this->lcd = new Lcd(SDA_PIN, SCL_PIN);
    lcd->clear();
    this->G1 = new Led(GREEN_LED_1);
    this->G2 = new Led(GREEN_LED_2);
    this->R = new Led(RED_LED);
    this->delay = new MyNonBlockingDelay();
    this->power = new PowerManager();
    this->msg = new MsgServiceClass();
    power->enablePIRInterrupt();
    setState(SLEEP);
    updateTimer = true;
}

void CarPresenceTask::tick(){

    switch (state){
    case SLEEP:
        if (DEBUG){
            lcd->display("Sleep");
            Serial.println("sleep");
        }
        // deep sleep method
        //power->sleep();
        setState(DETECTED);
        break;

    case DETECTED:
            lcd->clear();
            lcd->display("Welcome");
            G1->switchOn();
            delay->setDelay(N1);
            while(!delay->isDelayComplete()) {
                temperature->tick();
            }
            setState(CHECKIN);
        break;
    case CHECKIN:

        servo->setPosition(90);
        blink->setActive(true);

        lcd->clear();
        lcd->twoLineText("Proceed to the washing area");
        delay->setDelay(500); // set 2second waiting
        while (!delay->isDelayComplete()){
            distance = sonar->getDistance();
        }

        if (distance > 0 && distance <= MINDIST){
            setState(ENTERED);
        }
        break;

    case ENTERED:
        blink->setActive(false);
        if (DEBUG){
            Serial.println("entered");
        }
        servo->setPosition(0);
        // red on
        R->switchOn();
        lcd->clear();
        lcd->display("Ready to wash");
        if (button->isPressed()){

            setState(WASHING);
        }
        break;

    case WASHING:
        

        if (updateTimer){
            startTime = millis();
            updateTimer = false;
        }

        // red blink
        R->switchOff();
        blink->setActive(true);

        if (countdownActive){
            unsigned long currentTime = millis();
            unsigned long elapsedTime = currentTime - startTime;
            unsigned long remainingTime = countdownDuration - elapsedTime;

            if (remainingTime / 1000 > 0){
                lcd->clear();
                lcd->display(remainingTime / 1000);
            }
            else{
                countdownActive = false;
                msg->sendMsg("A: washing");
                setState(CHECKOUT);
            }
        }
        break;

    case CHECKOUT:
        countdownActive = true;
        countdownActive = true;
        lcd->clear();
        Serial.println("Checkout");
        servo->setPosition(90);
        lcd->display("Washing complete, you can leave the area");
        // red off and g2 on
        blink->setActive(false);
        R->switchOff();
        G2->switchOn();
        // Serial.println(sonar->getDistance());
        delay->setDelay(2000);
        while (!delay->isDelayComplete()){
            distance = sonar->getDistance();
        }

        if (distance > MAXDIST && distance > 0){
            servo->setPosition(0);
            setState(SLEEP);
        }

        break;
    }
}


void CarPresenceTask::setState(int s){
    state = s;
}
