#ifndef PADDLE_H
#define PADDLE_H

#include <ArxSmartPtr.h>
#include "input.h"

namespace ArduinoPong {
    class Paddle {
        public:
            Paddle(const int& x, const float& y, const int& maxY, const float& step, const std::shared_ptr<Input>& input);

            void update();
            int getX() const;
            float getY() const;
        private:
            const int x;
            float y;

            const int maxY;
            const float step;
            std::shared_ptr<Input> input;
    };
}

#endif