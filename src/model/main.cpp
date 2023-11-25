#include <Arduino.h> 
#include "task/Task.h"
#include "task/TemperatureControlTask.h"
#include "task/Scheduler.h"
#include "task/CarPresenceTask.h"
#include "task/BlinkTask.h"
#include "config.h"

Scheduler sched;
void setup() {
    Serial.begin(9600);
    sched.init(50);
    Task* temperature = new TemperatureControlTask();
    Task* blinkTask = new BlinkTask(RED_LED);
    Task* carControl = new CarPresenceTask(blinkTask);
    
    temperature->init(50);
    carControl->init(100);
    blinkTask->init(0.1);
    blinkTask->setActive(false);

    sched.addTask(temperature);
    sched.addTask(carControl);
    sched.addTask(blinkTask);
}

void loop() {
    sched.schedule();
}
