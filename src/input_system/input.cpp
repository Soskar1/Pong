#include "input_system/input.h"

namespace ArduinoPong {
    Input::Input() : lastInputEvent(nullptr) { }

    void Input::registerInputEvent(const std::shared_ptr<InputEvent>& inputEvent) {
        lastInputEvent = inputEvent;
    }

    std::shared_ptr<InputEvent> Input::getInputEvent() const {
        return lastInputEvent;
    }
}