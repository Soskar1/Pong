#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

namespace ArduinoPong {
    class Joystick {
        public:
            Joystick(const uint8_t& xPin, const uint8_t& yPin, const uint8_t& swPin);

            void begin() const;

            float getX() const;
            float getY() const;
            bool buttonPressed() const;
        private:
            uint8_t xPin;
            uint8_t yPin;
            uint8_t swPin;

            float xMin;
            float xMax;
            float yMin;
            float yMax;

            float map(const float& value, const float& inMin, const float& inMax, const float& outMin, const float& outMax) const;
    };
}

#endif