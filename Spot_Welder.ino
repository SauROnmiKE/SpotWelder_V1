#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int relayPin = 2;
int btnpinwelddouble = 3;
int btnpininc = 4;
int btnpindec = 5;
int btnpinweld = 6;
int btnpindelay = 1;
int delayRelay = 20;
int delaybetween = 50;
void setup()
{
  pinMode(relayPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Mike Welder");
  lcd.setCursor(0, 1);
  lcd.print("Loading.");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.print(".");
  delay(1000);
  lcd.clear();
  lcd.print("Loading Complete!");
  lcd.setCursor(0, 1);
  lcd.print("    Welcome!");
  delay(3000);
  lcd.clear();
  lcd.print("Copyright(c)2016");
  lcd.setCursor(0, 1);
  lcd.print("   SauROnmiKE");
  delay(1500);
  lcd.clear();
  lcd.print(delayRelay);
  lcd.print("ms");
  lcd.print( " Delay:");
  lcd.print(delaybetween);
  lcd.setCursor(0, 1);
  lcd.print("Ready to weld!");
}

void loop()
{
  if (digitalRead(btnpinwelddouble) == LOW)
  {
    delay(550);
    if (digitalRead(btnpinwelddouble) == LOW)
    {
      digitalWrite(relayPin, HIGH);
      delay(delayRelay);

      digitalWrite(relayPin, LOW);
      delay(delaybetween);

      digitalWrite(relayPin, HIGH);
      delay(delayRelay);

      digitalWrite(relayPin, LOW);

      lcd.clear();
      lcd.print(delayRelay);
      lcd.print("ms");
      lcd.print( " Delay:");
      lcd.print(delaybetween);
      lcd.setCursor(0, 1);
      lcd.print("Double Pulse");
    }
  }

  if (digitalRead(btnpininc) == LOW)
  {
    delay(85);
    if (digitalRead(btnpininc) == LOW)
    {
      delayRelay = delayRelay + 5;
      lcd.clear();
      lcd.print(delayRelay);
      lcd.print("ms");
      lcd.print( " Delay:");
      lcd.print(delaybetween);
      lcd.setCursor(0, 1);
      lcd.print("Ready to weld!");
    }
  }

  if (digitalRead(btnpindec) == LOW)
  {
    delay(85);
    if (digitalRead(btnpindec) == LOW)
    {
      if (delayRelay >= 5)
      {
        delayRelay = delayRelay - 5;
        lcd.clear();
        lcd.print(delayRelay);
        lcd.print("ms");
        lcd.print( " Delay:");
        lcd.print(delaybetween);
        lcd.setCursor(0, 1);
        lcd.print("Ready to weld!");
      }
    }
  }

  if (digitalRead(btnpinweld) == LOW)
  {
    delay(550);
    if (digitalRead(btnpinweld) == LOW)
    {
      digitalWrite(relayPin, HIGH);
      delay(delayRelay);

      digitalWrite(relayPin, LOW);

      lcd.clear();
      lcd.print(delayRelay);
      lcd.print("ms");
      lcd.print( " Delay:");
      lcd.print(delaybetween);
      lcd.setCursor(0, 1);
      lcd.print("Single Pulse");
    }
  }

  if (digitalRead(btnpindelay) == LOW)
  {
    delay(125);
    if (digitalRead(btnpindelay) == LOW)
    {
      if (delaybetween <= 500)
      {
        delaybetween = delaybetween + 50;
        lcd.clear();
        lcd.print(delayRelay);
        lcd.print("ms");
        lcd.print( " Delay:");
        lcd.print(delaybetween);
        lcd.setCursor(0, 1);
        lcd.print("Ready to weld!");


      }
      else
      {
        delaybetween = 0;
      }
    }
  }
}
