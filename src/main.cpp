#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <joystick.h>

#include "custom_characters.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display


LiquidCrystal_I2C lcd(0x3F, 20, 4);
ArduinoPong::Joystick joystick(A0, A1, 7);

void setup()
{
  // initialize the LCD
  // lcd.begin();

  // lcd.createChar(0, leftPaddleTop);
  // lcd.createChar(1, leftPaddleDown);
  // lcd.createChar(2, leftPaddle);

  // lcd.createChar(3, rightPaddleTop);
  // lcd.createChar(4, rightPaddleDown);
  // lcd.createChar(5, rightPaddle);

  // lcd.setCursor(0, 1);
  // lcd.write(2);
  Serial.begin(9600);
  joystick.begin();
}

void loop()
{
  float x = joystick.getX();
  float y = joystick.getY();
  bool pressed = joystick.buttonPressed();

  Serial.println("X: " + String(x) + " | Y: " + String(y) + " | Button: " + String(pressed));
}