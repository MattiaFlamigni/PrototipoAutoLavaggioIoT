/**
 * 
 * @author Mattia Flamigni (mattia.flamigni4@studio.unibo.it), Filippo Badioli (filippo.badioli@studio.unibo.it)
 * 
 */

#include <Arduino.h> 
#include "Arduino/kernel/Task.h"
#include "Arduino/task/TemperatureControlTask.h"
#include "Arduino/kernel/Scheduler.h"
#include "Arduino/task/CarPresenceTask.h"
#include "Arduino/task/BlinkTask.h"
#include "Arduino/config.h"

Scheduler sched;
void setup() {
    Serial.begin(9600);
    sched.init(50);
    Task* temperature = new TemperatureControlTask();
    Task* blinkTask = new BlinkTask(RED_LED);
    Task* carControl = new CarPresenceTask(blinkTask, temperature);
    
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
