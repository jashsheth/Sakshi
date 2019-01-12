#include <Wire.h>

// this constant won't change:
const int  buttonPin = 3;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {


  pinMode(buttonPin, INPUT);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Wire.begin(2);

  Serial.println("Select Your Choice");

}


void loop() {



  Wire.beginTransmission(8);


  buttonState = digitalRead(buttonPin);


  if (buttonState != lastButtonState) {

    if (buttonState == HIGH) {

      buttonPushCounter++;

      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      if (buttonPushCounter==1)
      {
        Serial.println("BT MODE");
        Wire.write('B');
        delay(100);
        Wire.endTransmission();
        check();
        //Serial.println("CP1 ");
      } 
        if(buttonPushCounter== 2)
        {
        Serial.println("AUTO  MODE");


        Wire.beginTransmission(8);
        Wire.write('A');
        delay(100);
        Wire.endTransmission();
        //  Serial.println("off");
      }
 if(buttonPushCounter==3)
        {
        Serial.println("SHUTDOWN");


        Wire.beginTransmission(8);
        Wire.write('S');
        delay(100);
        Wire.endTransmission();
         buttonPushCounter=0;
        //  Serial.println("off");
      }
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState = buttonState;
   
  }
}



void check()
{
  Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8

  // slave may send less than requested
  char c = Wire.read(); // receive a byte as character
  Serial.print(c);
  delay(100);
}




