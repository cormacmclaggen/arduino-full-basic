#include <LiquidCrystal_I2C.h>

// Create an I2C LCD object with 16 columns and 2 rows
// The I2C address of the LCD is usually set to 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();        // Initialize I2C LCD
  lcd.backlight();   // Turn on I2C LCD backlight
}

void loop()
{
  lcd.setCursor(0, 0);        // Move cursor to column 0 of row 0 (top-left)
  lcd.print("Welcome to");   // Display message on I2C LCD

  lcd.setCursor(1, 1);        // Move cursor to column 1 of row 1 (bottom row)
  lcd.print("ARDUINO world !"); // Display message on I2C LCD
}

