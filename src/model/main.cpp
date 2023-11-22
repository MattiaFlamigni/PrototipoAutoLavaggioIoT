#include <Arduino.h> 
#include "task/Task.h"
#include "task/TemperatureControlTask.h"
#include "task/Scheduler.h"
#include "task/CarPresenceTask.h"

Scheduler sched;
void setup() {
    Serial.begin(9600);
    sched.init(300);
    Task* temperature = new TemperatureControlTask();
    Task* carControl = new CarPresenceTask();
    temperature->init(100);
    carControl->init(30);

    sched.addTask(temperature);
    sched.addTask(carControl);
}

void loop() {
    sched.schedule();
}
