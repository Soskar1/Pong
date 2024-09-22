#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Arduino.h>

#include "pong/joystick_input.h"
#include "pong/button_input.h"
#include "pong/pong.h"

#define LCD_WIDTH 20
#define LCD_HEIGHT 4

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd16(rs, en, d4, d5, d6, d7);

LiquidCrystal_I2C lcd(0x3F, LCD_WIDTH, LCD_HEIGHT);
std::shared_ptr<ArduinoPong::JoystickInput> joystick = std::make_shared<ArduinoPong::JoystickInput>(A0, A1, 7);
std::shared_ptr<ArduinoPong::ButtonInput> buttons = std::make_shared<ArduinoPong::ButtonInput>(9, 8);
ArduinoPong::Pong pong(LCD_WIDTH - 1, LCD_HEIGHT - 1, joystick, buttons, lcd, lcd16);

void setup() {
  lcd.begin();
  lcd16.begin(16, 2);
  joystick->begin();
  buttons->begin();

  pong.loadGraphics();
  pong.drawCounter();
}

void loop() {
  pong.update();
  delay(200);
}