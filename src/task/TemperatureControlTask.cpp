#include "TemperatureControlTask.h"
#include "components/TempSensorLM35.h"
#include <Arduino.h>
#include "components/ButtonImpl.h"
#include "config.h"



TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(TMP_SENSOR_PIN);
    this->button = new ButtonImpl(BUTTON_MAINTENACE_PIN);
    setState(NORMAL);
}

void TemperatureControlTask::tick(){
    float currentTemp = tempSensor->getTemperature();
    Serial.println(currentTemp); 
    
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
            //Serial.println("Alarm");

        }else{
            setState(NORMAL);
        }
        break;

    case ALARM:
        Serial.println("ALARM");
        if(button->isPressed()){
            setState(NORMAL);
        }
        
        break;
        
    }

}

void TemperatureControlTask::setState(int s){
    state = s;
}