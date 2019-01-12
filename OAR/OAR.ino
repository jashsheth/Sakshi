/*Obstacle avoider*/
int trig = 12; /* connect trigger pin of Ultrasonic to pin number 13 */
int echo = 11; /* connect echo pin of Ultrasonic to pin number 12 */
int motorL= 7; /* Declaring left motor */
//int motorR=10; /* Declaring right motor */
void setup()
{
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(motorL, OUTPUT);
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
digitalWrite(motorL,LOW);
//digitalWrite(motorR,HIGH);// turning motor right //
if (h<=20)
{
digitalWrite(motorL,HIGH);
//digitalWrite(motorR,LOW);
//delay(1000);
}
}
