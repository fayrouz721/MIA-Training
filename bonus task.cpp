#include <Servo.h> 

Servo myServo; 

// Range in centimeters
const float detectionRange = 400;

// Defines variables
int state = 0; 
long duration;
int distance1, distance2, distance3, distance4;
float x = 0.0; // X position in the grid
float y = 0.0; // Y position in the grid
float angle = 0.0; // Orientation angle in degrees
const long interval = 500;
unsigned long prevTime = 0;
float speed = 100.0; // Speed in cm/s

// Define boundaries
const float MAX_X = 50.0; // Maximum X boundary in cm
const float MAX_Y = 60.0; // Maximum Y boundary in cm

// Function to get distance from a sensor
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  return duration * 0.0344 / 2;
}

// Update position based on movement
void updatePosition(float Time) {
  float distanceTraveled = speed * Time; // Calculate distance traveled
  float radians = angle * (PI / 180.0);
  x += distanceTraveled * cos(radians);
  y += distanceTraveled * sin(radians);

  // Boundary check
  if (x < 0 || x > MAX_X || y < 0 || y > MAX_Y) {
    stopMotors();
    delay(500);
    yawRight(); // Change direction
    delay(1000);
   x = constrain(x, 0, MAX_X); // Keep x within bounds
    y = constrain(y, 0, MAX_Y); // Keep y within bounds
  }
}
// Update orientation based on rotation
void updateOrientation(float Angle) {
  angle += Angle;
  if (angle >= 360.0) angle -= 360.0;
  if (angle < 0.0) angle += 360.0;
}
// Function to move forward
void moveForward() {
  digitalWrite(13, HIGH);  // Left motor pin 1
  digitalWrite(12, LOW);   // Left motor pin 2
  digitalWrite(11, HIGH);  // Right motor pin 1
  digitalWrite(10, LOW);   // Right motor pin 2
}
// Function to move backward
void moveBackward() {
  digitalWrite(13, LOW);  
  digitalWrite(12, HIGH);  
  digitalWrite(11, LOW);   
  digitalWrite(10, HIGH);
}
// Function to stop the motors
void stopMotors() {
  digitalWrite(13, LOW);  
  digitalWrite(12, LOW);  
  digitalWrite(11, LOW);  
  digitalWrite(10, LOW);
}
// Function to rotate 90 degrees to the right
void yawRight() {
  digitalWrite(13, HIGH);  
  digitalWrite(12, LOW);   
  digitalWrite(11, LOW);   
  digitalWrite(10, HIGH);  
  updateOrientation(-90);
}
// Function to rotate 90 degrees to the left
void yawLeft() {
  digitalWrite(13, LOW);   
  digitalWrite(12, HIGH);  
  digitalWrite(11, HIGH);  
  digitalWrite(10, LOW);   
  updateOrientation(90);
}
void setup() {
 pinMode(A3, OUTPUT); pinMode(4, INPUT);  // Front sensor
 pinMode(A1, OUTPUT); pinMode(A2, INPUT);  // Left sensor
 pinMode(A5, OUTPUT); pinMode(A4, INPUT);  // Right sensor
 pinMode(6, OUTPUT); pinMode(5, INPUT);  // Back sensor
  pinMode(13, OUTPUT);  // Right motor IN1
 pinMode(12, OUTPUT);  // Right motor IN2
 pinMode(11, OUTPUT);  // Left motor IN3
  pinMode(10, OUTPUT);  // Left motor IN4
  pinMode(2, OUTPUT);   // LED
  pinMode(7, OUTPUT);   // BUZZER
  pinMode(A0, INPUT);   // Photoresistor
Serial.begin(9600);
  myServo.attach(9); // Attach the servo to pin 9
  myServo.write(0); // Set the initial position to 0 degrees
}
void loop() {
  unsigned long currentMillis = millis();
  float Time = (currentMillis - prevTime) / 1000.0; // Calculate elapsed time in seconds
  if (currentMillis - prevTime >= interval) {
    prevTime = currentMillis;
    distance1 = getDistance(A3, 4); // Front sensor
    distance2 = getDistance(A1, A2); // Left sensor
    distance3 = getDistance(A5, A4); // Right sensor
    distance4 = getDistance(6, 5); // Back sensor
   Serial.print("Front: ");
   Serial.print(distance1);
   Serial.print(" cm\t");
   Serial.print("Left: ");
  Serial.print(distance2);
   Serial.print(" cm\t");
   Serial.print("Right: ");
   Serial.print(distance3);
   Serial.print(" cm\t");
   Serial.print("Back: ");
   Serial.print(distance4);
   Serial.println(" cm");
    if (distance1 < 15) {
        Serial.println("Obstacle detected");
      stopMotors();
      delay(500);
      yawRight(); 
      delay(1000);
    } else if (distance2 < 15) {
        Serial.println("Obstacle detected");
      stopMotors();
      delay(500);
      yawRight(); 
      delay(1000);
    } else if (distance3 < 15) {
       Serial.println("Obstacle detected");
      stopMotors();
      delay(500);
      yawLeft(); 
      delay(1000);
    } else if (distance4 < 15) {
      Serial.println("Obstacle detected");
      stopMotors();
      delay(500);
      moveForward(); 
      delay(1000);
    } else {
      Serial.println("Moving Forward");
      moveForward();
    }}
  updatePosition(Time); 
  int ldrValue = analogRead(A0); 
  if (ldrValue >= 500) {
    tone(7, 100);
    digitalWrite(2, HIGH);
    delay(100);
    noTone(7);
    digitalWrite(2, LOW);
    delay(100);
    Serial.println("Detected Mine"); 
  } else {
    noTone(7);
    digitalWrite(2, LOW);
    Serial.println("No Detected Mines");
  }
  myServo.attach(3); 
  myServo.write(60); 
  delay(2000); 
  myServo.write(0); 
  delay(2000);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.print(", Angle: ");
  Serial.println(angle);
}
