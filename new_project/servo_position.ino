#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
}

void loop() {
  myservo.write(90);  // tell servo to go to position 90
  delay(15);          // waits 15ms for the servo to reach the position
}