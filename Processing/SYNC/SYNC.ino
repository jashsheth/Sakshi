void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(5,INPUT_PULLUP);
}

void loop() {
  // put your mainM code here, to run repeatedly:
//Serial.println("Jash ");
//delay(100);
int s=digitalRead(5);
if(s==0)
{
  Serial.println("F;");
}
else
{
  Serial.println("1;");
}
delay(50);
}
