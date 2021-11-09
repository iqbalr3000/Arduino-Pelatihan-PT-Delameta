//add mfrc library
#include<SPI.h>
#include<MFRC522.h>

//inisialisasi variable untuk mfrd522
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN,RST_PIN);

//inisialisasi variable tambahan
int pinBuzzer = 8;

void setup() {
  
  Serial.begin(9600);

  //initiate SPI bus
  SPI.begin();
  
  //initiate MFRC522
  mfrc522.PCD_Init();

  //atur pin mode output atau input
  pinMode(pinBuzzer,OUTPUT);
}

void loop() {

  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  //select one of the card
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }

  //Show UID on serial monitor
  Serial.print("UID tag : ");
  String content="";
  byte letter;
  
  for(byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if(content == "8A375A1A"){//sesuaikan dengan id card
    Serial.println("Selamat Datang Iqbal");
    buzzerBunyi();
  }else if(content == "058656BF90D100"){
    Serial.println("Selamat Datang Teman");
    buzzerBunyi();
  }else{
    Serial.println("Kartu Belum Terdaftar");
    digitalWrite(pinBuzzer,HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
  }

  Serial.println("Tempelkan Kartu!");
  digitalWrite(pinBuzzer,LOW);
  delay(500);

}

void buzzerBunyi(){
  digitalWrite(pinBuzzer, HIGH);
  delay(1000);
}
