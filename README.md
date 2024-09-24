# Arduino Pong

![20240924_194942](https://github.com/user-attachments/assets/edeb7b97-c0e2-4215-8413-452918d5dd5c)

# Requirements
- Arduino UNO
- LCD 20x4 I2C
- LCD 16x2
- JoyStick Dual Axis
- 2x buttons
- 10k Ohm potenciometer
- 2x 10k Ohm resistors
- 220 Ohm resistor

# Wiring
## Joystick
- GND to ground
- 5V to power supply
- VRX to Arduino A0
- VRY to Arduino A1
- SW (not necessary)

## Buttons
- First button to Arduino 9th pin
- Second button to Arduino 8th pin

# LCD 20x4 I2C
- GND to ground
- VCC to power supply
- SDA to Arduino SDA pin
- SCL to Arduino SDL pin

# LCD 16x2
- RS to 12th pin
- E to 11th pin
- D4 to 5th pin
- D5 to 4th pin
- D6 to 3rd pin
- D7 to 2nd pin
