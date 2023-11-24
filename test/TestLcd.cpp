#include "TestLcd.h"
#include "Arduino.h"
#include "components/Lcd.h"
#include "config.h"

TestLcd::TestLcd() {
    this->lcd = new Lcd(SDA_PIN, SCL_PIN);
}

TestLcd::testDisplay(char *msg) {
    lcd->display(msg);
}

TestLcd::testClear() {
    lcd->clear();
}

TestLcd::testTwoLineText(char *msg) {
    lcd->twoLineText(msg);
}