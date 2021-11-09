int button1 = 2;
int button2 = 3;
int button3 = 4;

int R = 5;
int Y = 6;
int G = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int readButton1 = digitalRead(button1);
  int readButton2 = digitalRead(button2);
  int readButton3 = digitalRead(button3);

  Serial.print("Kondisi button : ");
  Serial.print(readButton1);
  Serial.print(readButton2);
  Serial.print(readButton3);
  Serial.println();

  if(readButton1 == 1){
    digitalWrite(R,HIGH);
  }else if(readButton2 == 1){
    digitalWrite(Y,HIGH);
  }else if(readButton3 == 1){
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
  }

}
