#ifndef __TEMPERATURE_CONTROL__
#define __TEMPERATURE_CONTROL__

#include "Task.h"
#include "components/TempSensorLM35.h"
#include "components/ButtonImpl.h"


class TemperatureControlTask: public Task{
public:
    TemperatureControlTask();
    void tick();

private:
    enum {NORMAL, PRE_ALARM, ALARM} state;
    void setState(int state);
    TempSensorLM35* tempSensor;
    ButtonImpl* button ;
};

#endif