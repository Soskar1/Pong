#ifndef BUTTON_EVENT_H
#define BUTTON_EVENT_H

#include "input_event.h"

namespace ArduinoPong {
    struct ButtonEvent : public InputEvent {
        ButtonEvent(EventCallback callback);

        EventCallback callback;
    };
}

#endif