#ifndef PADDLE_H
#define PADDLE_H

#include <ArxSmartPtr.h>
#include "input.h"

namespace ArduinoPong {
    class Paddle {
        public:
            Paddle(const std::shared_ptr<Input>& input);

            void update();
            float getY() const;
        private:
            float y;
            std::shared_ptr<Input> input;
    };
}

#endif