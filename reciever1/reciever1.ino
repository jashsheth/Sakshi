//Connect the Receiver data pin to Arduino pin 11

#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message
  
int L=9;//Left Motor

int R=10;//Right Motor

//int ledPin=13;//led on pin 13 is ON except when bot is stationary
int receive_pin=3;
void setup()
{
 //Serial.begin(9600);//Initialise the serial connection debugging

 pinMode(LED_BUILTIN,OUTPUT);//Onboard LED
 pinMode(L,OUTPUT);

 pinMode(R,OUTPUT);

vw_set_rx_pin(receive_pin);
 vw_setup(2000); // Bits per sec
 vw_rx_start(); // Start the receiver
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      digitalWrite(LED_BUILTIN,HIGH)//when data is received Onboard LED is ON
	int i;

	Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.println(buf[i],HEX);
	    //Serial.print(' ');// debugging

          if (buf[i]==55)//Stationary
          {
            Serial.println("Stop ");
            digitalWrite(L,LOW);  
          //  digitalWrite(Lr,LOW);
            digitalWrite(R,LOW);
          //  digitalWrite(Rr,LOW);
          
           // digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[i]==48)//Forward
            {
              Serial.println("FORWARD ");
              
              digitalWrite(L,HIGH);
              digitalWrite(R,HIGH);
              
              
            //  digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==55)//Backward
            {
              Serial.println("BACK ");
              digitalWrite(L,HIGH);  
              digitalWrite(Lr,LOW);
              digitalWrite(R,LOW);
              digitalWrite(Rr,HIGH);
              
             // digitalWrite(ledPin,HIGH);
          }
          
            if (buf[i]==51)//Left 
            {
              Serial.println("LEFT ");
              digitalWrite(L,LOW);  
             // digitalWrite(Lr,LOW);
              digitalWrite(R,HIGH);
             // digitalWrite(Rr,LOW);
             // digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==50)//Right 
            {
              Serial.println("RIGHT ");
              digitalWrite(L,HIGH);  
             // digitalWrite(Lr,HIGH);
              digitalWrite(R,LOW);
              //digitalWrite(Rr,LOW);
            //  digitalWrite(ledPin,HIGH);
            }
           }   
	  }
	  //Serial.print("\n");// debugging
        }
        //delay(1000);
}
