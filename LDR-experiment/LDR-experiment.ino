int LDR = A0;
int buzz = 13;
void setup() {
  pinMode(LDR, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int out = analogRead(LDR);
  Serial.println(out);
  digitalWrite(buzz, HIGH);
  delay(out);
  digitalWrite(buzz, LOW);
  delay(out);
  // put your main code here, to run repeatedly:

}
