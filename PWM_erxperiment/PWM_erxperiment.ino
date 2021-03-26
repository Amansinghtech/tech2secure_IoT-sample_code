#define LED 11
#define btn 12

int brightness = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int z = digitalRead(btn);
  Serial.println(brightness);
  if (z) {
      brightness = brightness + 10;
    }
  if (brightness > 255) {
      brightness = 0;
    }
  analogWrite(LED, brightness);
  delay(100);
 }
