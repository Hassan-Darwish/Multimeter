# Arduino Multimeter Project

This project is a simple Arduino-based multimeter capable of measuring voltage, current, and power. It uses an Arduino Uno, an LCD display, a voltage divider, and other components to display the readings.

## Components

- Arduino Uno
- LiquidCrystal_I2C LCD
- Voltage Divider (Resistors: 15kΩ and 1.5kΩ)
- LED
- Breadboard and jumper wires
- Power source (e.g., 9V battery)
- Battery recharging circuit

## Circuit Diagram

![Circuit Diagram](image.png)

## Code

The code for the project is written in C++ and uses the Arduino IDE.

## How to Use
1. Assemble the circuit as shown in the diagram.
2. Upload the provided code to the Arduino Uno using the Arduino IDE.
3. Open the Serial Monitor to view the readings or observe them on the LCD screen.
4. Use the serial input to control the LED (send '1' to turn it off, '0' to turn it on).
