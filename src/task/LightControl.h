#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include "Task.h"

class LightControl : public Task {
public:
    LightControl();
    void tick();

private:
    enum {ON, OFF, BLINKING} state;
    void setState(int state);
};

#endif