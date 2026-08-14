// Necessary libraries: Servo
#include <Servo.h>

const int motorrp = 11;
const int motorrn = 10;
const int motorlp = 13;
const int motorln = 12;
const int led = 7;
const int trigPin2 = 8;
const int echoPin2 = 3;
const int trigPin = 5;
const int echoPin = 6;
const int irr = 2;
const int irl = 4;
int servoOn = TRUE;
long duration;
int distance;
int distance2;
int obstacleRight;
int obstacleLeft;

Servo sweepServo;

void setup() {
    pinMode(motorrp, OUTPUT);
    pinMode(motorrn, OUTPUT);
    pinMode(motorlp, OUTPUT);
    pinMode(motorln, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(irr, INPUT);
    pinMode(irl, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    sweepServo.attach(9);
    sweepServo.write(90);
}

void goForward() {
    digitalWrite(motorrp, HIGH);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorlp, HIGH);
    digitalWrite(motorln, LOW);
}

void goBackward() {
    digitalWrite(motorrp, LOW);
    digitalWrite(motorrn, HIGH);
    digitalWrite(motorlp, LOW);
    digitalWrite(motorln, HIGH);
}

void turnRight() {
    digitalWrite(motorrp, LOW);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorlp, HIGH);
    digitalWrite(motorln, LOW);
}

void turnRightBackwards() {
    digitalWrite(motorrp, LOW);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorlp, LOW);
    digitalWrite(motorln, HIGH);
}

void turnLeft() {
    digitalWrite(motorrp, HIGH);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorlp, LOW);
    digitalWrite(motorln, LOW);
}

void turnLeftBackwards() {
    digitalWrite(motorrp, LOW);
    digitalWrite(motorrn, HIGH);
    digitalWrite(motorlp, LOW);
    digitalWrite(motorln, LOW);
}

void stop() {
    digitalWrite(motorrp, LOW);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorlp, LOW);
    digitalWrite(motorln, LOW);
}

void servoMotion() {
    sweepServo.write(random(0, 180));
    delay(random(50, 500));
}

void loop() {
    goForward();
    delay(2000);
    turnRight();
    delay(1000);
    goForward();
    delay(2000);
    stop();
    delay(20000);
}