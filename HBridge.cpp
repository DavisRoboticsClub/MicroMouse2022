#include <sys/types.h>
#include "HBridge.h"

class HBridge
{
  private:
  const uint8_t IN1;
  const uint8_t IN2;
  const uint8_t EN;

  public:
  HBridge(uint8_t IN1, uint8_t IN2, uint8_t EN)
  : IN1(IN1), IN2(IN2), EN(EN)
  {
    pinMode(IN1, OUTPUT);
    digitalWrite(IN1, LOW);

    pinMode(IN2, OUTPUt);
    digitalWrite(IN2, LOW);
    
    pinMode(EN, OUTPUT);
    digitalWrite(EN, LOW);
  }

  void spin();
  void stop();
};