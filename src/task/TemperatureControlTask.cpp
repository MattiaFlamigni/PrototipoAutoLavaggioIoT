#include "TemperatureControlTask.h"
#include "components/TempSensorLM35.h"
#include <Arduino.h>
#include "components/ButtonImpl.h"
#include "config.h"
#include "MsgService.h"


#define DEBUG 1 // 0 - disable, 1 - enable
bool rewrite = true;


TemperatureControlTask::TemperatureControlTask(){
    this->tempSensor = new TempSensorLM35(TMP_SENSOR_PIN);
    this->button = new ButtonImpl(100); //TODO
    this->msg = new MsgServiceClass();
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
        Serial.println("NORMAL");
        
        if(currentTemp>50){
            
            setState(PRE_ALARM);

        }

        break;
    case PRE_ALARM:
        
        Serial.println("PRE_ALARM");
        //wait Nseconds //TODO
    
        for(int i=0; i<2; i++){
            if(DEBUG){
                Serial.println("attesa");
            }
            delay(50); 
        }


        if(currentTemp>50){
            //Serial.println("AT: Alarm");
            rewrite=true;
            setState(ALARM);
            

        }else{
            setState(NORMAL);
        }
        break;

    case ALARM:
        Serial.println("ALARM");
        if(rewrite==true){
            Serial.println("AT: alarm");
            rewrite=false;
        }
        
        //se sulla seriale arriva MAINTENANCE: OK -> setState(NORMAL)

        if(msg->isMsgAvailable()){
            Msg* msg = msg->receiveMsg();
            if(msg->getContent()=="MAINTENANCE: OK"){
                setState(NORMAL);
            }
        }

        

        
        break;
        
    }

}

void TemperatureControlTask::setState(int s){
    state = s;
}