#include <Wire.h>

void setup() {
  Wire.begin(); // I2C master olarak başlat
  Serial.begin(9600); // Seri haberleşmeyi başlat
  Serial.println("Bir sayi girin ve Enter'a basin:"); // Kullanıcıya mesaj gönder
}

void loop() {
  if (Serial.available() > 0) {
    // Kullanıcıdan gelen veriyi oku
    int sayi = Serial.parseInt();
    
    // I2C üzerinden veri gönder
    Wire.beginTransmission(0x2); // 0x2 adresine gönderim başlat
    Wire.write(sayi); // Sayıyı gönder
    Wire.endTransmission(); // Gönderimi sonlandır

    // Girilen sayıyı geri yaz
    Serial.print("Gönderilen sayi: ");
    Serial.println(sayi);

    delay(11000); // 1 saniye bekle
  }
}
