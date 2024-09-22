#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

namespace ArduinoPong {
    class Button {
        public:
            Button(const uint8_t& pin);

            void begin() const;
            bool isPressed() const;
        private:
            const uint8_t PIN;
    };
}

#endif