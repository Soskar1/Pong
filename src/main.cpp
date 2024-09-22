#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "pong/joystick_input.h"
#include "pong/button_input.h"
#include "pong/pong.h"

#define LCD_WIDTH 20
#define LCD_HEIGHT 4

LiquidCrystal_I2C lcd(0x3F, LCD_WIDTH, LCD_HEIGHT);
std::shared_ptr<ArduinoPong::JoystickInput> joystick = std::make_shared<ArduinoPong::JoystickInput>(A0, A1, 7);
std::shared_ptr<ArduinoPong::ButtonInput> buttons = std::make_shared<ArduinoPong::ButtonInput>(4, 2);
ArduinoPong::Pong pong(LCD_WIDTH - 1, LCD_HEIGHT - 1, joystick, buttons, lcd);

void setup() {
  lcd.begin();
  joystick->begin();
  buttons->begin();

  pong.loadGraphics();
}

void loop() {
  pong.update();

  lcd.clear();
  pong.draw();

  delay(200);
}