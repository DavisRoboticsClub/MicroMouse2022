#include <sys/_stdint.h>
#ifndef MICROMOUSEHBRIDGE_H
#define MICROMOUSEHBRIDGE_H

#include <cstdint>

namespace MicroMouse
{
  class HBridge
  {
    private:
    const uint8_t IN1;
    const uint8_t IN2;
    const uint8_t EN;

    public:
    HBridge(uint8_t IN1, uint8_t IN2, uint8_t EN);

    /// @brief Spins the attached motor, with duty cycle of velocity. Positive velocity spins one way, negative the other
    /// @param velocity is the pwm value to write to the enable pin, from-255 to 255
    void spin(int velocity);
    void stop();
  };
}

#endif