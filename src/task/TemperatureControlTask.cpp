#include "TemperatureControlTask.h"
#include "components/TempSensorLM35.h"
#include <Arduino.h>
#include "components/ButtonImpl.h"
#include "config.h"


#define DEBUG 0 // 0 - disable, 1 - enable


TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(TMP_SENSOR_PIN);
    this->button = new ButtonImpl(100); //TODO
    setState(NORMAL);
    
}

void TemperatureControlTask::tick(){
    float currentTemp = tempSensor->getTemperature();
    if(DEBUG){
        Serial.println(currentTemp); 
    }
    
    switch (state)
    {
    case NORMAL:
        
        if(DEBUG){
            Serial.println("NORMAL");
        }
        if(currentTemp>0){
            
            setState(PRE_ALARM);
        }
        break;
    case PRE_ALARM:
        
        if(DEBUG){
            Serial.println("PRE_ALARM");
        }
        //wait Nseconds //TODO
    
        for(int i=0; i<2; i++){
            if(DEBUG){
                Serial.println("attesa");
            }
            delay(50); 
        }


        if(currentTemp>0){
            setState(ALARM);
            Serial.println("Alarm");

        }else{
            setState(NORMAL);
        }
        break;

    case ALARM:
        if(DEBUG){
            Serial.println("ALARM");
        }
        if(button->isPressed()){
            setState(NORMAL);
        }
        
        break;
        
    }

}

void TemperatureControlTask::setState(int s){
    state = s;
}