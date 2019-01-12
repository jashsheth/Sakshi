#include <AFMotor.h>

#define lf_1 3
#define lf_2 4
#define lb_1 5
#define lb_2 6

#define rf_1 9
#define rf_2 10
#define rb_1 7
#define rb_2 8


int c = 0;
//int 12;
//int stat;
char state = 'u0000';
void setup() {
 int stat;
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(stat, INPUT);
  Serial.println(c);
  pinMode(lf_1, OUTPUT);
  pinMode(lf_2, OUTPUT);
  pinMode(lb_1, OUTPUT);
  pinMode(lb_2, OUTPUT);

  pinMode(rf_1, OUTPUT);
  pinMode(rf_2, OUTPUT);
  pinMode(rb_1, OUTPUT);
  pinMode(rb_2, OUTPUT);
  Serial.println("Stsrting : ");
  // put your setup code here, to run on
  pinMode(2, INPUT);
}
int check_char(char a, char b)
{
  if (a == b)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  //if(digitalRead(stat)==HIGH)
  //{
  int stat = digitalRead(2);
  Serial.println(stat);

  if (stat == 0)
  {

    Serial.println("Error ");
    digitalWrite(lf_1, LOW);
    digitalWrite(lf_2, LOW);
    digitalWrite(lb_1, LOW);
    digitalWrite(lb_2, LOW);

    digitalWrite(rf_1, LOW);
    digitalWrite(rf_2, LOW);
    digitalWrite(rb_1, LOW);
    digitalWrite(rb_2, LOW);
  }


  if (Serial.available() > 0)
  {
    /*char prev_state = state;
    state = Serial.read();
    Serial.println("\t "+state);
    int ans = check_char(prev_state, state);
    switch (ans)
    {
      case 0:
        c = c;
        break;
      case 1:
        c = 0;
        break;
      default:
        Serial.println("NOT DEFINED ");
    }*/
    if (state == 'F')

    {
      digitalWrite(13, HIGH);
      Serial.println("Forward ");
      {
        for (int i = 0; i <= 255; i++)
        {
          Serial.println("accelerating");
          analogWrite(lf_1, i);
          digitalWrite(lf_2, LOW);
          analogWrite(lb_1, i);
          digitalWrite(lb_2, LOW);

          analogWrite(rf_1, i);
          digitalWrite(rf_2, LOW);
          analogWrite(rb_1, i);
          digitalWrite(rb_2, LOW);
          delay(30);
        }
      }

      digitalWrite(lf_1, HIGH);
      digitalWrite(lf_2, LOW);
      digitalWrite(lb_1, HIGH);
      digitalWrite(lb_2, LOW);

      digitalWrite(rf_1, HIGH);
      digitalWrite(rf_2, LOW);
      digitalWrite(rb_1, HIGH);
      digitalWrite(rb_2, LOW);

    }



  }
  else if (state == 'B')
  {
    {
      for (int i = 0; i = 255; i++)
      {
        digitalWrite(13, HIGH);
        Serial.println(" BACKWARD ");

        digitalWrite(lf_1, LOW);
        analogWrite(lf_2, i);
        digitalWrite(lb_1, LOW);
        analogWrite(lb_2, i);

        digitalWrite(rf_1, LOW);
        analogWrite(rf_2, i);
        digitalWrite(rb_1, LOW);
        analogWrite(rb_2, i);
        delay(30);
      }
      digitalWrite(lf_1, LOW);
      digitalWrite(lf_2, HIGH);
      digitalWrite(lb_1, LOW);
      digitalWrite(lb_2, HIGH);

      digitalWrite(rf_1, LOW);
      digitalWrite(rf_2, HIGH);
      digitalWrite(rb_1, LOW);
      digitalWrite(rb_2,HIGH);
    }
  }
    else if (state == 'L')

    {
      digitalWrite(13, HIGH);
      Serial.println(" LEFT ");
      digitalWrite(lf_1, LOW);
      digitalWrite(lf_2, HIGH);
      digitalWrite(lb_1, LOW);
      digitalWrite(lb_2, HIGH);

      digitalWrite(rf_1, HIGH);
      digitalWrite(rf_2, LOW);
      digitalWrite(rb_1, HIGH);
      digitalWrite(rb_2, LOW);
    }
    else if (state == 'R')
    {
      digitalWrite(13, HIGH);
      Serial.println(" RIGHT ");

      digitalWrite(lf_1, HIGH);
      digitalWrite(lf_2, LOW);
      digitalWrite(lb_1, HIGH);
      digitalWrite(lb_2, LOW);

      digitalWrite(rf_1, LOW);
      digitalWrite(rf_2, HIGH);
      digitalWrite(rb_1, LOW);
      digitalWrite(rb_2, HIGH);
    }

    else if (state == 'S')
    {
      digitalWrite(13, LOW);
      Serial.println(" STOP ");
      digitalWrite(lf_1, LOW);
      digitalWrite(lf_2, LOW);
      digitalWrite(lb_1, LOW);
      digitalWrite(lb_2, LOW);

      digitalWrite(rf_1, LOW);
      digitalWrite(rf_2, LOW);
      digitalWrite(rb_1, LOW);
      digitalWrite(rb_2, LOW);
    }

}



