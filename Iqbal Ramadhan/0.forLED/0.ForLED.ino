void setup() {

  for(int i=2; i<=4; i++){ //nilai i akan terus bertambah mulai dari 2 sampai 4
    pinMode(i,OUTPUT);
  }

}

void loop() {

  //Lampu merah kuning hijau menyala bergantian menggunakan loop dengan variable i, delay tidak bisa berbeda beda

   for(int i=2; i<=4; i++){
      digitalWrite(i,HIGH);
      delay(100);
      digitalWrite(i,LOW);
      delay(100);
    }
  
  
}
