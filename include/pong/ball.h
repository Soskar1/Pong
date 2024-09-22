#ifndef BALL_H
#define BALL_H

#include "vector2.h"

namespace ArduinoPong {
    class Ball {
        public:
            Ball(const int& maxX, const int& maxY);

            int getX() const;
            int getY() const;

            void setPosition(const int& x, const int& y);
            void setDirection(const int& x, const int& y);

            void flipDirectionY();

            void update();
        private:
            Vector2 position;
            Vector2 direction;

            const int MAX_X;
            const int MAX_Y;
    };
}

#endif