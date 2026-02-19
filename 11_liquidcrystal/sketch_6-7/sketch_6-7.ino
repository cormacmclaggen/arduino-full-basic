#include <LiquidCrystal_I2C.h>
#include <DHT.h>              // Using DHT11

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  lcd.init();                 // Initialize I2C LCD
  lcd.backlight();            // Turn on backlight
  lcd.clear();
}

void loop() {
  delay(3000);

  float tem = dht.readTemperature();
  float hum = dht.readHumidity();

  // If sensor read fails, stop the program
  if (isnan(tem) || isnan(hum)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Display temperature on LCD
  lcd.setCursor(1, 0);
  lcd.print("Temp : ");
  lcd.setCursor(8, 0);
  lcd.print(tem, 1);
  lcd.print(" C");

  // Display humidity on LCD
  lcd.setCursor(1, 1);
  lcd.print("Humi : ");
  lcd.setCursor(8, 1);
  lcd.print(hum, 1);
  lcd.print(" %");

  // Print values to Serial Monitor
  Serial.print("Temperature : ");
  Serial.print(tem);
  Serial.print(" C ");
  Serial.print("Humidity : ");
  Serial.print(hum);
  Serial.println("%");
}
