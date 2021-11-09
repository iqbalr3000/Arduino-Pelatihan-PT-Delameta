//variable button
int button1 = 2;
int button2 = 3;
int button3 = 4;

//variable LED
int R = 5;
int Y = 6;
int G = 7;

//addon variable
int key1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //setup pin mode
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  
}

void loop() {
  
  //read button condition
  int readButton1 = digitalRead(button1);
  int readButton2 = digitalRead(button2);
  int readButton3 = digitalRead(button3);

  //print Serial
  Serial.print("Kondisi button 1 : "); Serial.print(readButton1);
  Serial.print(" | Kondisi button 2 : "); Serial.print(readButton2);
  Serial.print(" | Kondisi button 3 : "); Serial.print(readButton3);
  Serial.println();

  //logic

  //start of button 1
  if(readButton1 == 1 && key1 == 0){
    delay(2000);
    digitalWrite(R,HIGH);
    key1 = 1;
  }else if(readButton1 == 1 && key1 == 1){
    delay(2000);
    digitalWrite(R,LOW);
  }
  //end of button 1

  //start of button 2
   if(readButton2 == 1){
    digitalWrite(Y,HIGH);
   }else{
    digitalWrite(Y,LOW);
   }
   //end of button 2

   //start of button 3
    if(readButton3 == 1){
      digitalWrite(G,HIGH);
    }else{
      digitalWrite(G,LOW);
    }
   //end of button 3

}
