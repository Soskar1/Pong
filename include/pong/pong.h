#ifndef PONG_H
#define PONG_H

#include <ArxSmartPtr.h>
#include <inttypes.h>
#include "input.h"
#include "paddle.h"

namespace ArduinoPong {
    class Pong {
        public:
            Pong(const uint8_t& maxX, const uint8_t& maxY, const std::shared_ptr<Input>& leftPaddleInput, const std::shared_ptr<Input>& rightPaddleInput);

            void update();
        private:
            const uint8_t MAX_X;
            const uint8_t MAX_Y;

            const Paddle LEFT_PADDLE;
            const Paddle RIGHT_PADDLE;
    };
}

#endif