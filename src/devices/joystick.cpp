#include "devices/joystick.h"

namespace ArduinoPong {
    Joystick::Joystick(const uint8_t& xPin, const uint8_t& yPin, const uint8_t& swPin) : 
        xPin(xPin), yPin(yPin), swPin(swPin), xMin(-1.0f), xMax(1.0f), yMin(-1.0f), yMax(1.0f) { }

    void Joystick::begin() const {
        pinMode(xPin, INPUT);
        pinMode(yPin, INPUT);
        pinMode(swPin, INPUT_PULLUP);
    }

    float Joystick::getX() const {
        float x = analogRead(xPin);
        return map(x, 0, 1023, xMin, xMax);
    }

    float Joystick::getY() const {
        float y = analogRead(yPin);
        return map(y, 0, 1023, yMin, yMax);
    }

    bool Joystick::buttonPressed() const {
        return digitalRead(swPin);
    }

    float Joystick::map(const float& value, const float& inMin, const float& inMax, const float& outMin, const float& outMax) const {
        return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
    }
}