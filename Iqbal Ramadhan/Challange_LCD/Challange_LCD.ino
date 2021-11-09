//menggunakan library mfrc522
#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>

//inisiasi variable mfrc522
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

//inisiasi variabel tambahan
int buzzer = 8;
int infrared = 7;
String uidString;
int kunci = 0;

//inisialisasi variable lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  lcd.begin();
  mfrc522.PCD_Init();
  
  pinMode(buzzer,OUTPUT);
  pinMode(infrared,INPUT);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Kartu!");
}

void loop() {
  //Baca Data
  if(mfrc522.PICC_IsNewCardPresent() && kunci == 0){
    readRFID();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tag UID : ");
    lcd.setCursor(0,1);
    lcd.print(uidString);
    
    if(uidString == "8A-B0-C1-15"){
      buzzerBunyi();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Berhasil!");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Palang dibuka");
      lcd.setCursor(0,1);
      lcd.print("Silahkan masuk");
      kunci = 1;
    }else if(uidString == "5-86-56-BF"){
      buzzerBunyi();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Berhasil!");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Palang dibuka");
      lcd.setCursor(0,1);
      lcd.print("Silahkan masuk");
      kunci = 1;
    }
    else{
      buzzerBunyiGagal();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("GAGAL!");
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tempelkan Kartu!");
    }
    
  }

  infraredNyala();

}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //pembatas bisa dirubah sesuai keinginan, disini yang digunakan "-"
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

void buzzerBunyi(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}

void buzzerBunyiGagal(){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
}

void infraredNyala(){
  int readInfrared = digitalRead(infrared);

  if(readInfrared == 0 && kunci == 1){
    buzzerBunyi();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Palang ditutup");
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempelkan Kartu!");
    kunci = 0;
  }

}
