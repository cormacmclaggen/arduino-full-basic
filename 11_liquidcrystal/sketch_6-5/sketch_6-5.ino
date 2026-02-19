#include <LiquidCrystal_I2C.h>

char array1[] = "Hello, world!        ";   // Text displayed on the top row
char array2[] = "Nice to meet you.    ";   // Text displayed on the bottom row
int delayTime = 500;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD address 0x27, 16x2 display

void setup()
{
  lcd.init();        // Initialize I2C LCD
  lcd.backlight();   // Turn on I2C LCD backlight
}

void loop()
{
  lcd.setCursor(15, 0);   // Set cursor to the far right of the top row
  for (int posCnt1 = 0; posCnt1 < 26; posCnt1++)
  {
    lcd.scrollDisplayLeft();     // Scroll display left by one position
    lcd.print(array1[posCnt1]); // Print character to I2C LCD
    delay(delayTime);
  }

  lcd.clear();                   // Clear LCD screen
  lcd.setCursor(15, 1);          // Set cursor to the far right of the bottom row
  for (int posCnt2 = 0; posCnt2 < 26; posCnt2++)
  {
    lcd.scrollDisplayLeft();     // Scroll display left by one position
    lcd.print(array2[posCnt2]); // Print character to I2C LCD
    delay(delayTime);
  }

  lcd.clear();                   // Clear LCD screen
}
