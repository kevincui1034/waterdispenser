#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,9,10,11,12,13);

int leds = 5;
float value;

void setup()
{
  lcd.begin(16,2);
  lcd.print("Power on");
  delay(3000);
  lcd.clear();
  pinMode(A0, INPUT);
  pinMode(6, INPUT);
  
  for(int i = 2; i <= leds; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
  
{
  static int buttonpress;

 
  buttonpress = digitalRead(6);
  if(buttonpress==HIGH)
  {
  	lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Dispensing...");
    delay(3000);
    lcd.clear();
  }
    if(digitalRead(2)==LOW)
    {
  		lcd.setCursor(0, 0);
    	lcd.print("Hello!");
    	lcd.setCursor(0, 1);
    	lcd.print("Select amount");
    	delay(1000);
    	lcd.clear();
    }
    if(digitalRead(2)==HIGH && digitalRead(3)==LOW)
    {
      	lcd.setCursor(0, 0);
    	lcd.print("Amount of Water:");
    	lcd.setCursor(0, 1);
    	lcd.print("32 oz");
      	delay(1500);
      	lcd.clear();
    }
    if(digitalRead(3)==HIGH && digitalRead(4)==LOW)
    {
      	lcd.setCursor(0, 0);
    	lcd.print("Amount of Water:");
    	lcd.setCursor(0, 1);
    	lcd.print("64 oz");
      	delay(3000);
      	lcd.clear();
    }
    if(digitalRead(4)==HIGH && digitalRead(5)==LOW)
    {
      	lcd.setCursor(0, 0);
    	lcd.print("Amount of Water:");
    	lcd.setCursor(0, 1);
    	lcd.print("96 oz");
      	delay(3000);
      	lcd.clear();
    }
    if(digitalRead(5)==HIGH)
    {
      	lcd.setCursor(0, 0);
    	lcd.print("Amount of Water:");
    	lcd.setCursor(0, 1);
    	lcd.print("128 oz");
      	delay(3000);
      	lcd.clear();
    }
   

  value = analogRead(A0);
  value = map(value, 0, 1023, 1, leds);
  for(int i = 2; i <= leds; i++)
  {
      if (value >= i){
      digitalWrite(i, HIGH);
  } else
      {
      digitalWrite(i, LOW);
      }
  }
  
}