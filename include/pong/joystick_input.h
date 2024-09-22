#ifndef JOYSTICK_INPUT
#define JOYSTICK_INPUT

#include "input.h"
#include "devices/joystick.h"

namespace ArduinoPong {
    class JoystickInput : public Input {
        public:
            JoystickInput(const uint8_t& xPin, const uint8_t& yPin, const uint8_t& swPin, const float& inputUpdateThreshold = 0.25f);

            void begin();
            virtual float read() const;
        private:
            Joystick joystick;
            float yPrev;
            const float THRESHOLD;
    };
}

#endif