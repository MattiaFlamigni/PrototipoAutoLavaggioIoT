#ifndef __TEMPERATURE_CONTROL__
#define __TEMPERATURE_CONTROL__

#include "Arduino/kernel/Task.h"
#include "Arduino/components/TempSensorLM35.h"
#include "Arduino/components/ButtonImpl.h"
#include "Arduino/kernel/MsgService.h"


class TemperatureControlTask: public Task{
public:
    TemperatureControlTask();
    void tick();

private:
    enum {NORMAL, PRE_ALARM, ALARM} state;
    void setState(int state);
    TempSensorLM35* tempSensor;
    Button* button ;
    MsgServiceClass* msg;
};

#endif