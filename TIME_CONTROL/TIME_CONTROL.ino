#define a 3
boolean b=false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

uint32_t period = 1000L;       // 5 minutes
Serial.println("Inside");
for( uint32_t tStart = millis();  (millis()-tStart) < period;  ){
  char x=Serial.read();
  Serial.println(x);
} 
}

void loop() {
  // put your main code here, to run repeatedly:

}
