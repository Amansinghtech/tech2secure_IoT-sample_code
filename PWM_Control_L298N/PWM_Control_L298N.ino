#define in1 13
#define in2 12
#define btn 11
#define pot A0
#define pwm 9

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(btn, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(pwm, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int out = digitalRead(btn);
  int value = analogRead(pot);
  int output_signal = map(value, 0, 1023, 0, 255);
  Serial.print("POT value : ");
  Serial.print(value);
  Serial.print("; output: ");
  Serial.println(output_signal);
  analogWrite(pwm, output_signal);
  if (out) {
    //opposite direction
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);  
    }else {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);  
      }
  
}
