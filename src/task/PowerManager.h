// PowerManager.h

#ifndef POWERMANAGER_H
#define POWERMANAGER_H

#include <avr/sleep.h>
#include "components/Led.h"
#include "components/Lcd.h"

class PowerManager {
public:
  PowerManager();
  void sleep();
  void enablePIRInterrupt();
  void disablePIRInterrupt();
  static void PIRInterruptHandler();
  
};

#endif  
