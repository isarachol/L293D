#include "L293D_Single.h"

L293D_Single::L293D_Single(uint8_t en, uint8_t a1, uint8_t a2) {
    en_pin = en;
    a1_pin = a1;
    a2_pin = a2;
}

void L293D_Single::configure() {
    pinMode(en_pin, OUTPUT);
    pinMode(a1_pin, OUTPUT);
    pinMode(a2_pin, OUTPUT);
    digitalWrite(en_pin, LOW);
    digitalWrite(a1_pin, LOW);
    digitalWrite(a2_pin, LOW);
}

void L293D_Single::enable() {
    digitalWrite(en_pin, HIGH);
}    

void L293D_Single::disable() {
    digitalWrite(en_pin, LOW);
} 

// speed = [-255, 255]
void L293D_Single::run(int speed) {
    if (speed >= 0) {
    analogWrite(a1_pin, speed);
    analogWrite(a2_pin, 0);
    }
    else {
    analogWrite(a1_pin, 0);
    analogWrite(a2_pin, -speed);
    }
}