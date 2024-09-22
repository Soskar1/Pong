#ifndef PONG_H
#define PONG_H

#include <LiquidCrystal_I2C.h>
#include <ArxSmartPtr.h>
#include <inttypes.h>
#include "input.h"
#include "paddle.h"

namespace ArduinoPong {
    class Pong {
        public:
            Pong(const uint8_t& maxX, const uint8_t& maxY, const std::shared_ptr<Input>& leftPaddleInput, const std::shared_ptr<Input>& rightPaddleInput, LiquidCrystal_I2C& lcd);

            void loadGraphics();
            void update();
            void draw();
        private:
            const uint8_t MAX_X;
            const uint8_t MAX_Y;
            const float STEP;

            Paddle leftPaddle;
            Paddle rightPaddle;

            LiquidCrystal_I2C* lcd;

            uint8_t leftPaddleTopChar[8] = { 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00 };
            uint8_t leftPaddleDownChar[8] = { 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18 };
            uint8_t leftPaddleMidChar[8] = { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 };
            uint8_t rightPaddleTopChar[8] = { 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00 };
            uint8_t rightPaddleDownChar[8] = { 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03 };
            uint8_t rightPaddleMidChar[8] = { 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03 };

            enum CustomCharacters {
                LEFT_PADDLE_TOP,
                LEFT_PADDLE_DOWN,
                LEFT_PADDLE_MID,
                RIGHT_PADDLE_TOP,
                RIGHT_PADDLE_DOWN,
                RIGHT_PADDLE_MID
            };

            void drawToLCD(const Paddle& paddle, const uint8_t& topPaddleChar, const uint8_t& midPaddleChar, const uint8_t& downPaddleChar);
    };
}

#endif