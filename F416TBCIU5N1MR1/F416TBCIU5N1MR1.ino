/*Obstacle avoider*/
int trig = 10; /* connect trigger pin of Ultrasonic to pin number 13 */
int echo = 13; /* connect echo pin of Ultrasonic to pin number 12 */

void setup()
{
Serial.begin(9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

}
void loop()
{

digitalWrite(trig, HIGH);

digitalWrite(echo, LOW);// Calculating distance


}
