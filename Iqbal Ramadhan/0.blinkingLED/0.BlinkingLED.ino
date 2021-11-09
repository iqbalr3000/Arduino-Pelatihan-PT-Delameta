int R=2; //variable untuk lampu merah
int Y=3; //variable untuk lampu kuning
int G=4; //variable untuk lampu hijau

void setup() {

  pinMode(R,OUTPUT); //lampu merah sebagai output
  pinMode(Y,OUTPUT); //lampu kuning sebagi output
  pinMode(G,OUTPUT); //lampu hijau sebagai output
  

}

void loop() {

  //Lampu merah kuning dan hijau menyala bergantian

  //lampu merah
  digitalWrite(R,HIGH); //nyala
  delay(1000);

  digitalWrite(R,LOW); //mati
  delay(1000);

  //lampu kuning
  digitalWrite(Y,HIGH); //nyala
  delay(1000);

  digitalWrite(Y,LOW); //mati
  delay(1000);

  //lampu hijau
  digitalWrite(G,HIGH); //nyala
  delay(1000);

  digitalWrite(G,LOW); //mati
  delay(1000);


  //lampu merah kuning dan hijau menyala

//  digitalWrite(R,HIGH); //nyala
//  digitalWrite(Y,HIGH); //nyala
//  digitalWrite(G,HIGH); //nyala
//  delay(1000);

  
  
}
