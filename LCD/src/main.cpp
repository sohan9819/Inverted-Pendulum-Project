#include <Arduino.h>
#include <LiquidCrystal.h>

// Define the LCD pin connections
#define LCD_RS 12
#define LCD_EN 11
#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

// Create an instance of the LCD library
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup()
{
  // put your setup code here, to run once:
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("Hello world");
  lcd.setCursor(0, 1);
  lcd.print("This is IP");
}