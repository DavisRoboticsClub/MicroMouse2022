#ifndef HBRIDGE_H
#define HBRIDGE_H

#include <cstdint>

class HBridge
{
  private:
  const uint8_t IN1;
  const uint8_t IN2;
  const uint8_t EN;

  public:
  HBridge(uint8_t IN1, uint8_t IN2, uint8_t EN)
  : IN1(IN1), IN2(IN2), EN(EN)
  { }

  void spin();
  void stop();
};

#endif