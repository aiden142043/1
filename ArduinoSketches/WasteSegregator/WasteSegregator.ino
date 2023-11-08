#include <Servo.h>

// Define the pins for the sensors and servo motors
#define CAPACITIVE_SENSOR_PIN A0
#define INDUCTIVE_SENSOR_PIN A1
#define LID_SERVO_PIN 9
#define WASTE_BIN_SERVO_PIN 7

// Define the threshold values for sensors
#define CAPACITIVE_THRESHOLD 1000
#define INDUCTIVE_THRESHOLD 500

// Define the positions for the servo motors
#define LID_OPEN_POSITION 0
#define LID_CLOSED_POSITION 90
#define BIN_DRY_POSITION 0
#define BIN_WET_POSITION 90
#define BIN_METAL_POSITION 180

// Define the delay times for the lid when it senses dry or metallic waste
#define DRY_WASTE_DELAY 1000
#define METALLIC_WASTE_DELAY 2000

// Create Servo objects for the lid and waste bin
Servo lidServo;
Servo wasteBinServo;

void setup() {
  // Initialize the Servo motors
  lidServo.attach(LID_SERVO_PIN);
  wasteBinServo.attach(WASTE_BIN_SERVO_PIN);

  // Set the pinMode for the sensors to INPUT
  pinMode(CAPACITIVE_SENSOR_PIN, INPUT);
  pinMode(INDUCTIVE_SENSOR_PIN, INPUT);

  // Initialize the Serial communication with a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the values from the sensors
  int capacitiveValue = analogRead(CAPACITIVE_SENSOR_PIN);
  int inductiveValue = analogRead(INDUCTIVE_SENSOR_PIN);

  // Control the lid servo based on the inductive sensor
  if (inductiveValue > INDUCTIVE_THRESHOLD) {
    // If the inductive sensor detects metallic waste, open the lid
    lidServo.write(LID_OPEN_POSITION);
    delay(METALLIC_WASTE_DELAY);
  } else {
    // If not, close the lid
    lidServo.write(LID_CLOSED_POSITION);
  }

  // Control the lid servo based on the capacitive sensor
  if (capacitiveValue > CAPACITIVE_THRESHOLD) {
    // If the capacitive sensor detects non-metallic waste (dry), open the lid
    lidServo.write(LID_OPEN_POSITION);
    delay(DRY_WASTE_DELAY);
  } else {
    // If not, close the lid
    lidServo.write(LID_CLOSED_POSITION);
  }

  // Control the waste bin servo based on the inductive sensor
  if (inductiveValue > INDUCTIVE_THRESHOLD) {
    // If the inductive sensor detects metallic waste, rotate the waste bin to the metal position
    wasteBinServo.write(BIN_METAL_POSITION);
  } else {
    // If it's not metallic waste, rotate the waste bin based on your wet/dry classification
    // Adjust the positions as needed
    if (capacitiveValue > CAPACITIVE_THRESHOLD) {
      // If it's dry waste, rotate the bin to the dry position
      wasteBinServo.write(BIN_DRY_POSITION);
    } else {
      // If it's not metallic or dry waste, assume it's wet waste and rotate to the wet position
      wasteBinServo.write(BIN_WET_POSITION);
    }
  }

  // Wait for a while before the next reading
  delay(100);
}