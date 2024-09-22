#ifndef PONG_H
#define PONG_H

#include <inttypes.h>
#include "paddle.h"

namespace ArduinoPong {
    class Pong {
        public:
            Pong(const uint8_t& maxX, const uint8_t& maxY);

            void start();
        private:
            const uint8_t maxX;
            const uint8_t maxY;

            Paddle leftPaddle;
            Paddle rightPaddle;
    };
}

#endif