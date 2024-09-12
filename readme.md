# Untitled

# Arduino Motor Speed Control

## Overview

This project demonstrates how to control the speed of a DC motor using an Arduino board. The system utilizes a PID controller for precise speed control and an Exponential Smoothing Filter to stabilize the output.

## Components Required

- **Arduino Board** (e.g., Arduino Uno)
- **DC Motor**
- **Motor Driver Module** (e.g., L298N or L293D)
- **Speed Sensor** (e.g., Hall Effect sensor with analog output)
- **Breadboard and Jumper Wires**
- **External Power Supply** (for the motor driver, if required)

## Circuit Diagram

1. **Motor Connections**
    - **Motor Driver Input Pin** → Arduino Pin 9
    - **Motor Driver Ground** → Arduino Ground
    - **Motor Driver Power** → External Power Supply
2. **Speed Sensor Connections**
    - **Speed Sensor Analog Output** → Arduino Analog Pin A0
    - **Speed Sensor Ground** → Arduino Ground
    - **Speed Sensor Power** → Arduino 5V

## Code Description

### `PID_Controller` Class

The `PID_Controller` class handles the PID control algorithm for motor speed adjustment.

- **Constructor**
    
    ```cpp
    PID_Controller(float p, float i, float d);
    ```
    
    Initializes PID coefficients `p`, `i`, and `d`.
    
- **Methods**
    - **`setSetPoint(float sp)`**
        
        Sets the desired speed setpoint.
        
        ```cpp
        void setSetPoint(float sp);
        ```
        
    - **`compute(float currentSpeed)`**
        
        Computes PID output based on current speed and returns a constrained PWM value.
        
        ```cpp
        float compute(float currentSpeed);
        ```
        

### Arduino Sketch

### `setup()`

Initializes pins, sets up serial communication, and sets the desired motor speed.

```cpp
void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(speedSensorPin, INPUT);

    Serial.begin(9600);

    motorPID.setSetPoint(Set_Point); // Set desired speed
}
```

### `loop()`

Reads the current speed, computes PID output, applies smoothing, and updates the motor speed.

```cpp
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

```

## How to Use

1. **Upload the Code**
    
    Copy the provided code into the Arduino IDE, select the correct board and port, and click "Upload."
    
2. **Connect the Hardware**
    
    Follow the circuit diagram to connect the motor, speed sensor, and motor driver to the Arduino.
    
3. **Monitor and Adjust**
    
    Open the Serial Monitor (baud rate: 9600) to observe speed and control output. Adjust PID coefficients if needed.
    

## Tuning PID Parameters

- **Proportional Gain (`kp`)**: Adjusts response to current error.
    
    ```cpp
    motorPID = PID_Controller(0.8, 20, 0.001); // Example values
    ```
    
- **Integral Gain (`ki`)**: Adjusts response based on accumulated error.
    
    ```cpp
    motorPID.setSetPoint(Set_Point); // Adjust as needed
    ```
    
- **Derivative Gain (`kd`)**: Adjusts response to the rate of change of error.
    
    ```cpp
    motorPID.compute(currentSpeed); // Example call
    ```
    

Adjust parameters to optimize motor speed control.

## Troubleshooting

- **Motor Not Running**
    - Check connections and power supply.
    - Ensure the motor driver ground is connected to Arduino ground.
- **No Speed Reading**
    - Verify sensor connections and functionality.
    - Ensure correct sensor output mapping.
- **PID Control Issues**
    - Fine-tune PID coefficients for better performance.
    - Use Serial Monitor to diagnose behavior.