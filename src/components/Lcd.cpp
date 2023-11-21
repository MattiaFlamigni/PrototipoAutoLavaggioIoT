#include "Lcd.h"
#include "Arduino.h"

Lcd::Lcd(int sda, int scl) {
    this->sda = sda;
    this->scl = scl;
}

void Lcd::display(char * msg) {
    //TODO
}