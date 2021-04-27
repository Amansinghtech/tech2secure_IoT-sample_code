#include "Mouse.h"

#define xAxis A0
#define yAxis A1

#define btn 2

int range = 12;

int responseDelay = 3;
int threshold = range / 4;

int center = range / 2;

int readAxis(int thisAxis) {
    int reading = analogRead(thisAxis);

    reading = map(reading, 0, 1023, 0, range);

    int distance = reading - center;

    if (abs(distance) < threshold) {
        distance = 0;
      }
    return distance;
  }

void setup() {
  pinMode(btn, INPUT);
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);

  Serial.begin(9600);
  Mouse.begin();
  
  // put your setup code here, to run once:

}

void loop() {
  int xReading = readAxis(xAxis);
  int yReading = readAxis(yAxis);
  
  int btnReading = digitalRead(btn);
  
  Serial.print("x: ");
  Serial.print(xReading);
  Serial.print(" y: ");
  Serial.print(yReading);
  Serial.print(" btn: ");
  Serial.println(btnReading);
  
  Mouse.move(xReading, -yReading, 0);

  if (btnReading) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  }
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }
  
  delay(responseDelay);
  // put your main code here, to runrepeatedly:

}
