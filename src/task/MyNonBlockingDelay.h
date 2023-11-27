#ifndef MyNonBlockingDelay_h
#define MyNonBlockingDelay_h

#include <Arduino.h>

class MyNonBlockingDelay {
public:
  MyNonBlockingDelay();
  void setDelay(unsigned long interval);
  bool isDelayComplete();

private:
  unsigned long delayInterval;
  unsigned long previousMillis;
};

#endif  // MyNonBlockingDelay_h
