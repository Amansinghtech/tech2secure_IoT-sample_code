#define in1 13
#define in2 12
#define btn 11

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(btn, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int out = digitalRead(btn);
  if (out) {
    //opposite direction
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
    }else {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);  
      }
  
}
