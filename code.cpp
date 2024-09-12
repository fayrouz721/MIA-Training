#include <Arduino.h>

// Define motor pins
const int motorPin = 9;
const int speedSensorPin = A0; // Define the pin for speed sensor feedback

// Desired speed setpoint
const float Set_Point = 100; // Desired speed (0-255)

// PID Controller Class
class PID_Controller {
public:
    PID_Controller(float p, float i, float d); // Constructor declaration

    void setSetPoint(float sp);
    float compute(float currentSpeed);

private:
    float kp, ki, kd;     // PID coefficients
    float setPoint;       // Desired speed
    float prevError;      // Previous error for derivative calculation
    float integral;       // Accumulated error for integral calculation
    float output;         // PID output
    float lastTime;       // Last time the PID was computed (in float)
};

// Constructor implementation
PID_Controller::PID_Controller(float p, float i, float d)
    : kp(p), ki(i), kd(d), setPoint(0), prevError(0), integral(0), output(0), lastTime(0.0) {}

// Method to set the set point
void PID_Controller::setSetPoint(float sp) {
    setPoint = sp;
}

// Method to compute the PID output
float PID_Controller::compute(float currentSpeed) {
    float now = millis(); // Get the current time in milliseconds as float
    float timeChange = (now - lastTime) / 1000.0; // Convert milliseconds to seconds
    float error = setPoint - currentSpeed;

    if (timeChange > 0) { // Avoid division by zero
        integral += error * timeChange;
        float derivative = (error - prevError) / timeChange;
        output = kp * error + ki * integral + kd * derivative;
        prevError = error;
        lastTime = now;
    }

    return constrain(output, 0, 255); // Constrain output to PWM range
}

// Exponential Smoothing Filter Class
class exp_filter {
public:
    exp_filter(double alpha) : Alpha(alpha), Smoothed_Value(0) {}

    double applyFilter(double input) {
        Smoothed_Value = Alpha * input + (1 - Alpha) * Smoothed_Value;
        return Smoothed_Value;
    }

private:
    double Alpha;         // Smoothing factor
    double Smoothed_Value; // Filtered value
};

// Initialize PID Controller and Exponential Smoothing Filter
PID_Controller motorPID(0.8, 20, 0.001);
exp_filter softStart(0.2);

void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(speedSensorPin, INPUT);

    Serial.begin(9600);

    motorPID.setSetPoint(Set_Point); // Set desired speed
}

void loop() {
    float currentSpeed = analogRead(speedSensorPin);  
    currentSpeed = map(currentSpeed, 0, 1023, 0, 255);  

    // Calculate PID output
    float pidOutput = motorPID.compute(currentSpeed);

    // Apply exponential smoothing
    float smoothedOutput = softStart.applyFilter(pidOutput);

    // Constrain smoothed output and write to motor
    int motorPWM = constrain(smoothedOutput, 0, 255);
    analogWrite(motorPin, motorPWM);

    // Print debug information to the serial monitor
    Serial.print("Speed: ");
    Serial.print(currentSpeed);
    Serial.print(" | Smoothed Output: ");
    Serial.println(smoothedOutput);

    delay(100);  // Adjust delay as needed for stability
}
