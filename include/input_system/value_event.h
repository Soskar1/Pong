#ifndef VALUE_EVENT_H
#define VALUE_EVENT_H

#include "input_event.h"

namespace ArduinoPong {
    struct ValueEvent : public InputEvent {
        ValueEvent(void *data);
        void *data;
    };
}

#endif