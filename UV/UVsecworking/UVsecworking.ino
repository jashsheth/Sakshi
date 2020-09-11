#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 5, en = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
#define inputCLK 14
#define inputDT 15
#define but 16
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
uint8_t ss = 0;
uint32_t lastTime;
int tim = 0;
uint8_t rly = 2;
void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(rly, OUTPUT);
  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);

  // Set LED pins as outputs
  pinMode(but, INPUT_PULLUP);
  // put your setup code here, to run once:
  Serial.println("Jash ");
}

void loop() {
  if (Serial.available() > 0)
  {
    Serial.println("In input ");
    tim = (Serial.readStringUntil('\n')).toInt();
    if (tim != 0)
    {
      Serial.print("Timer set for ");
      Serial.print("\t");
      Serial.print(tim);
      Serial.print("  seconds");
      ss = 1;
      //delay(2000);
      digitalWrite(rly, HIGH);
      lastTime = millis();
    }
  }
  // put your main code here, to run repeatedly:
  if ((millis() - lastTime >= 1000) && ss == 1)
  {
    tim--;
    lastTime += 1000;
    Serial.println(tim);
    if (tim == 0)
    {
      Serial.println("Done ");
      digitalWrite(rly, LOW);
      ss = 0;
    }
  }
}
