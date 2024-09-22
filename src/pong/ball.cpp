#include "pong/ball.h"

namespace ArduinoPong {
    Ball::Ball(const int& maxX, const int& maxY) : position(maxX / 2, maxY / 2), direction(2, 1), MAX_X(maxX), MAX_Y(maxY) { }

    int Ball::getX() const {
        return position.x;
    }

    int Ball::getY() const {
        return position.y;
    }

    void Ball::setPosition(const int& x, const int& y) {
        position.x = x;
        position.y = y;
    }

    void Ball::setDirection(const int& x, const int& y) {
        direction.x = x;
        direction.y = y;
    }

    void Ball::flipDirectionY() {
        direction.y = -direction.y;
    }

    void Ball::update() {
        position += direction;

        if (position.y < 0) {
            position.y = 0;
            flipDirectionY();
        } else if (position.y > MAX_Y) {
            position.y = MAX_Y;
            flipDirectionY();
        }
    }
}