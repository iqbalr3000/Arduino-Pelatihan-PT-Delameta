//variable sensor
int pinSensorLDR = A0;

//variable buzzer
int pinBuzzer = 5;

//variabel lamp
int R = 3;

void setup() {

  //setup port COM
  Serial.begin(9600);

  //setup pin mode input or output
  pinMode(pinBuzzer,OUTPUT);
  pinMode(R,OUTPUT);

  //note : LDR sensor default input

}

void loop() {

  //read sensor LDR condition / data
  int readSensorLDR = analogRead(pinSensorLDR);
  readSensorLDR = map(readSensorLDR,0,1024,0,255);
  
  //print serial
  Serial.print("Nilai Sensor LDR : ");
  Serial.print(readSensorLDR);
  Serial.println();

  analogWrite(R,readSensorLDR);
  
}
