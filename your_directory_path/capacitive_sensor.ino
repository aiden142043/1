#include <CapacitiveSensor.h>

#define SEND_PIN 2
#define RECEIVE_PIN 4

CapacitiveSensor capSensor = CapacitiveSensor(SEND_PIN, RECEIVE_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  delay(1000);
}