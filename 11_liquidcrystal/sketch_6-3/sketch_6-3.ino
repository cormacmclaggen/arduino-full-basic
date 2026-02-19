#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();        // Initialize I2C LCD
  lcd.backlight();   // Turn on I2C LCD backlight
}

void loop()
{
  lcd.print("Cursor Blink"); // Print "Cursor Blink"
  lcd.cursor();              // Show cursor
  lcd.blink();               // Enable cursor blinking
  delay(3000);               // Delay 3 seconds

  lcd.clear();               // Clear LCD screen
  lcd.print("Cursor Out");   // Print "Cursor Out"
  lcd.noBlink();             // Stop cursor blinking
  delay(3000);               // Delay 3 seconds

  lcd.clear();               // Clear LCD screen
  lcd.noCursor();            // Hide cursor
  delay(3000);               // Delay 3 seconds

  lcd.clear();               // Clear LCD screen
}
