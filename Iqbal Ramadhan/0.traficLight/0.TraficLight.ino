int R=2; //variable untuk lampu merah
int Y=3; //variable untuk lampu kuning
int G=4; //variable untuk lampu hijau

void setup() {

  pinMode(R,OUTPUT); //lampu merah sebagai output
  pinMode(Y,OUTPUT); //lampu kuning sebagi output
  pinMode(G,OUTPUT); //lampu hijau sebagai output

}

void loop() {

//  //Lampu merah kuning dan hijau menyala bergantian cara 1
//
//  //lampu merah
//  digitalWrite(R,HIGH); //nyala
//  delay(3000);
//  digitalWrite(R,LOW); //mati
//  delay(3000);
//
//  //lampu kuning
//  digitalWrite(Y,HIGH); //nyala
//  delay(1000);
//  digitalWrite(Y,LOW); //mati
//  delay(1000);
//  
//  //lampu hijau
//  digitalWrite(G,HIGH); //nyala
//  delay(2000);
//  digitalWrite(G,LOW); //mati
//  delay(2000);

  //Lampu merah kuning hijau menyala bergantian cara 2

  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(5000);

  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  digitalWrite(G,LOW);
  delay(2000);

  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,HIGH);
  delay(1000);
  
  
}
