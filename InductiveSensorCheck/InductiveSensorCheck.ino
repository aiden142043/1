// Define the sensor pin
const int sensorPin = 2;

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  
  // Set the sensor pin as INPUT
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Read the sensor value
  int sensorValue = digitalRead(sensorPin);
  
  // Since the sensor is NPN/NC, it will give HIGH when no metal is detected and LOW when metal is detected
  if (sensorValue == HIGH) {
    Serial.println("No metal detected");
  } else {
    Serial.println("Metal detected");
  }
  
  // Wait for a while before the next reading
  delay(500);
}