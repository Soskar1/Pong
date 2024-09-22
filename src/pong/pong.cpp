#include "pong/pong.h"

namespace ArduinoPong {
    Pong::Pong(const uint8_t& maxX, const uint8_t& maxY, const std::shared_ptr<Input>& leftPaddleInput, const std::shared_ptr<Input>& rightPaddleInput) :
        MAX_X(maxX), MAX_Y(maxY), LEFT_PADDLE(leftPaddleInput), RIGHT_PADDLE(rightPaddleInput) { }
}