#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
myservo.attach(8);
}

void loop() {
myservo.write(90);
delay(1000);
myservo.writeMicroseconds(100000);
delay(1000);



}
