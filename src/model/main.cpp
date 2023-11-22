#include <Arduino.h> 
#include "task/Task.h"
#include "task/TemperatureControlTask.h"
#include "task/Scheduler.h"
#include "task/CarPresenceTask.h"

Scheduler sched;
void setup() {
    Serial.begin(9600);
    sched.init(100);
    Task* temperature = new TemperatureControlTask();
    Task* carControl = new CarPresenceTask();
    temperature->init(50);
    carControl->init(100);

    //sched.addTask(temperature);
    sched.addTask(carControl);
}

void loop() {
    sched.schedule();
}
