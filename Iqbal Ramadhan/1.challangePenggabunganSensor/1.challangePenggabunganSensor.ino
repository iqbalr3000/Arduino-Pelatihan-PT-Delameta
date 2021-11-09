//variable sensor
int pinSensorFlame = A0;
int pinSensorLDR = A1;
int pinSensorPIR = A2;

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

 

}

void loop() {

  //read sensor LDR condition / data
  int readSensorFlame = analogRead(pinSensorFlame);
  readSensorFlame = map(readSensorFlame,1006,4,0,100);

  int readSensorLDR = analogRead(pinSensorLDR);

  int readSensorPIR = analogRead(pinSensorPIR);
    
  //print serial
  Serial.print("Nilai Sensor Flame : ");
  Serial.print(readSensorFlame);
  
  Serial.print(" | Nilai Sensor LDR : ");
  Serial.print(readSensorLDR);
  
  Serial.print(" | Nilai Sensor PIR : ");
  Serial.print(readSensorPIR);
  Serial.println();

  

  //logic
 
  if(readSensorFlame > 5){
    digitalWrite(pinBuzzer,HIGH);
  }else if(readSensorLDR >= 236){
    analogWrite(R,readSensorLDR);
    delay(1000);
  }else{
    digitalWrite(pinBuzzer,LOW);
  }
   
  
}
