#include "TemperatureControlTask.h"
#include "components/TempSensorLM35.h"
#include <Arduino.h>
#include "components/ButtonImpl.h"
#include "config.h"


#define DEBUG 1 // 0 - disable, 1 - enable


TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(TMP_SENSOR_PIN);
    this->button = new ButtonImpl(100); //TODO
    setState(NORMAL);
    
}

void TemperatureControlTask::tick(){
    float currentTemp = tempSensor->getTemperature();
    if(DEBUG){
        Serial.print("T: ");
        Serial.println(currentTemp); 
    }
    
    switch (state)
    {
    case NORMAL:
        
        if(DEBUG){
            Serial.println("NORMAL");
        }
        if(currentTemp>50){
            
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


        if(currentTemp>50){
            setState(ALARM);
            Serial.println("AT: Alarm");

        }else{
            setState(NORMAL);
        }
        break;

    case ALARM:
        if(DEBUG){
            Serial.println("AT: alarm");
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