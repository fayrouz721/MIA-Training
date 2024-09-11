# task 10.5

# Arduino Gyroscope Yaw Measurement

This project demonstrates how to interface an Arduino with a gyroscope sensor (such as the MPU6050) using I2C communication to measure the yaw angle. The code reads the Z-axis gyroscope data, calibrates it, and integrates the angular velocity over time to calculate the yaw.

## Components Required

- Arduino (e.g., Uno, Nano)
- MPU6050 gyroscope sensor or compatible
- Jumper wires

## Circuit Connections

- VCC of the sensor to 5V on the Arduino
- GND of the sensor to GND on the Arduino
- SDA of the sensor to A4 on the Arduino (for Uno)
- SCL of the sensor to A5 on the Arduino (for Uno)

## Code Explanation

The code performs the following steps:

1. **Initialization**: Sets up I2C communication and powers up the gyroscope.
2. **Calibration**: Calibrates the gyroscope to find the Z-axis offset.
3. **Yaw Measurement**: Reads the gyroscope data, corrects it, and calculates the yaw angle.
4. **Output**: Continuously prints the yaw angle to the Serial Monitor.

### Key Functions

- `setup()`: Initializes the gyroscope and performs calibration.
- `loop()`: Continuously reads gyroscope data, corrects it, calculates yaw, and prints it.
- `readZGyro()`: Reads the raw gyroscope data from the Z-axis.
- `calibrateGyro()`: Calibrates the gyroscope to find the offset.

## How to Use

1. Connect the sensor to the Arduino as per the connections above.
2. Upload the code to your Arduino board.
3. Open the Serial Monitor at 9600 baud rate to see the yaw angle updates.

## Important Notes

- Ensure the sensor is properly connected and powered.
- The calibration process may take a few seconds; keep the sensor stationary during calibration.
- Adjust the `GYRO_CONVERSION_FACTOR` if using a different gyroscope model.

## License

This project is open-source and available for modification and use under the MIT License.