#include <Servo.h>
int Rdist;
 int Ldist;
int MotorR=2;
int MotorL=3;
int trig=10;
int echo=13;
Servo rnrr;
int dist;
int failsafe=30;
void setup() {
  pinMode(MotorR,OUTPUT);

  pinMode(MotorL,OUTPUT);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  rnrr.attach(6);
 rnrr.write(90);
 
 delay(1000);

}

void loop() {

  
Serial.begin(9600);

dist=Ping();
if(dist<failsafe)
{
  changecourse();

  
}
forward();
delay(1000);

}

void forward()
{
  
 
  
  digitalWrite(MotorL,HIGH);
  digitalWrite(MotorR,HIGH);
}
int Ping()
{
long t = 0, h = 0; // Transmitting pulse
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);// Waiting for pulse
t = pulseIn(echo, HIGH);// Calculating distance
h = (t/2) / 29.1;// Sending to computer
Serial.print(h);// Serial.print(" cm\n");
Serial.print("\n");//condition for motors
return h;
}

void STOP()
{
  
  digitalWrite(MotorL,LOW);
  digitalWrite(MotorL,LOW);
}
void changecourse()
{

  
  STOP();
  rnrr.write(90);
  delay(1000);
  rnrr.writeMicroseconds(100000);
  delay(500);
  Rdist=Ping();
  delay(500);
  rnrr.writeMicroseconds(200000);
  delay(500);
  Ldist=Ping();
  delay(500);
  rnrr.write(90);
  compareDistance();
}
void compareDistance()
{

  
  if(Rdist>Ldist)
  {
    turnRight();
  }
  else if(Ldist>Rdist)
  {
    turnLeft();
  }
}
void turnRight()
{
  digitalWrite(MotorL
  ,HIGH);
  digitalWrite(MotorR,LOW);
  
}

void turnLeft()
{

digitalWrite(MotorL,LOW);
  digitalWrite(MotorR,HIGH);
  
  
}



