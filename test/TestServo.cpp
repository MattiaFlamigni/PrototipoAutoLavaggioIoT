#include "TestServo.h"
#include "Arduino.h"
#include "config.h"
#include "components/servo_motor_impl.h"

TestServo::TestServo() {
    this->pin = SERVO_PIN;
    this->servo = new ServoMotorImpl(SERVO_PIN);
}

void TestServo::testOpenGate() {
    servo->setPosition(0);
}

void TestServo::testCloseGate() {
    servo->setPosition(90);
}