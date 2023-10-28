#include <Servo.h>

// Define the pins for the sensors and servo motor
#define CAPACITIVE_SENSOR_PIN A0
#define INDUCTIVE_SENSOR_PIN A1
#define SERVO_PIN 9

// Define the thresholds for the sensors
#define CAPACITIVE_THRESHOLD 500
#define INDUCTIVE_THRESHOLD 500

// Define the positions for the servo motor
#define POSITION_A 0
#define POSITION_B 90
#define POSITION_C 180

// Create a Servo object
Servo servo;

void setup() {
  // Initialize the Servo motor
  servo.attach(SERVO_PIN);
}

void loop() {
  // Read the values from the sensors
  int capacitiveValue = analogRead(CAPACITIVE_SENSOR_PIN);
  int inductiveValue = analogRead(INDUCTIVE_SENSOR_PIN);

  // Control the servo motor based on the sensor values
  if (capacitiveValue > CAPACITIVE_THRESHOLD) {
    // If the capacitive sensor reads a high value, move the servo to position A
    servo.write(POSITION_A);
  } else if (inductiveValue > INDUCTIVE_THRESHOLD) {
    // If the inductive sensor reads a high value, move the servo to position B
    servo.write(POSITION_B);
  } else {
    // If neither sensor reads a high value, move the servo to position C
    servo.write(POSITION_C);
  }

  // Wait for a while before the next reading
  delay(1000);
}