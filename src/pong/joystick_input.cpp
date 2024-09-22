#include "pong/joystick_input.h"

namespace ArduinoPong {
    JoystickInput::JoystickInput(const uint8_t& xPin, const uint8_t& yPin, const uint8_t& swPin, const float& inputUpdateThreshold) : joystick(Joystick(xPin, yPin, swPin)), yPrev(0), THRESHOLD(inputUpdateThreshold) { }

    void JoystickInput::begin() {
        joystick.begin();
    }

    float JoystickInput::read() const {
        float y = joystick.getY();

        if (abs(y) > THRESHOLD) {
            return y;
        }

        return 0;
    }
}