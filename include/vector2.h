#ifndef VECTOR2_H
#define VECTOR2_H

namespace ArduinoPong {
    struct Vector2 {
        Vector2(const int& x, const int& y);

        int x;
        int y;

        Vector2 operator+(const Vector2& v) const;
        Vector2& operator+=(const Vector2& v);
    };
}

#endif