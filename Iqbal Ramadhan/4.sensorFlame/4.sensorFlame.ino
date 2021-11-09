//variable sensor
int pinSensorFlame = A0;
int pinSensorLDR = A1;

//variable buzzer
int pinBuzzer = 5;

//variabel addons
int R = 3; //red lamp
int Y = 4;
int G = 6;

void setup() {

  //setup port COM
  Serial.begin(9600);

  //setup pin mode input or output
  pinMode(pinBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);

  //note : sensor analog default as an input

  Serial.println("aman");
  digitalWrite(G,HIGH);

}

void loop() {

  //read sensor LDR condition / data
  int readSensorFlame = analogRead(pinSensorFlame);
  readSensorFlame = map(readSensorFlame,1006,4,0,100);
    
  //print serial
  Serial.print("Nilai Sensor Flame : ");
  Serial.print(readSensorFlame);
  Serial.println();

  //logic
 
  if(readSensorFlame > 0 and readSensorFlame < 50 ){
    digitalWrite(G,LOW);
    digitalWrite(R,LOW);
    delay(100);
    
    digitalWrite(pinBuzzer,HIGH);
    delay(500);
    digitalWrite(pinBuzzer,LOW);
    delay(500);
    digitalWrite(pinBuzzer,LOW);
    
    Serial.println("warning");
    
    digitalWrite(Y,HIGH);
  }else if(readSensorFlame > 50){
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    delay(100);

    digitalWrite(pinBuzzer,HIGH);
    Serial.println("Bahaya harap mengungsi");

    digitalWrite(R,HIGH);
  }else{
    digitalWrite(Y,LOW);
    digitalWrite(R,LOW);
    
    digitalWrite(pinBuzzer,LOW);
    digitalWrite(G,HIGH);
    Serial.println("aman");
  }
  
}
