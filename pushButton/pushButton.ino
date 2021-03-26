int pushBtn = 12;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushBtn, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(pushBtn);
  Serial.println(buttonState);
  if (buttonState == 1){
      digitalWrite(LED, HIGH);
    }
  else {
    digitalWrite(LED, LOW);
    }
}
