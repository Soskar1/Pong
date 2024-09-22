#include "pong/button_input.h"

namespace ArduinoPong {
    ButtonInput::ButtonInput(const uint8_t& upButtonPin, const uint8_t& downButtonPin) : upButton(upButtonPin), downButton(downButtonPin) { }

    void ButtonInput::begin() const {
        upButton.begin();
        downButton.begin();
    }

    float ButtonInput::read() const {
        return upButton.isPressed() - downButton.isPressed();
    }
}