#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_pa 101325

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Adafruit_BMP085 bmp;
void setup()
{
  lcd.init();
  lcd.backlight();
  if (!bmp.begin()) {
      lcd.setCursor(0,0);
      lcd.print("BMP ERROR");
      while(1) {}
    }
  // Print a message to the LCD.
  lcd.setCursor(2,0);
  lcd.print("Tech2Secure.com");
}


void loop()
{
  //this part will print temperature
  lcd.setCursor(0,1);
  lcd.print("Temp:       ");
  lcd.setCursor(6, 1);
  lcd.print(bmp.readTemperature());
  lcd.print(" *C");

  //this part will print Air Pressure
  lcd.setCursor(0, 2);
  lcd.print("Pressure:         ");
  lcd.setCursor(10, 2);
  lcd.print(bmp.readPressure());
  lcd.print(" Pa");

  //this part will print Real Altitude
  lcd.setCursor(0, 3);
  lcd.print("Altitude:         ");
  lcd.setCursor(10, 3);
  lcd.print(bmp.readAltitude(seaLevelPressure_pa));
  lcd.print(" m");

  delay(500);
}
