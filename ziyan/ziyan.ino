//#include <AFMotor.h>
//
//#define lf_1 3
//#define lf_2 4
//#define lb_1 5
//#define lb_2 6
//
#define motorL 9
#define motorR 10
//#define rb_1 7
//#define rb_2 8
int trig = 6; /* connect trigger pin of Ultrasonic to pin number 13 */
int echo = 8;

int c = 10;
//int 12;
int stat;
char state;
void setup() {

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(stat, INPUT);
  Serial.println(c);
  pinMode(motorL, OUTPUT);
  pinMode(motorR, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(7, INPUT_PULLUP);
  //
  //  pinMode(rf_1, OUTPUT);
  //  pinMode(rf_2, OUTPUT);
  //  pinMode(rb_1, OUTPUT);
  //  pinMode(rb_2, OUTPUT);
  Serial.println("Stsrting : ");
  digitalWrite(13, HIGH);
  delay(2000);
  // put your setup code here, to run on
  pinMode(2, INPUT);
}

void loop() {
  digitalWrite(13, LOW);
  // put your main code here, to run repeatedly:
  if (digitalRead(7) == LOW)
  {
    c += 1;
    delay(500);
  }
  if (c == 10)
  {
    Serial.println(" STOP ");
    digitalWrite(motorL, LOW);
    digitalWrite(motorR, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else
  {
    if (c % 2 == 1)

    {
      Serial.println("Bluetooth Mode");
      digitalWrite(13, HIGH);
      // delay(1000);
      BT();
    }
    if (c % 2 == 0)
    {
      Serial.println("OAR ");
      digitalWrite(13, HIGH);
      //delay(3000);
      OAR();
    }

  }
  }


  //  if (stat != 0)
  //  {
  //
  //    Serial.println("Error ");
  //    digitalWrite(lf_1, LOW);
  //    digitalWrite(lf_2, LOW);
  //    digitalWrite(lb_1, LOW);
  //    digitalWrite(lb_2, LOW);
  //
  //    digitalWrite(rf_1, LOW);
  //    digitalWrite(rf_2, LOW);
  //    digitalWrite(rb_1, LOW);
  //    digitalWrite(rb_2, LOW);
  //    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //    delay(1000);                       // wait for a second
  // turn the LED off by making the voltage LOW
  //    delay(1000);
  //  }
  //digitalWrite(13, HIGH);
  void BT()
  {

    if (Serial.available() > 0)
    {
      char prev_state = state;
      state = Serial.read();
      digitalWrite(13, LOW);
      if (state == 'F')

      {

        digitalWrite(13, HIGH);
        Serial.println("Forward ");
        digitalWrite(motorR, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(motorL, HIGH);
        digitalWrite(12, LOW);

        //      digitalWrite(rf_1, HIGH);
        //      digitalWrite(rf_2, LOW);
        //      digitalWrite(rb_1, HIGH);
        //      digitalWrite(rb_2, LOW);

      }
      else if (state == 'B')
      {
        digitalWrite(13, HIGH);
        Serial.println(" BACKWARD ");

        digitalWrite(motorR, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(motorL, LOW);
        digitalWrite(12, HIGH);
      }
      else if (state == 'L')

      {
        digitalWrite(13, HIGH);
        Serial.println(" LEFT ");
        digitalWrite(motorL, LOW);
        // digitalWrite(lf_2, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(motorR, HIGH);


      }
      else if (state == 'R')
      {
        digitalWrite(13, HIGH);
        Serial.println(" RIGHT ");

        // analogWrite(lf_1, 190);
        digitalWrite(motorR, LOW);
        digitalWrite(12, LOW);
        digitalWrite(motorL, HIGH);

        digitalWrite(11, LOW);
        //      digitalWrite(rf_2, HIGH);
        //      digitalWrite(rb_1, LOW);
        //      digitalWrite(rb_2, HIGH);
      }

      else if (state == 'S')
      {
        digitalWrite(13, LOW);
        Serial.println(" STOP ");
        digitalWrite(motorL, LOW);
        digitalWrite(motorR, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        //
        //      digitalWrite(rf_1, LOW);
        //      digitalWrite(rf_2, LOW);
        //      digitalWrite(rb_1, LOW);
        //      digitalWrite(rb_2, LOW);
      }

    }
  }
  void OAR()
  {
    delay(50);
    long t = 0, h = 0; // Transmitting pulse
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);// Waiting for pulse
    t = pulseIn(echo, HIGH);// Calculating distance
    h = (t / 2) / 29.1; // Sending to computer
    Serial.print(h);// Serial.print(" cm\n");
   // Serial.print("\n");//condition for motors
    digitalWrite(motorL, HIGH);
    digitalWrite(motorR, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    //digitalWrite(motorR,HIGH);// turning motor right //
    if (h <= 25)
    {
      digitalWrite(motorL, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(motorR, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);

      //delay(500);
    }
  }



