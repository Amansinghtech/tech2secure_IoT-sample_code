#include <Arduino.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define en1 9
#define en2 6
#define in1 2
#define in2 3
#define in3 4
#define in4 5

int x = 500;
int y = 500;

#define max_throttle 255

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

// int prev = micros();
void setup() {
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void left(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

  if (radio.available()) {
    int data[2];
    radio.read(&data, sizeof(data));
    x = data[0];
    y = data[1];
    // int now = micros() - prev;
    // Serial.print("delay: ");
    // Serial.print(now);
    // Serial.print(" ;");
    // Serial.println(text);
    // prev = micros();
  }
  Serial.print("x axis: ");
  Serial.print(1023 - x);
  Serial.print("; y axis: ");
  Serial.println(y);
  // Serial.println("something");
  //reference value x axis: 512; y axis: 495

  if (y >= 1000) {
    forward();
  }
  else if (y <= 100){
    backward();
  }else if (x >= 1000){
    left();

  }
  else if (x <= 100){
    right();
  }else {
    stop();
  }

  analogWrite(en1, max_throttle);
  analogWrite(en2, max_throttle);

}