#include <AFMotor.h>               
#define trigPin 8
#define echoPin 7

AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motor1.setSpeed(105);
  motor2.setSpeed(105);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 25) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  }
  else {
    delay(15);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }
}
