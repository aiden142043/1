#include <Servo.h>

// Define the pins for the sensors and servo motor
#define CAPACITIVE_SENSOR_PIN A0
#define INDUCTIVE_SENSOR_PIN A1
#define SERVO_PIN 9
#define DROPPERSERVO2_PIN 7

// Define the thresholds for the sensors
#define CAPACITIVE_THRESHOLD 500
#define INDUCTIVE_THRESHOLD 100

// Define the positions for the servo motor
#define POSITION_A 0
#define POSITION_B 90
#define POSITION_C 180

// Define the delay for dropperservo2
#define DROPPERSERVO2_DELAY 1000

// Create a Servo object
Servo servo;
Servo dropperservo2;

void setup() {
  // Initialize the Servo motor
  servo.attach(SERVO_PIN);
  dropperservo2.attach(DROPPERSERVO2_PIN);
}

void loop() {
  // Read the values from the sensors
  int capacitiveValue = analogRead(CAPACITIVE_SENSOR_PIN);
  int inductiveValue = analogRead(INDUCTIVE_SENSOR_PIN);

  // Control the servo motor based on the sensor values
  if (capacitiveValue > CAPACITIVE_THRESHOLD) {
    // If the capacitive sensor reads a high value, move the servo to position A
    servo.write(POSITION_A);
    delay(1000);
    dropperservo2.write(POSITION_A);
    delay(DROPPERSERVO2_DELAY);
  } else if (inductiveValue > INDUCTIVE_THRESHOLD) {
    // If the inductive sensor reads a high value, move the servo to position B
    servo.write(POSITION_B);
    delay(1000);
    dropperservo2.write(POSITION_B);
    delay(DROPPERSERVO2_DELAY);
  } else {
    // If neither sensor reads a high value, move the servo to position C
    servo.write(POSITION_C);
    delay(1000);
    dropperservo2.write(POSITION_C);
    delay(DROPPERSERVO2_DELAY);
  }

  // Wait for a while before the next reading
  delay(100);
}