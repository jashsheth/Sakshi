#define lf_1 3
#define lf_2 4
#define lb_1 5
#define lb_2 6

#define rf_1 9
#define rf_2 10
#define rb_1 7
#define rb_2 8

#include <VirtualWire.h>
const int receive_pin = 11;

const int led = 13;
//const int transmit_pin = 12;

//const int transmit_en_pin = 3;
void setup()
{
  pinMode(lf_1, OUTPUT);
  pinMode(lf_2, OUTPUT);
  pinMode(lb_1, OUTPUT);
  pinMode(lb_2, OUTPUT);

  pinMode(rf_1, OUTPUT);
  pinMode(rf_2, OUTPUT);
  pinMode(rb_1, OUTPUT);
  pinMode(rb_2, OUTPUT);
  Serial.begin(9600);  // Debugging only
  Serial.println("setup");
  pinMode(led, OUTPUT);
  // Initialise the IO and ISR
  //  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  //vw_set_ptt_pin(transmit_en_pin);
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);  // Bits per sec


  vw_rx_start();

}

void loop()
{

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  digitalWrite(led, HIGH);
  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    int i;
    digitalWrite(led, HIGH);
 //   delay(50);
    digitalWrite(led, LOW);
   // delay(50);

    Serial.print("Got: ");

    for (i = 0; i < buflen; i++)
    {

      //  Serial.println(buf[i],HEX);
      //  Serial.print(' ');// debugging




      if (buf[i] == 48) //Forward
      {
        digitalWrite(2, HIGH);
        Serial.println("Forward ");
                digitalWrite(lf_1, HIGH);
                digitalWrite(lf_2, LOW);
                digitalWrite(lb_1, HIGH);
                digitalWrite(lb_2, LOW);
        
                digitalWrite(rf_1, HIGH);
                digitalWrite(rf_2, LOW);
                digitalWrite(rb_1, HIGH);
                digitalWrite(rb_2, LOW);
        // Serial.println("  FORWARD ");


      }

//      if (buf[i] == 57) //Backward
//      {
//        digitalWrite(3, HIGH);
//        //        digitalWrite(lf_1, LOW);
//        //        digitalWrite(lf_2, HIGH);
//        //        digitalWrite(lb_1, LOW);
//        //        digitalWrite(lb_2, HIGH);
//        //
//        //        digitalWrite(rf_1, LOW);
//        //        digitalWrite(rf_2, HIGH);
//        //        digitalWrite(rb_1, LOW);
//        //        digitalWrite(rb_2, HIGH);
//        Serial.println(" BACK  ");
//
//
//
//      }

      if (buf[i] == 51) //Left
      {
        digitalWrite(4, HIGH);
        Serial.println(" LEFT ");
        //        digitalWrite(lf_1, LOW);
        //        digitalWrite(lf_2, HIGH);
        //        digitalWrite(lb_1, LOW);
        //        digitalWrite(lb_2, HIGH);
        //
        //        digitalWrite(rf_1, HIGH);
        //        digitalWrite(rf_2, LOW);
        //        digitalWrite(rb_1, HIGH);
        //        digitalWrite(rb_2, LOW);
        // Serial.println("left");

      }

      if (buf[i] == 50) //Right
      {
        digitalWrite(5, HIGH);
        Serial.println("Right ");
                analogWrite(lf_1, 150);
                digitalWrite(lf_2, LOW);
                digitalWrite(lb_1, HIGH);
                digitalWrite(lb_2, LOW);
        
                digitalWrite(rf_1, LOW);
                digitalWrite(rf_2, HIGH);
                digitalWrite(rb_1, LOW);
                digitalWrite(rb_2, HIGH);


      }
      if (buf[i] == 56) //STOP
      {
        delay(100);
        digitalWrite(lf_1, LOW);
        digitalWrite(lf_2, LOW);
        digitalWrite(lb_1, LOW);
        digitalWrite(lb_2, LOW);

        digitalWrite(rf_1, LOW);
        digitalWrite(rf_2, LOW);
        digitalWrite(rb_1, LOW);
        digitalWrite(rb_2, LOW);
        Serial.println(" STOP ");

      }
      if (buf[i] == 55)
      {
        digitalWrite(13, HIGH);
        Serial.println(" BACKWARD ");

        digitalWrite(lf_1, LOW);
        digitalWrite(lf_2, HIGH);
        digitalWrite(lb_1, LOW);
        digitalWrite(lb_2, HIGH);

        digitalWrite(rf_1, LOW);
        digitalWrite(rf_2, HIGH);
        digitalWrite(rb_1, LOW);
        digitalWrite(rb_2, HIGH);
      }
    }

  }
}




