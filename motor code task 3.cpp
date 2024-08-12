void setup() {

  pinMode(13, OUTPUT);  // Right motor IN1
  pinMode(12, OUTPUT);  // Right motor IN2
  pinMode(11, OUTPUT);  // Left motor IN3
  pinMode(10, OUTPUT);  // Left motor IN4
  
  Serial.begin(9600);
}

void loop() {
  // Yaw Right (Rotate 90 degrees to the right)
  Serial.println("Yaw Right");
  digitalWrite(13, HIGH); 
  digitalWrite(12, LOW);   
  digitalWrite(11, LOW);   
  digitalWrite(10, HIGH); 
  delay(1000);

  // Yaw Left (Rotate 90 degrees to the left)
  Serial.println("Yaw Left");
  digitalWrite(13, LOW);   
  digitalWrite(12, HIGH); 
  digitalWrite(11, HIGH);  
  digitalWrite(10, LOW);   
  delay(1000);

  // Move Forward
  Serial.println("Forward");
  digitalWrite(13, HIGH);  
  digitalWrite(12, LOW);   
  digitalWrite(11, HIGH);  
  digitalWrite(10, LOW);   
  delay(1000);

  // Move Backward
  Serial.println("Backward");
  digitalWrite(13, LOW);  
  digitalWrite(12, HIGH);  
  digitalWrite(11, LOW);   
  digitalWrite(10, HIGH);  
  delay(1000);
}
