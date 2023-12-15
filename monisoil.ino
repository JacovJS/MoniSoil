#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int buzzerPin = 8;
dht DHT;

#define DHT11_PIN A0

void setup(){
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);
  lcd.begin();
  lcd.backlight();
}

void loop(){
  if (DHT.temperature < 25) {
    tone(buzzerPin, 587); // D4
    delay(1000);
  }
  else if (DHT.humidity < 60) {
    tone(buzzerPin, 523); // C4
    delay(1000);
  }
  int chk = DHT.read11(DHT11_PIN);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
}
