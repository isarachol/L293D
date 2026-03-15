#pragma once // include guards

#include "Arduino.h"

class L293D_Single {
  private:
    byte en_pin;
    byte a1_pin;
    byte a2_pin;

  public:
    L293D_Single(byte, byte, byte);

    void configure();

    void start();
    void stop();

    void run(bool, int);
};