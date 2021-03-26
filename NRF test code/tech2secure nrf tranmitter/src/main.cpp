#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setAutoAck(false);
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello Aliens";
  radio.write(&text, sizeof(text));
  // delay(1000);
}