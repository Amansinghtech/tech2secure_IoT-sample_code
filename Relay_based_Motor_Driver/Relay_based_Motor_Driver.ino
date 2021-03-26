#define in1 11
#define in2 12
#define btn 10

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {

  int x = digitalRead(btn);
  if (x) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);  
    }
   else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
  
  // put your main code here, to run repeatedly:

}
