

int m1=7;
int m2=8;

void setup() {
  // put your setup code here, to run once:
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
delay(12000);
}
