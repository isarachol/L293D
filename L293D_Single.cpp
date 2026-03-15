#include "L293D_Single.h"

L293D_Single::L293D_Single(byte en, byte a1, byte a2) {
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

void L293D_Single::start() {
    digitalWrite(en_pin, HIGH);
}    

void L293D_Single::stop() {
    digitalWrite(en_pin, LOW);
} 

void L293D_Single::run(bool dir, int speed) {
    if (dir) {
    analogWrite(a2_pin, 0);
    analogWrite(a1_pin, speed);
    }
    else {
    analogWrite(a1_pin, 0);
    analogWrite(a2_pin, speed);
    }
}