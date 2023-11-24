#include "TestLcd.h"
#include "Arduino.h"
#include "components/Lcd.h"
#include "config.h"

TestLcd::TestLcd() {
    this->lcd = new Lcd(SDA_PIN, SCL_PIN);
}

void TestLcd::testDisplay(char* msg) {
    lcd->display(msg);
}

void TestLcd::testClear() {
    lcd->clear();
}

void TestLcd::testTwoLineText(char* msg) {
    lcd->twoLineText(msg);
}