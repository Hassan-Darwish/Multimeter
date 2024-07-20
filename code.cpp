#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

float vOUT = 0.0;
float vIN = 0.0;
float R1 = 15000.0;
float R2 = 1500.0;
float current = 0.0; 
int LED = 7;
boolean led = HIGH;
char inbyte = 0;
float Power = 0;
float P = 0;
float Pavg = 0;
int n = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {

  digitalWrite(LED, led);
  int value = analogRead(A0);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2 / (R1 + R2));
  current = 1000 * (vIN / (R1 + R2));
  if (Serial.available() > 0)
  {
    inbyte = Serial.read();
    if (inbyte == '1')
    {
      led = LOW;
    }
    else if (inbyte == '0')
    {
      led = HIGH;
    }

  }
  P = (current)*(vIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(vIN);
  lcd.print("V ");
  lcd.setCursor(0,1);
  lcd.print(current);
  lcd.print("A ");
  lcd.print(P);
  lcd.print("W ");

  Serial.print("Voltage: ");
  Serial.print(vIN);
  Serial.println("V");
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println("A");
  Serial.print("Power: ");
  Serial.print(P);
  Serial.println("W");
  Serial.println("......................");
  delay(500);
}
