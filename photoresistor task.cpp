void setup () {

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
}
void loop() {
  //read the LDR value
  int A0 = analogRead(A0); 
   // Check if light level is above the threshold
  if (A0 >= 500) {

    tone(7,100);
    digitalWrite(2, HIGH);
    delay(100);
    noTone(7);
    digitalWrite(2, LOW);
    delay(100);
    Serial.println("Detected Mine"); 
  }
  else {
    noTone(7);
    digitalWrite(2, LOW);
    Serial.println("No Detected Mines");
  }
}