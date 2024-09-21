#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

namespace ArduinoPong {
    class Joystick {
        public:
            Joystick(const int& xPin, const int& yPin, const int& swPin);

            void begin() const;

            float getX() const;
            float getY() const;
            bool buttonPressed() const;
        private:
            int xPin;
            int yPin;
            int swPin;

            float xMin;
            float xMax;
            float yMin;
            float yMax;

            float map(const float& value, const float& inMin, const float& inMax, const float& outMin, const float& outMax) const;
    };
}

#endif