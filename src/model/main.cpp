#include <Arduino.h> 
#include "task/Task.h"
#include "task/TemperatureControlTask.h"
#include "task/Scheduler.h"

Scheduler sched;
void setup() {
    Serial.begin(9600);
    sched.init(100);
    Task* temperature = new TemperatureControlTask();
    temperature->init(50);

    sched.addTask(temperature);
}

void loop() {
    sched.schedule();
}
