#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "pong/custom_characters.h"
#include "pong/joystick_input.h"
#include "pong/button_input.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
ArduinoPong::JoystickInput joystick(A0, A1, 7);
ArduinoPong::ButtonInput buttons(4, 2);

void setup() {
  lcd.begin();
  joystick.begin();
  buttons.begin();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BUTTONS: " + String(buttons.read()));

  lcd.setCursor(0, 1);
  lcd.print("JOYSTICK: " + String(joystick.read()));
  
  delay(200);
}