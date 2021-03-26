int pot = A0;
int LED = 3;
void setup() {
  pinMode(pot, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int out = analogRead(pot);
  Serial.print("analog Input: ");
  Serial.println(out);
  Serial.print("PWM LED output: ");
  //Serial.println(out/4);
  //analogWrite(LED, out/4);
  // put your main code here, to run repeatedly:

}
