#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo.write(0);   // sets the servo position to 0 degrees
}

void loop() {
  // nothing happens after setup
}