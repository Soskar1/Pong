#include "devices/button.h"

namespace ArduinoPong {
    Button::Button(const uint8_t& pin) : PIN(pin) { }

    void Button::begin() const {
        pinMode(PIN, INPUT);
    }

    bool Button::isPressed() const {
        return digitalRead(PIN);
    }
}