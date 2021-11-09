//variable sensor
int pinSensorPIR = 2;

//variabel buzzer
int pinBuzzer = 5;

//variable addons
int i = 0;

void setup() {

  //setup port COM
  Serial.begin(9600);

  //setup pin for output or input
  pinMode(pinSensorPIR,INPUT);
  pinMode(pinBuzzer,OUTPUT);

}

void loop() {

  //read sensor condition or data
  int readSensorPIR = digitalRead(pinSensorPIR);

  //print serial
//  Serial.print("nilai PIR : ");
//  Serial.print(readSensorPIR);
//  Serial.println();

  //logic

  //use tone to customize the output sound of buzzer
//  for(i=700;i<800;i++){
//    tone(pinBuzzer,i);
//    delay(15);
//  }
//  for(i=800;i>700;i--){
//    tone(pinBuzzer,i);
//    delay(15);
//  }
  

  //start of sensor PIR
  if(readSensorPIR == 1){
    digitalWrite(pinBuzzer,HIGH);
    Serial.println("Hati hati!!!");
  }else{
    digitalWrite(pinBuzzer,LOW);
    Serial.println("Kondisi aman");
  }
  //end of sensor PIR

}
