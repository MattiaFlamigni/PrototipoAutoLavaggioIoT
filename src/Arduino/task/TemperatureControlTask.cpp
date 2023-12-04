#include "TemperatureControlTask.h"
#include "Arduino/components/TempSensorLM35.h"
#include <Arduino.h>
#include "Arduino/components/ButtonImpl.h"
#include "Arduino/config.h"
#include "Arduino/kernel/MsgService.h"


#define DEBUG 0 // 0 - disable, 1 - enable
bool rewrite = true;


TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(TMP_SENSOR_PIN);

    this->msg = new MsgServiceClass();
    setState(NORMAL);
    
}

void TemperatureControlTask::tick(){
    float currentTemp = tempSensor->getTemperature();
    
        Serial.print("T: ");
        Serial.println(currentTemp); 
    
    
    switch (state){
    case NORMAL:
        
        if(currentTemp>MAXTEMP){
            setState(PRE_ALARM);
        }

        break;
    case PRE_ALARM:
    
        for(int i=0; i<2; i++){
            if(DEBUG){
                Serial.println("attesa");
            }
            delay(50); 
        }

        if(currentTemp>MAXTEMP){
            //Serial.println("AT: Alarm");
            rewrite=true;
            setState(ALARM);
        }else{
            setState(NORMAL);
        }
        break;

    case ALARM:
        
        if(rewrite==true){
            Serial.println("AT: alarm");
            rewrite=false;
        }
        
        //se sulla seriale arriva MAINTENANCE: OK -> setState(NORMAL)
        if(msg->currentMsg->getContent()=="MAINTENANCE: OK"){
            setState(NORMAL);
        }
        break;
    }
}

void TemperatureControlTask::setState(int s){
    state = s;
}