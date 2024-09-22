#include "pong/pong.h"

namespace ArduinoPong {
    Pong::Pong(const uint8_t& maxX, const uint8_t& maxY, const std::shared_ptr<Input>& leftPaddleInput, const std::shared_ptr<Input>& rightPaddleInput, LiquidCrystal_I2C& lcd, LiquidCrystal& counterLCD) :
        MAX_X(maxX), MAX_Y(maxY), STEP(0.5f), leftPaddle(0, maxY / 2, maxY, STEP, leftPaddleInput), rightPaddle(maxX, maxY / 2, maxY, STEP, rightPaddleInput), ball(maxX, maxY), counterLCD(&counterLCD), lcd(&lcd) { }

    void Pong::loadGraphics() {
        lcd->createChar(LEFT_PADDLE_TOP, leftPaddleTopChar);
        lcd->createChar(LEFT_PADDLE_DOWN, leftPaddleDownChar);
        lcd->createChar(LEFT_PADDLE_MID, leftPaddleMidChar);
        lcd->createChar(RIGHT_PADDLE_TOP, rightPaddleTopChar);
        lcd->createChar(RIGHT_PADDLE_DOWN, rightPaddleDownChar);
        lcd->createChar(RIGHT_PADDLE_MID, rightPaddleMidChar);
        lcd->createChar(BALL, ballChar);
    }

    void Pong::update() {
        leftPaddle.update();
        rightPaddle.update();
        ball.update();

        // Collision
        if (ball.getX() <= 0) {
            ball.setPosition(0, ball.getY());

            if (abs(leftPaddle.getY() - ball.getY()) <= 0.5) {
                ball.setDirection(1, random(-3, 3));
            } else {
                rightWon = true;
            }
        } else if (ball.getX() >= MAX_X) {
            ball.setPosition(MAX_X, ball.getY());

            if (abs(rightPaddle.getY() - ball.getY()) <= 0.5) {
                ball.setDirection(-1, random(-3, 3));
            } else {
                leftWon = true;
            }
        }

        draw();

        if (leftWon || rightWon) {
            reset();
        }
    }

    void Pong::draw() {
        lcd->clear();

        drawToLCD(leftPaddle, LEFT_PADDLE_TOP, LEFT_PADDLE_MID, LEFT_PADDLE_DOWN);
        drawToLCD(rightPaddle, RIGHT_PADDLE_TOP, RIGHT_PADDLE_MID, RIGHT_PADDLE_DOWN);

        lcd->setCursor(ball.getX(), ball.getY());
        lcd->write(BALL);
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

    void Pong::reset() {
        leftPaddle.setY(MAX_Y / 2);
        rightPaddle.setY(MAX_Y / 2);
        ball.setPosition(MAX_X / 2, MAX_Y / 2);

        if (rightWon) {
            ball.setDirection(-1, random(-3, 3));
            rightWon = false;
            ++rightScore;
        }

        if (leftWon) {
            ball.setDirection(1, random(-3, 3));
            leftWon = false;
            ++leftScore;
        }

        draw();
        drawCounter();
        delay(1000);
    }

    void Pong::drawCounter() {
        counterLCD->clear();
        counterLCD->setCursor(0, 0);
        counterLCD->print("P1: " + String(leftScore));

        counterLCD->setCursor(0, 1);
        counterLCD->print("P2: " + String(rightScore));
    }
}