//include library
#include<NewPing.h>

//variable sensor
int pinTrigger = 8; //trigger from sensor ultrasonic
int pinEcho = 9; //echo from sensor ultrasonic

//variable output
int pinBuzzer = 3;
int R = 4;
int Y = 5;
int G = 6;

//variable addons
int limit = 400; //max limit for sensor is 400cm or 4m

NewPing cm(pinTrigger,pinEcho,limit);

void setup() {
  //setup port COM
  Serial.begin(9600);

  //setup pin input output
  pinMode(pinBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

}

void loop() {
    //read sensor data
    int readSpace = cm.ping_cm();

    //print serial
    Serial.print("Data jarak : ");
    Serial.print(readSpace);
    Serial.print(" cm");
    Serial.println();
    delay(500);

    //logic
    if(readSpace <= 20 && readSpace != 0){
      Serial.println("Berhenti");
      
      digitalWrite(R,HIGH);
      digitalWrite(Y,LOW);
      digitalWrite(G,LOW);

      digitalWrite(pinBuzzer,HIGH);
      delay(100);
      digitalWrite(pinBuzzer,LOW);
      delay(100);
    }else if(readSpace >= 21 && readSpace <= 70){
      Serial.println("Bahaya");

      digitalWrite(R,LOW);
      digitalWrite(Y,HIGH);
      digitalWrite(G,LOW);

      digitalWrite(pinBuzzer,HIGH);
      delay(500);
      digitalWrite(pinBuzzer,LOW);
      delay(500);
    }else{
      Serial.println("Aman");

      digitalWrite(R,LOW);
      digitalWrite(Y,LOW);
      digitalWrite(G,HIGH);

      digitalWrite(pinBuzzer,LOW);
    }

}
