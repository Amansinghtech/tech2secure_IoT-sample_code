int led1 = 13;
int led2 = 12;
int led3 = 11;

int delayRED = 10000;
int delayGREEN = 4000;
int delayYELLOW = 2000; //white LED

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1, HIGH);
  delay(delayRED);
  digitalWrite(led1, LOW);
  delay(200);
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  delay(200);
  digitalWrite(led3, HIGH);
  delay(delayGREEN);
  digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);
  delay(delayYELLOW);
  digitalWrite(led2, LOW); 
}
