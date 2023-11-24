#include "TestSonar.h"
#include "Arduino.h"
#include "components/Sonar.h"
#include "config.h"

TestSonar::TestSonar() {
    this.sonar = new Sonar(ECHO_PIN, TRIG_PIN, SONAR_TIME)
}

TestSonar::testDistance() {
    Serial.print("Current distance is: ");
    Serial.println(sonar.getDistance());
}