#include "TestPir.h"
#include "Arduino.h"
#include "components/Pir.h"
#include "config.h"
TestPir::TestPir() {
    this->pir = new Pir(PIR_PIN);
}

TestPir::testDetected() {
    if(pir->isDetected()) {
        Serial.println("Something detected")
    }
    else {
        Serial.println("Nothing detected");
    }
}