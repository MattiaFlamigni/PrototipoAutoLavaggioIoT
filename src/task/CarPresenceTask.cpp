#include <Arduino.h>
#include "CarPresenceTask.h"
#include "config.h"
#include "components/Sonar.h"
#include "components/Pir.h"
#include "components/Servo.h"
#include "components/Lcd.h"

CarPresenceTask::CarPresenceTask() {
    this->sonar = new Sonar(ECHO_PIN, TRIG_PIN, SONAR_TIME);
    this->pir = new Pir(PIR_PIN);
    this->servo = new Servo(SERVO_PIN);
    this->button = new ButtonImpl(START_BUTTON_PIN);
    this->lcd = new Lcd(SDA_PIN, SCL_PIN);
    setState(SLEEP);
}

void CarPresenceTask::tick() {

    switch(state) {
        case SLEEP:
            Serial.println("sleep");
            //deep sleep method
            if(pir->isDetected()) {
                setState(CHECKIN);
            }
        break;

        case CHECKIN:
            Serial.println("checkin");
            servo->openGate();
            //l2 blink
            lcd->display("Proceed to the washing area");
            if(sonar->getDistance() < MINDIST) {
                setState(ENTERED);
            } 
        break;

        case ENTERED:
            Serial.println("entered");
            servo->closeGate();
            //l2 on
            lcd->display("Ready to wash");
            if(button->isPressed()) {
                setState(WASHING);
            }
        break;

        case WASHING:
            Serial.println("Washing");
            //l2 blink
            //display countdown
            //if(countdown = 0) {setState = CHECKOUT}
        break;

        case CHECKOUT:
            Serial.println("Checkout");
            servo->openGate();
            lcd->display("Washing complete, you can leave the area");
            //l2 off and l3 on
            if(sonar->getDistance() > MAXDIST) {
                setState(SLEEP);
            }
        break;
    }

}

void CarPresenceTask::setState(int s) {
    state = s;
}