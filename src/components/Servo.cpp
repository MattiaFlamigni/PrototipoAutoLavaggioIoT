#include "Arduino.h"
#include "Servo.h"

Servo::Servo(int pin) {
    this->pin = pin;
    this->closeGate();
}

void Servo::closeGate() {
    //TODO
}

void Servo::openGate() {
    //TODO
}