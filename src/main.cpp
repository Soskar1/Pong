#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <joystick.h>

#include "custom_characters.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
ArduinoPong::Joystick joystick(A0, A1, 7);

void joystickDebug() {
  float x = joystick.getX();
  float y = joystick.getY();
  bool pressed = joystick.buttonPressed();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("X: " + String(x));

  lcd.setCursor(0, 1);
  lcd.print("Y: " + String(y));

  lcd.setCursor(0, 2);
  lcd.print("Button: " + String(pressed));
  delay(1000);
}

void setup() {
  lcd.begin();

  lcd.createChar(0, leftPaddleTop);
  lcd.createChar(1, leftPaddleDown);
  lcd.createChar(2, leftPaddle);

  lcd.createChar(3, rightPaddleTop);
  lcd.createChar(4, rightPaddleDown);
  lcd.createChar(5, rightPaddle);

  // Serial.begin(9600);
  joystick.begin();
}

void loop() {
  
}