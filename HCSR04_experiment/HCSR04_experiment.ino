#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

LiquidCrystal_I2C lcd(0x27,20,4);


int dist(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
  }

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Tech2secure.com");
 // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance: ");
  int d = dist();
  Serial.println(d);
  lcd.setCursor(0,1);
  lcd.print("uptime: ");
  lcd.print(millis()/1000);
  lcd.setCursor(0,2);
  lcd.print("Distance:    ");
  lcd.setCursor(10,2);
  lcd.print(d);
  delay(500);
}
