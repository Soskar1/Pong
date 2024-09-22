#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

namespace ArduinoPong {
    typedef void (*EventCallback)(void*);

    struct InputEvent {
        virtual ~InputEvent() {}
    };
}

#endif