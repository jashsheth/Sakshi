


AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor1(1, MOTOR12_64KHZ);
int state = 0;

void setup() <br>{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Welcome: Forward = 1 Left = 2 Right = 3 Backwards = 4 Stop = 0");
  motor2.setSpeed(200);     // set the speed to 200
  motor1.setSpeed(200);     // set the speed to 200
}

void loop(){   //if some data is sent, read it and save it in the state variable

if(Serial.available() > 0)
  {
    state = Serial.read();
    Serial.print("I received: ");
    Serial.println(state);
    delay(10);</p>
if (state == '0') 
    {
      motor2.setSpeed(200);     // set the speed to 200/255
      motor1.setSpeed(200);     // set the speed to 200/255
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      Serial.println("Stopped");
      delay(100);
      state = 0; 
    }
else if (state == '1')      // If 1 Forwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(200);     // set the speed to 200
      motor1.setSpeed(200);     // set the speed to 200
      motor2.run(FORWARD);      // turn it on going forward
      motor1.run(FORWARD);      // turn it on going forward
      Serial.println("Forward");
      delay(100);
      state = 0; 
    }
else if (state == '2')      // If 2 Turn Left
    { 
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward  
      motor1.setSpeed(255);     // set the speed to 200/255
      motor1.run(FORWARD);
      //motor2.run(BACKWARD);      
      Serial.println("Left");
      delay(100);
      state = 0;     
    }
else if (state == '3') {    // If 3 Turn Right
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(255);     // set the speed to 255
      motor2.run(FORWARD);      
      //motor1.run(BACKWARD);    
      Serial.println("Right");
      delay(100);
      state = 0;  
    }
else if (state == '4')       // If 4 Backwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(200);      // set the speed to 200
      motor1.setSpeed(200);      // set the speed to 200
      motor2.run(BACKWARD);      // Motor 2 backwards
      motor1.run(BACKWARD);      // Motor 1 backwards
      Serial.println("Backward");
      delay(100);
      state = 0;   
    }
else if (state == '5') 
    {
      motor2.run(RELEASE);      // turn it on going release
      motor1.run(RELEASE);      // turn it on going release
      motor2.setSpeed(255);     // set the speed to 255
      motor1.setSpeed(140);     // set the speed to 140
      motor2.run(FORWARD);      // Motor 2 forward
      motor1.run(FORWARD);      // Motor 1 forward
      Serial.println("Forward Right");
      delay(100);
      state = 0;   
     }
else if (state == '6') 
    {
      motor2.run(RELEASE);      // turn it on going release
      motor1.run(RELEASE);      // turn it on going release
      motor1.setSpeed(255);     // set the speed to 255
      motor2.setSpeed(140);     // set the speed to 140
      motor2.run(FORWARD);      // Motor 2 forward
      motor1.run(FORWARD);      // Motor 1 forward
      Serial.println("Forward Left");
      delay(100);
      state = 0;   
     }
else if (state == '7')       // If 4 Backwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor1.setSpeed(255);     // set the speed to 255
      motor2.setSpeed(140);     // set the speed to 140
      motor2.run(BACKWARD);      // Motor 2 backwards
      motor1.run(BACKWARD);      // Motor 1 backwards
      Serial.println("Backward Right");
      delay(100);
      state = 0;   
    }
else if (state == '8')       // If 4 Backwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(255);     // set the speed to 255
      motor1.setSpeed(140);     // set the speed to 140
      motor2.run(BACKWARD);      // Motor 2 backwards
      motor1.run(BACKWARD);      // Motor 1 backwards
      Serial.println("Backward Left");
      delay(100);
      state = 0;   
    }
else if (state >= '9')
    {
      Serial.println("Invalid");
      delay(100);
      state = 0; 
    }
  }
}
<br>
