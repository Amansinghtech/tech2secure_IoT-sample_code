int temp = A0;
int LED = 2;

void setup() {
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(temp);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;
  //Serial.print("TEMPRATURE = ");
  //Serial.print(cel);
  //Serial.print("*C");
  //Serial.println();
  
// uncomment this to get temperature in farenhite
  Serial.print("TEMPRATURE = ");
  Serial.print(farh);
  Serial.print("*F");
  Serial.println();
  // put your main code here, to run repeatedly:
  if (farh >= 95) {
      digitalWrite(LED, HIGH);
    }else {
      digitalWrite(LED, LOW);  
    }
}
