// Necessary libraries: Servo
#include <Servo.h>

const int motorrp = 11;
const int motorrn = 10;
const int motorlp = 13;
const int motorln = 12;
const int ledr = 7;
const int ledl = 8;
const int trigPin = 5;
const int echoPin = 6;
const int irr = 2;
const int irl = 4;
long duration;
int distance;
int obstacleRight;
int obstacleLeft;

Servo sweepServo;

void setup() {
    pinMode(motorrp, OUTPUT);
    pinMode(motorrn, OUTPUT);
    pinMode(motorlp, OUTPUT);
    pinMode(motorln, OUTPUT);
    pinMode(ledr, OUTPUT);
    pinMode(ledl, OUTPUT);
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

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    if (distance <= 30) {
        stop();
        obstacleRight = (digitalRead(irr));
        if (obstacleRight == HIGH) {
            obstacleLeft = (digitalRead(irl));
            if (obstacleLeft == HIGH) {
                while (obstacleLeft == HIGH) {
                    goBackward();
                }
                goBackward();
                delay(200);
                turnRightBackwards();
                delay(700);
                goForward();
                
            }
            turnLeftBackwards();
        }
        else {
            turnRightBackwards();
        }
    }
    else {
        goForward()
    }
    delay(200);
}