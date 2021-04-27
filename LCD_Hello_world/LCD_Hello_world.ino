#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#define pot A0

void setup() {
  pinMode(pot, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello world");
 // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  lcd.print("Uptime: ");
  lcd.print(millis() / 1000);
  lcd.setCursor(0, 2);
  lcd.print("Pot Value:     ");
  lcd.setCursor(11, 2);
  lcd.print(analogRead(pot));
  delay(500);
}
