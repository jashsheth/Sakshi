unsigned long counters = 0;
unsigned long rem = 0;
unsigned long due = 0;
unsigned long currentMillis = 0, addmillis = 0, addmillis1 = 0;
/*
  Rotary Encoder Demo
  rot-encode-demo.ino
  Demonstrates operation of Rotary Encoder
  Displays results on Serial Monitor
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Rotary Encoder Inputs
#define inputCLK 10
#define inputDT 9
#define but 3
#define rlypin 7

// LED Outputs
#define ledCW 3
#define ledCCW 2
uint8_t en = 0;
uint32_t counter, tim = 0;
int ss = 0;
int currentStateCLK;
int previousStateCLK;

String encdir = "";

void setup() {

  // Set encoder pins as inputs
  pinMode (inputCLK, INPUT);
  pinMode (inputDT, INPUT);

  // Set LED pins as outputs
  pinMode (but, INPUT_PULLUP);
  pinMode (rlypin, OUTPUT);

  // Setup Serial Monitor
  Serial.begin (115200);
  Serial.println("Jash ");
  // Read the initial state of inputCLK
  // Assign to previousStateCLK variable
  previousStateCLK = digitalRead(inputCLK);
}

void loop() {

  // Update previousStateCLK with the current state
  if (Serial.available() > 0)
  {
    Serial.println("In input ");
    int tim = (Serial.readStringUntil('\n')).toInt();
    if (tim != 0)
    {
      Serial.print("Timer set for ");
      Serial.print("\t");
      Serial.print(tim);
      Serial.print("  seconds");
      counters = millis() / 1000;
      due = counters + tim;
      Serial.println(counters);
      // Serial.println("-----------------------------------------------");
      Serial.println(due);
      ss = 1;
      //delay(2000);
    }
  }
  if (digitalRead(but) == LOW )
  {
    delay(50);
    if (digitalRead(but) == LOW )
    {
      en++;
      if (en == 1)
      {
        ss = 0;
        Serial.println("Paused");
        addmillis = millis();

      }
      if (en == 2)
      {
        addmillis1 = ((millis() - addmillis) / 1000);
        due += addmillis;
        en = 0;
        ss = 1;
      }
    }
  }
  if (currentMillis < due && ss == 1)
  {
    currentMillis = millis() / 1000;
    Serial.print("Time left : ");
    Serial.print("\t");
    int remm = due - currentMillis;
    Serial.print(remm);
    Serial.print("  seconds");
    Serial.println();

  }
  else
  {
    ss = 0;
    tim, counter = 0;
  }
  //  if (ss == 1)
  //  {
  //    //int a = 1;
  //    Serial.println("Relay ONN");
  //    currentMillis = millis() / 1000;
  //    while (currentMillis <= due)
  //    {
  //      //Serial.println(counters);
  //      Serial.print("Time left : ");
  //      Serial.print("\t");
  //      int remm = due - currentMillis;
  //      Serial.print(remm);
  //      Serial.print("  seconds");
  //      Serial.println();
  //      currentMillis = millis() / 1000;
  //      // Serial.println(currentMillis);
  //      // delay(100);
  //    }
  //    Serial.println("Relay oFF");
  //    ss = 0;
  //    tim, counter = 0;
  //    //currentMillis = millis();
  //  }
}
