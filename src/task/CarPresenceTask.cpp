#include <Arduino.h>
#include "CarPresenceTask.h"
#include "config.h"
#include "components/Sonar.h"
#include "components/Pir.h"
#include "components/Servo.h"

CarPresenceTask::CarPresenceTask() {
    this->sonar = new Sonar(ECHO_PIN, TRIG_PIN, SONAR_TIME);
    this->pir = new Pir(PIR_PIN);
    this->servo = new Servo(SERVO_PIN);
    this->button = new ButtonImpl(START_BUTTON_PIN);
    setState(SLEEP);
}

void CarPresenceTask::tick() {

    switch(state) {
        case SLEEP:
            //deep sleep method
            if(pir->isDetected()) {
                setState(CHECKIN);
            }
        break;

        case CHECKIN:
            servo->openGate();
            //l2 blink
            //lcd display
            if(sonar->getDistance() < MINDIST) {
                setState(ENTERED);
            } 
        break;

        case ENTERED:
            servo->closeGate();
            //l2 on
            //lcd display
            if(button->isPressed()) {
                setState(WASHING);
            }
        break;

        case WASHING:
            //l2 blink
            //display countdown
            //if(countdown = 0) {setState = CHECKOUT}
        break;

        case CHECKOUT:
            servo->openGate();
            //lcd display checkout msg
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