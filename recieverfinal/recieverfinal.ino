
//Connect the Receiver data pin to Arduino pin 11
int m1=5;
int m2=2;
#include <VirtualWire.h>
const int receive_pin = 9;
const int led_pin = 6;


//const int transmit_en_pin = 3;
void setup()
{
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);


    Serial.begin(9600);  // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR

    vw_set_rx_pin(receive_pin);

    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec

 
    vw_rx_start();
pinMode(LED_BUILTIN,OUTPUT);
}

void loop()
{ 
  
 
 uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      digitalWrite(LED_BUILTIN,HIGH);
	int i;

	Serial.print("Got: ");
	
	for (i = 0; i < buflen; i++)
	{

	 // Serial.println(buf[i],HEX);
	 // Serial.print(' ');// debugging

         
          
         
            if(buf[i]==48)//Forward
            {
            
             digitalWrite(m1,HIGH);
             digitalWrite(m2,HIGH);
            
             Serial.println("  FORWARD ");
          
             
            }
        
          
            if (buf[i]==51)//Left 
            {
        digitalWrite(m1,HIGH);
             digitalWrite(m2,LOW);
           Serial.println("left");
           
            }
          
            if (buf[i]==50)//Right 
            {
              digitalWrite(m2,HIGH);
             digitalWrite(m1,LOW);
               Serial.println(" RIGHT  ");
         
           
            }
             if (buf[i]==56||buf[i]==55)//STOP
            {
            digitalWrite(m1,LOW);
             digitalWrite(m2,LOW);
             Serial.println(" STOP ");
    
            }
	}
    }
}       

  
         
      
    
    
  
     
	

