#include <Wire.h>

// Gyroscope sensor settings
const int GYRO_ADDRESS = 0x68;           // I2C address for the gyroscope
const int POWER_MGMT_REG = 0x6B;         // Register to wake up the gyroscope
const int GYRO_ZOUT_H = 0x47;            // Register to read high byte of Z-axis gyroscope data
const float GYRO_SCALE = 131.0;          // Scale factor to convert raw data to degrees per second

// Variables for yaw angle calculation
float yawAngle = 0.0;                    // Yaw angle in degrees
float zGyroBias = 0.0;                   // Offset value for Z-axis gyroscope
unsigned long previousTime = 0;          // Previous time for integration

void setup() {
    Serial.begin(9600);                  // Initialize serial communication
    Wire.begin();                        // Initialize I2C communication

    initializeGyro();                    // Initialize the gyroscope sensor
    calibrateGyro();                     // Calibrate the gyroscope to find offset

    previousTime = millis();             // Set the initial time
}

void loop() {
    float zGyroRate = getZGyroRate();    // Read and correct Z-axis gyroscope rate
    updateYaw(zGyroRate);                // Update the yaw angle using the rate

    // Display the current yaw angle
    Serial.print("Yaw Angle: ");
    Serial.println(yawAngle);

    delay(1000);                         // Delay for 1 second between readings
}

// Function to initialize the gyroscope sensor
void initializeGyro() {
    Wire.beginTransmission(GYRO_ADDRESS);
    Wire.write(POWER_MGMT_REG);
    Wire.write(0);                       // Set the power management register to wake up the sensor
    if (Wire.endTransmission() != 0) {
        Serial.println("Error initializing gyroscope.");
    }
}

// Function to read and return the corrected Z-axis gyroscope rate
float getZGyroRate() {
    int16_t zGyroRaw = readGyroZ();      // Read raw Z-axis gyroscope data
    float zGyroRate = (zGyroRaw / GYRO_SCALE) - zGyroBias;  // Correct with scale and offset
    return zGyroRate;
}

// Function to read raw Z-axis gyroscope data
int16_t readGyroZ() {
    Wire.beginTransmission(GYRO_ADDRESS);
    Wire.write(GYRO_ZOUT_H);
    if (Wire.endTransmission(false) != 0) {
        Serial.println("Failed to request Z-axis data.");
        return 0;  // Return 0 on error to avoid incorrect readings
    }

    Wire.requestFrom(GYRO_ADDRESS, 2);   // Request 2 bytes of Z-axis data
    if (Wire.available() < 2) {
        Serial.println("Incomplete data received.");
        return 0;  // Return 0 if data is incomplete
    }

    int16_t zGyro = (Wire.read() << 8) | Wire.read(); // Combine high and low bytes
    return zGyro;
}

// Function to calibrate the gyroscope and find the Z-axis offset
void calibrateGyro() {
    const int calibrationSamples = 500;  // Number of samples for calibration
    long zGyroSum = 0;

    Serial.println("Calibrating gyroscope...");

    // Read multiple samples to determine the average offset
    for (int i = 0; i < calibrationSamples; i++) {
        zGyroSum += readGyroZ();         // Accumulate Z-axis readings
        delay(2);                        // Short delay between readings
    }

    // Calculate average bias from accumulated readings
    zGyroBias = (zGyroSum / (float)calibrationSamples) / GYRO_SCALE;

    Serial.print("Calibration complete. Z Gyro Bias: ");
    Serial.println(zGyroBias);
}

// Function to update the yaw angle based on the gyroscope rate
void updateYaw(float zGyroRate) {
    unsigned long currentTime = millis();
    float timeDelta = (currentTime - previousTime) / 1000.0;  // Time difference in seconds
    previousTime = currentTime;

    yawAngle += zGyroRate * timeDelta;   // Integrate the rate over time to update the yaw angle
}
