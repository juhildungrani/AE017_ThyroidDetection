// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buzzer=2;
int green=3;
int red=4;
unsigned char cmd;

void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
}

void loop() 
{
  if(Serial.available()>0)
  {
    cmd = Serial.read();
    if(cmd == 'N')
    {
      lcd.clear();
      lcd.print("Normal Ultrasnd");
      digitalWrite(buzzer,LOW);
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
    }
    else if(cmd == 'T')
    {
      lcd.clear();
      lcd.print("Thyroid Detected");
      digitalWrite(buzzer,HIGH);
      delay(5000);
      digitalWrite(buzzer,LOW);
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);     
    }
  }

}
