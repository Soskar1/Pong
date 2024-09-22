#include "vector2.h"

namespace ArduinoPong {
    Vector2::Vector2(const int& x, const int& y) : x(x), y(y) { }

    Vector2 Vector2::operator+(const Vector2& v) const {
        return {x + v.x, y + v.y};
    }

    Vector2& Vector2::operator+=(const Vector2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
}