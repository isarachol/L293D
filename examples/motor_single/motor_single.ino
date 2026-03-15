#include "L293D_Single.h"

const uint8_t en_pin = 13;
const uint8_t a1_pin = 14;
const uint8_t a2_pin = 15;
L293D_Single motor(en_pin, a1_pin, a2_pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  motor.configure();
  motor.enable();
  Serial.println("Motor is enabled");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int speed = -255; speed <= 255; speed += 10) {
    Serial.print("Speed = ");
    Serial.println(speed);
    motor.run(speed);
    delay(1000);  
  }
  motor.disable();
  Serial.println("Test Done");
  while(1);
}
