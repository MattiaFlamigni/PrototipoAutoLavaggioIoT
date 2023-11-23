#include "TestServo.h"
#include "Arduino.h"
#include "config.h"
#include "components/servo_motor_impl.h"

TestServo::TestServo() {
    this->pin = SERVO_PIN;
    this->servo = new ServoMotorImpl;
}

TestServo::testOpenGate() {
    servo->setPosition(0);
}

TestServo::testCloseGate() {
    servo->setPosition(90);
}