#include "MyNonBlockingDelay.h"

MyNonBlockingDelay::MyNonBlockingDelay() {
  previousMillis = 0;
}

void MyNonBlockingDelay::setDelay(unsigned long interval) {
  delayInterval = interval;
  previousMillis = millis();
}

bool MyNonBlockingDelay::isDelayComplete() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= delayInterval) {
    previousMillis = currentMillis;
    return true;
  }

  return false;
}
