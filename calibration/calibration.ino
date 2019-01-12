#include <Servo.h>


Servo m;

void setup() {
    m.attach(7);
 
    
}

void loop() {
  
  m.writeMicroseconds(100000);
  delay(1000);
    m.writeMicroseconds(200000);
  delay(1000);
}

