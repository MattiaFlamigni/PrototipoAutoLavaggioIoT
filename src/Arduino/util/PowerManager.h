// PowerManager.h

#ifndef POWERMANAGER_H
#define POWERMANAGER_H

#include <avr/sleep.h>
#include "Arduino/components/Led.h"
#include "Arduino/components/Lcd.h"

class PowerManager {
public:
  PowerManager();
  void sleep();
  void enablePIRInterrupt();
  void disablePIRInterrupt();
  static void PIRInterruptHandler();
  
};

#endif  
