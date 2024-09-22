#include "pong/pong.h"

namespace ArduinoPong {
    Pong::Pong(const uint8_t& maxX, const uint8_t& maxY, const std::shared_ptr<Input>& leftPaddleInput, const std::shared_ptr<Input>& rightPaddleInput, LiquidCrystal_I2C& lcd) :
        MAX_X(maxX), MAX_Y(maxY), STEP(0.5f), leftPaddle(0, maxY / 2, maxY, STEP, leftPaddleInput), rightPaddle(maxX, maxY / 2, maxY, STEP, rightPaddleInput), lcd(&lcd) { }

    void Pong::loadGraphics() {
        lcd->createChar(LEFT_PADDLE_TOP, leftPaddleTopChar);
        lcd->createChar(LEFT_PADDLE_DOWN, leftPaddleDownChar);
        lcd->createChar(LEFT_PADDLE_MID, leftPaddleMidChar);
        lcd->createChar(RIGHT_PADDLE_TOP, rightPaddleTopChar);
        lcd->createChar(RIGHT_PADDLE_DOWN, rightPaddleDownChar);
        lcd->createChar(RIGHT_PADDLE_MID, rightPaddleMidChar);
    }

    void Pong::update() {
        leftPaddle.update();
        rightPaddle.update();
    }

    void Pong::draw() {
        drawToLCD(leftPaddle, LEFT_PADDLE_TOP, LEFT_PADDLE_MID, LEFT_PADDLE_DOWN);
        drawToLCD(rightPaddle, RIGHT_PADDLE_TOP, RIGHT_PADDLE_MID, RIGHT_PADDLE_DOWN);
    }

    void Pong::drawToLCD(const Paddle& paddle, const uint8_t& topPaddleChar, const uint8_t& midPaddleChar, const uint8_t& downPaddleChar) {
        float y = paddle.getY();
        int x = paddle.getX();
        bool onTwoSquares = ((int)(y / STEP) % 2) == 1;

        if (onTwoSquares) {
            lcd->setCursor(x, y - STEP);
            lcd->write(downPaddleChar);

            lcd->setCursor(x, y + STEP);
            lcd->write(topPaddleChar);
        } else {
            lcd->setCursor(x, y);
            lcd->write(midPaddleChar);
        }
    }
}