#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#include "custom_characters.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup()
{
	// initialize the LCD
	lcd.begin();

  lcd.createChar(0, leftPaddleTop);
  lcd.createChar(1, leftPaddleDown);
  lcd.createChar(2, leftPaddle);

  lcd.createChar(3, rightPaddleTop);
  lcd.createChar(4, rightPaddleDown);
  lcd.createChar(5, rightPaddle);

  lcd.setCursor(0, 1);
  lcd.write(2);

	// Turn on the blacklight and print a message.
	// lcd.print("Hello, world!");
}

void loop()
{
	// Do nothing here...
}
