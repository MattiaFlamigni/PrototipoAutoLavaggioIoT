#include <avr/sleep.h>
#include "PowerManager.h"
#include <Arduino.h>
#include "Arduino/config.h"
#include "Arduino/components/Led.h"
#include "Arduino/components/Lcd.h"

PowerManager::PowerManager(){
}

void PowerManager::sleep(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode(); 
    sleep_disable(); 
}

void PowerManager::enablePIRInterrupt(){
    attachInterrupt(digitalPinToInterrupt(PIR_PIN), PIRInterruptHandler, RISING);
}

void PowerManager::disablePIRInterrupt(){
    detachInterrupt(digitalPinToInterrupt(PIR_PIN));
}

void PowerManager::PIRInterruptHandler(){
    sleep_disable();
}
