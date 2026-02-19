#include <LiquidCrystal_I2C.h>

// Create I2C LCD object (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// User-defined character data (8 bytes per character)
// Each byte represents one row (5x8 dot matrix)

byte char_00[8] = {0x00, 0x0E, 0x1B, 0x11, 0x11, 0x1B, 0x0E, 0x00}; 
byte char_01[8] = {0x08, 0x08, 0x08, 0x0E, 0x08, 0x08, 0x08, 0x08};  
byte char_02[8] = {0x0F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0F, 0x00}; 
byte char_12[8] = {0x1F, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00};
byte char_05[8] = {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}; 
byte char_06[8] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0F, 0x00};
byte char_16[8] = {0x04, 0x04, 0x04, 0x1F, 0x00, 0x00, 0x00, 0x00};
byte heart[8] = {0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00};

void setup()
{
  lcd.init();          // Initialize I2C LCD
  lcd.backlight();     // Turn on LCD backlight

  // Up to 8 user-defined characters can be stored (index 0–7)
  lcd.createChar(0, char_00);   
  lcd.createChar(1, char_01);   
  lcd.createChar(2, char_02);   
  lcd.createChar(3, char_05);   
  lcd.createChar(4, char_06);   
  lcd.createChar(5, char_12);   
  lcd.createChar(6, char_16);
  lcd.createChar(7, heart); 

  lcd.clear();          // Clear LCD screen
}

void loop()
{
  lcd.setCursor(0, 0);          // Move cursor to first row, first column
  lcd.write(byte(7));           // Display heart symbol

  lcd.setCursor(2, 0);
  lcd.write(byte(0)); 

  lcd.setCursor(3, 0);
  lcd.write(byte(1));           

  lcd.setCursor(4, 0);
  lcd.write(byte(2));           

  lcd.setCursor(4, 1);
  lcd.write(byte(5));           

  lcd.setCursor(6, 0);
  lcd.write(byte(0)); 

  lcd.setCursor(7, 0);
  lcd.write(byte(3)); 

  lcd.setCursor(8, 0);
  lcd.write(byte(4));

  lcd.setCursor(8, 1);
  lcd.write(byte(6));
}
