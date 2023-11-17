#include "TemperatureControlTask.h"
#include "components/TempSensorLM35.h"
#include <Arduino.h>
#include "components/ButtonImpl.h"



TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(A0);
    this->button = new ButtonImpl(7);
    setState(NORMAL);
}

void TemperatureControlTask::tick(){
    float currentTemp = tempSensor->getTemperature();
    
    switch (state)
    {
    case NORMAL:
        Serial.println("NORMAL");
        if(currentTemp>0){
            setState(PRE_ALARM);
        }
        break;
    case PRE_ALARM:
        Serial.println("PRE_ALARM");
        for(int i=0; i<10; i++){
            Serial.println("attesa");
            delay(100);
        }
        if(currentTemp>0){
            setState(ALARM);
            Serial.println("Alarm");

        }else{
            setState(NORMAL);
        }
        break;

        case ALARM:
               //se premo pulsante ritorna a normal
            if(button->isPressed()){
                setState(NORMAL);
            }
            break;
    }

}

void TemperatureControlTask::setState(int s){
    state = s;
}