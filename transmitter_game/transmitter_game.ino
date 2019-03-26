#include <VirtualWire.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(10,9); // CE, CSN
const byte address[6] = "saksh";
#include<Wire.h>
//#define led 13
//const int transmit_en_pin = 3;
//const int transmit_pin = 11;
const int MPU_addr = 0x68;
int16_t axis_X, axis_Y, axis_Z;

int minVal = 265;
int maxVal = 402;

double x;
double y;
double z;

void setup() {
//  vw_set_tx_pin(transmit_pin);
//
//  vw_set_ptt_pin(transmit_en_pin);
//  vw_set_ptt_inverted(true); // Required for DR3100
//  vw_setup(2000);   // Bits per sec
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);
 // pinMode(led, OUTPUT);
}
void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);
  axis_X = Wire.read() << 8 | Wire.read();

  axis_Y = Wire.read() << 8 | Wire.read();
  axis_Z = Wire.read() << 8 | Wire.read();
  int xAng = map(axis_X, minVal, maxVal, -90, 90);
  int yAng = map(axis_Y, minVal, maxVal, -90, 90);
  int zAng = map(axis_Z, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  Serial.print("Angle of inclination in X axis = ");
  Serial.println(x);
  Serial.println((char)176);



  Serial.print("Angle of inclination in Y axis= ");
  Serial.print(y);
  Serial.println((char)176);

  //    Serial.print("Angle of inclination in Z axis= ");
  //     Serial.print(z);
  //     Serial.println((char)176);
  //
  Serial.println("-------------------------------------------");
 // delay(500);
 // digitalWrite(led, HIGH);
  //delay(1000);

  if ((x >= 30 && x <= 55 ) && (y >= 34 && y <= 70))
  {
    const char text[] = "A.";
    radio.write(&text, sizeof(text));
    Serial.println(" Forward Right  ");
  }

  else if ((x >= 30 && x <= 55) && (y <= 330 && y >= 280))
  {
    const char text[] = "B.";
    radio.write(&text, sizeof(text));
    Serial.println("Forward Left ");
  }

  else if (x > 25 && x < 60 )
  {
    const char text[] = "F.";
    radio.write(&text, sizeof(text));
    Serial.println(" FORWARD ");
    char msg1[1] = {'0'};
    Serial.println(msg1);
    //    vw_send((uint8_t *)msg1, 1);
    //    vw_wait_tx();
  }



  //  else if (x > 310 && x < 345 )
  //  {
  //    Serial.println(" Stop");
  //    char a[1] = {'7'};
  //const char text[] = "S";
  //  radio.write(&text, sizeof(text));
  //    Serial.println(a);
  //
  ////    vw_send((uint8_t *)a, 1);
  ////    vw_wait_tx();
  //  }


  else if(y>35 && y<70 )
  {
  const char text[] = "A.";
    radio.write(&text, sizeof(text));
    Serial.println(" Forward Right  ");
    Serial.println("   RIGHT   ");
//      char msg2[1] = {'2'};
//  
//   Serial.println(msg2);
//  
//    vw_send((uint8_t *)msg2, 1);
//    vw_wait_tx();
  }



  else if(y>280 && y<330)
    {
  
    Serial.println("   LEFT    ");
    const char text[] = "B.";
    radio.write(&text, sizeof(text));
//     char msg3[1] = {'3'};
//  
//   Serial.println(msg3);
//  
//    vw_send((uint8_t *)msg3, 1);
//    vw_wait_tx();
  }
  else if (((x > 335 && x < 360)) || (x >= 0 && x < 25))
  {
    Serial.println( "STOP ");
    char msg4[1] = {'8'};
    const char text[] = "S.";
    radio.write(&text, sizeof(text));
    //Serial.println(msg4);
    //
    //    vw_send((uint8_t *)msg4, 1);
    //    vw_wait_tx();
  }
  else if (x > 280 && x < 334 )
  {
    Serial.println(" BAckward ");
    const char text[] = "C.";
    radio.write(&text, sizeof(text));

  }
}
//void send(char message)//send function definition
//{
//  Serial.println(message);
//  vw_send((uint8_t *)message, strlen(message));
//  vw_wait_tx(); // Wait until the whole message is gone
//}



