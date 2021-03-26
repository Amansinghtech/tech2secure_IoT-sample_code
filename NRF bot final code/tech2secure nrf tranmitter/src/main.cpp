#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define x_axis A0
#define y_axis A1

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  pinMode(x_axis, INPUT);
  pinMode(y_axis, INPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setAutoAck(false);
  radio.stopListening();
}

void loop() {
  int x = analogRead(x_axis);
  int y = analogRead(y_axis);

  Serial.print("x axis: ");
  Serial.print(1023 - x);
  Serial.print("; y axis: ");
  Serial.println(y);

  int data[] = {x, y};
  radio.write(&data, sizeof(data));
  // delay(1000);

}