#define motor 11

void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor, 255/2);
}
