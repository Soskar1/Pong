#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "pong/custom_characters.h"
#include "pong/joystick_input.h"
#include "pong/button_input.h"
#include "pong/pong.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
std::shared_ptr<ArduinoPong::JoystickInput> joystick = std::make_shared<ArduinoPong::JoystickInput>(A0, A1, 7);
std::shared_ptr<ArduinoPong::ButtonInput> buttons = std::make_shared<ArduinoPong::ButtonInput>(4, 2);
ArduinoPong::Pong pong(20, 4, joystick, buttons);

void setup() {
  lcd.begin();
  joystick->begin();
  buttons->begin();
}

void loop() {  
  delay(200);
}