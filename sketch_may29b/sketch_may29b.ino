#include <Servo.h>


Servo m;
void setup() {
  // put your setup code here, to run once:
m.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
m.write(120);
delay(1000);


}
