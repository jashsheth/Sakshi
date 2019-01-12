#include <AFMotor.h>
char data;
AF_DCMotor m(1);

AF_DCMotor m2(3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
m.setSpeed(200);
m.run(RELEASE);

m2.setSpeed(200);
m2.run(RELEASE);
}

void loop() {

  if(Serial.available() > 0)

  {
    data=Serial.read();
    Serial.println(data);
    if(data=='0')
    {
      m.setSpeed(200);
      m.run(FORWARD);
      Serial.println("winding up ");
      m2.setSpeed(200);
      m2.run(BACKWARD);
    }
    else if(data=='1')
    {
      m2.setSpeed(250);
      m2.run(FORWARD);
      m.setSpeed(250);
      m.run(BACKWARD);

      Serial.println("opening up ");
    }
else if(data=='2')
{
  m.setSpeed(0);
  m.run(RELEASE);

   m2.setSpeed(0);
  m2.run(RELEASE);
  Serial.println("stop");
}




    
  }
  
  

}
