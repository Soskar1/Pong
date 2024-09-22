#include "pong/paddle.h"

namespace ArduinoPong {
    Paddle::Paddle(const int& x, const float& y, const int& maxY, const float& step, const std::shared_ptr<Input>& input) : x(x), y(y), maxY(maxY), step(step), input(input) { }

    void Paddle::update() {
        float in = input->read();

        if (in == 0) {
            return;
        }

        if (in > 0) {
            y += step;
        } else {
            y -= step;
        }

        if (y < 0) {
            y = 0;
        } else if (y > maxY) {
            y = maxY;
        }
    }

    float Paddle::getY() const {
        return y;
    }

    int Paddle::getX() const {
        return x;
    }

    void Paddle::setY(const float& y) {
        this->y = y;
    }
}