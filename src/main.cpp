#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "pong/custom_characters.h"
#include "pong/joystick_input.h"

LiquidCrystal_I2C lcd(0x3F, 20, 4);
ArduinoPong::JoystickInput input(A0, A1, 7);

void setup() {
  lcd.begin();

  lcd.createChar(0, leftPaddleTop);
  lcd.createChar(1, leftPaddleDown);
  lcd.createChar(2, leftPaddle);

  lcd.createChar(3, rightPaddleTop);
  lcd.createChar(4, rightPaddleDown);
  lcd.createChar(5, rightPaddle);

  input.begin();

  pinMode(2, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // input.read();
  // std::shared_ptr<ArduinoPong::InputEvent> event = input.getInputEvent();
  // std::shared_ptr<ArduinoPong::ValueEvent> valueEvent = std::static_pointer_cast<ArduinoPong::ValueEvent>(event);
  // float y = *(static_cast<float*>(valueEvent->data));

  // lcd.clear();
  // lcd.println("Y: " + String(y));

  int up = digitalRead(4);
  int down = digitalRead(2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("UP: " + String(up));

  lcd.setCursor(0, 1);
  lcd.print("DOWN: " + String(down));
  
  delay(200);
}