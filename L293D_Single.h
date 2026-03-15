#pragma once // include guards

#include "Arduino.h"

class L293D_Single {
  private:
    uint8_t en_pin;
    uint8_t a1_pin;
    uint8_t a2_pin;

  public:
    L293D_Single(uint8_t, uint8_t, uint8_t);

    void configure();

    void enable();
    void disable();

    void run(int);
};