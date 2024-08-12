//i2c sends to UART slave
#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  
}

void loop() {
  Wire.beginTransmission(8);
  Wire.write("MIA");
  Wire.endTransmission();
  delay(1000);
}

 //UART Receives from i2c slave
#include <SoftwareSerial.h>
const int rxPin = 7;
const int txPin = 6;
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); // Initialize SoftwareSerial
}

void loop() {
  if (mySerial.available()) { // Check if data is available on SoftwareSerial
    Serial.println(mySerial.readStringUntil('\n')); // Read and print the data received
    delay(1000);
  }
}

//master
#include <SoftwareSerial.h>
#include <Wire.h>
const int rxPin = 7;
const int txPin = 6;
SoftwareSerial mySerial(rxPin, txPin);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); 
  Wire.begin();
  Wire.onReceive(receiveFunc);
  Wire.onRequest(requestFunc);
}

void loop() {
   mySerial.println("MIA");
  delay(100);
}
  
 void receiveFunc(int bytename){
  while(Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println("");
}
void requestFunc(){
  Wire.write("MIA");
}