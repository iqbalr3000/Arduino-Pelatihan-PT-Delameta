void setup() {

  Serial.begin(9600);
  for(int i=3; i<=6; i++){ //nilai i akan terus bertambah mulai dari 2 sampai 4
    pinMode(i,OUTPUT);
  }

}

void loop() {

  //lampu merah kuning hijau menyala berbarengan redup dan terang
  for(float i=0.0; i<=255.0; i++){
    analogWrite(3,i);
//    float volt=map(i,0,255,0,5); //konvensi nilai pwm ke volt dari 0-255 menjadi 0-5
    float volt = (5.0/255.0);
    float hasil = i*volt;
//    Serial.println("Nilai : " + String(hasil) + " volt"); //menampikan hasil dari volt
  Serial.println(hasil);
    delay(10);
  }
  
  for(float i=255.0; i>=0.0; i--){
    analogWrite(3,i);
//    float volt=map(i,0,255,0,5); //konvensi nilai pwm ke volt dari 0-255 menjadi 0-5
    float volt = (5.0/255.0);
    float hasil = i*volt;
//    Serial.println("Nilai : " + String(hasil) + " volt"); //menampilkan hasil dari volt
    Serial.println(hasil);
    delay(10);
  }


}
