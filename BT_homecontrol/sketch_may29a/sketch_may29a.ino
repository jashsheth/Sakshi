#include <AFMotor.h>
AF_DCMotor m(4);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

m.setSpeed(300);
m.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
m.setSpeed(500);
m.run(BACKWARD);

}
