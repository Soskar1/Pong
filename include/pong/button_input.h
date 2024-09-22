#ifndef BUTTON_INPUT_H
#define BUTTON_INPUT_H

#include "input.h"
#include "devices/button.h"

namespace ArduinoPong {
    class ButtonInput : public Input {
        public:
            ButtonInput(const uint8_t& upButtonPin, const uint8_t& downButtonPin);

            void begin() const;
            virtual float read() const;
        private:
            Button upButton;
            Button downButton;
    };
}

#endif