#include "pong/paddle.h"

namespace ArduinoPong {
    Paddle::Paddle(const std::shared_ptr<Input>& input) : y(0), input(input) { }
}