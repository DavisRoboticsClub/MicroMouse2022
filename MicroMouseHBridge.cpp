#include "Arduino.h"
#include <sys/_stdint.h>
#include "core_pins.h"
#include <sys/types.h>
#include "MicroMouseHBridge.h"

MicroMouse::HBridge::HBridge(uint8_t IN1, uint8_t IN2, uint8_t EN)
: IN1(IN1), IN2(IN2), EN(EN)
{
  pinMode(IN1, OUTPUT);
  digitalWrite(IN1, LOW);

  pinMode(IN2, OUTPUT);
  digitalWrite(IN2, LOW);
  
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}


void MicroMouse::HBridge::spin(int velocity)
{

  if(velocity > 0) {
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }

  int speed = abs(velocity);

  analogWrite(EN, speed);
}

void MicroMouse::HBridge::stop()
{

}