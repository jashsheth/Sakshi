/*Obstacle avoider*/
int trig = 6; /* connect trigger pin of Ultrasonic to pin number 13 */
int echo = 8; /* connect echo pin of Ultrasonic to pin number 12 */
int motorL= 9; /* Declaring left motor */
int motorR=10; /* Declaring right motor */
void setup()
{
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(motorL, OUTPUT);
pinMode(motorR, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13,OUTPUT);
//pinMode(motorR, OUTPUT);
}
void loop()
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
digitalWrite(motorL,HIGH);
digitalWrite(motorR,HIGH);
digitalWrite(11,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);
//digitalWrite(motorR,HIGH);// turning motor right //
if (h<=25)
{
digitalWrite(motorL,HIGH);
digitalWrite(11,LOW);
digitalWrite(motorR,LOW);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);

//delay(500);
}
}
