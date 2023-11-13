#ifndef __LED__
#define __LED__
#include "Light.h"

class Led : public Light{
public:
    void switchOn();
    void switchOff();

private:
    int pin;
};

#endif