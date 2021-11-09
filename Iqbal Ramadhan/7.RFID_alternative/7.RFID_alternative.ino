//menggunakan library mfrc522
#include<SPI.h>
#include<MFRC522.h>

//inisiasi variable mfrc522
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

//inisiasi variabel tambahan
int buzzer = 8;
int infrared = 7;
String uidString;
int kunci = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  pinMode(buzzer,OUTPUT);
  pinMode(infrared,INPUT);

  Serial.println("Tempelkan Kartu!");
}

void loop() {
  //Baca Data
  if(mfrc522.PICC_IsNewCardPresent() && kunci == 0){
    readRFID();
    Serial.print("Tag UID : ");
    Serial.println(uidString);
    
    if(uidString == "8A-37-5A-1A"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      delay(500);
      Serial.println("Palang dibuka, Silahkan Masuk");
      kunci = 1;
    }else if(uidString == "5-86-56-BF"){
      buzzerBunyi();
      Serial.println("Berhasil!");
      delay(500);
      Serial.println("Palang dibuka, Silahkan Masuk Teman");
      kunci = 1;
    }
    else{
      buzzerBunyiGagal();
      Serial.println("GAGAL!");
      Serial.println("");
      Serial.println("Tempelkan Kartu!");
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
    Serial.println("Palang ditutup");
    Serial.println("");
    Serial.println("Tempelkan Kartu!");
    kunci = 0;
  }

}
