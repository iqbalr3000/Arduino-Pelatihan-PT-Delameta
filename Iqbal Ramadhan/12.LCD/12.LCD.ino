//menggunakan library
#include<LiquidCrystal_I2C.h>

//inisialisasi variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin();
}

void loop() {
  lcd.clear();//menghapus karakter pada lcd
  lcd.setCursor(5,0);
  lcd.print("Welcome");
  lcd.setCursor(4,1);
  lcd.print("iqbal");
  delay(1000);//jeda waktu perulangan selama 1000 mili detik atau 1 detik

  lcd.clear();//menghapus karakter pada lcd
  lcd.setCursor(1,0);
  lcd.print("Welcome home");
  lcd.setCursor(4,1);
  lcd.print("iqbal");
  delay(1000);//jeda waktu perulangan selama 1000 mili detik atau 1 detik
}
