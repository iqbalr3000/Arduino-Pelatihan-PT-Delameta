//include library
#include<OneWire.h>
#include<DallasTemperature.h>

//variable sensor
int pinSensorSuhu = 2;
OneWire oneWire(pinSensorSuhu);
DallasTemperature sensors(&oneWire);

//variable output
int pinBuzzer = 3;
int R = 4;
int Y = 5;
int G = 6;

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
    //read sensor condition / data
    sensors.requestTemperatures();
    float readSuhu = sensors.getTempCByIndex(0); //read index0's data on onewire

    //print serial
    Serial.print("Data suhu : ");
    Serial.print(readSuhu);
    Serial.print(" C");
    Serial.println();

    digitalWrite(G,HIGH);

    //logic
    if(readSuhu > 31){
      digitalWrite(G,LOW);
      delay(500);
      digitalWrite(R,HIGH);
      
      digitalWrite(pinBuzzer,HIGH);
      delay(500);
      digitalWrite(pinBuzzer,LOW);
    }else{
      digitalWrite(R,LOW);
      delay(500);
      digitalWrite(G,HIGH);
      
      digitalWrite(pinBuzzer,LOW);
    }

    //the logic if you wanna know is that sensor connect or not
//    if(bacaSuhu != DEVICE_DISCONNECTED_C){
//      Serial.print("Data suhu yang terbaca pada bus 1 (index 0) : ");
//      Serial.println(bacaSuhu);
//    }else{
//      Serial.println("Error: Sensor pada index 0 tidak ditemukan");
//    }

  
}
