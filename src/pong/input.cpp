#include "pong/input.h"

namespace ArduinoPong {
    Input::Input() : inputValue(0) { }

    void Input::registerInput(const float& value) {
        inputValue = value;
    }

    float Input::getInputValue() const {
        return inputValue;
    }
}