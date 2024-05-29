#include <Wire.h>

#define kirmiziLed 8
#define yesilLed 9

void setup()
{
  Wire.begin(0x2); // i2c adresini ayarla
  Serial.begin(9600);
  pinMode(kirmiziLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  Wire.onReceive(receiveEvent); 
}

void loop()
{
  // Loop'un içinde bir şey yapılmıyor, ama boş bırakılmalı
}
void receiveEvent(int howMany) {
  while (Wire.available()) {
    byte c = Wire.read(); // Gelen veriyi oku
    Serial.print("Alinan veri: ");
    Serial.println(c);
    
    if (c == 1) {
      digitalWrite(kirmiziLed, HIGH);
      digitalWrite(yesilLed, LOW);
    } else if (c == 2) {
      digitalWrite(yesilLed, HIGH);
      digitalWrite(kirmiziLed, LOW);
    } else if (c == 3) {
      digitalWrite(kirmiziLed, HIGH);
      digitalWrite(yesilLed, HIGH);
    } else {
      digitalWrite(kirmiziLed, LOW);
      digitalWrite(yesilLed, LOW);
    }
  }
}