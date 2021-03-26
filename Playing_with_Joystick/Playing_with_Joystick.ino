#define y_axis A0
#define in1 13
#define in2 12
#define en1 9
void setup() {
  pinMode(y_axis, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en1, OUTPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  // 527 
  // < 520 reverse Direction , speed increase 
  // > 550 forward direciton, speed increase 
  int y = analogRead(y_axis);
  int pwm_out = 0;
  //Serial.println(y);

  if (y >= 540) {
      //forward direciton 
      pwm_out = map(y, 540, 1023, 0, 255);
      analogWrite(en1, pwm_out);
      Serial.println(pwm_out);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
   if (y <= 520){
      pwm_out = map(520 - y, 0, 520, 0, 255);
      analogWrite(en1, pwm_out);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
    else if (y >520 && y < 530) {
      //analogWrite(en1, 0);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      }
  
  // put your main code here, to run repeatedly:

}
