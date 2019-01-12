#include <Servo.h>

int a=7;
char data;
void setup() {
  pinMode(a,OUTPUT);
  
Serial.begin(9600);
//m.attach(7);
// m.write(130);
}

void loop() {

   if(Serial.available() > 0)  

   
   {
    
   
      data = Serial.read();        //Read the  incoming  data and store it into variable data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");          //New line
      if(data =='F')     
      {
        digitalWrite(a,HIGH);
     //   m.write(150);
        Serial.println("LIGHT on");
      }
        
      else if(data =='S')         
   {
    digitalWrite(a,LOW);
   // m.write(310);
        Serial.println("LIGHT off");
   }
}
  

}
