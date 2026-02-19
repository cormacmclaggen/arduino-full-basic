#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();        // Initialize I2C LCD
  lcd.backlight();   // Turn on I2C LCD backlight
}

void loop()
{
  lcd.print("Hello, arduino!"); // Print "Hello, arduino!"
  lcd.noDisplay();              // Turn off display
  delay(1000);                  // Delay 1 second

  lcd.display();                // Turn on display
  delay(1000);                  // Delay 1 second

  lcd.clear();                  // Clear LCD screen
}

