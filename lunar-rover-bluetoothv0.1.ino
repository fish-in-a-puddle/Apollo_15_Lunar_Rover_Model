// Necessary libraries: Servo
#include <Servo.h>
#include <Serial.h>

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
const int lightDetect = A0;
int lightLevel;
long duration;
int distance;
int distance2;
int obstacleRight;
int obstacleLeft;
int autoDrive = 0; 
int autoLights;
int btIn

Servo sweepServo;

void setup() {
    Serial.begin(9600);
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
    if (Serial.available() > 0) {
        btIn = Serial.read();
        switch (btIn) {
            case 100:
            goForward();
            break;
            case 110:
            turnRight();
            break;
            case 120:
            turnLeft();
            break;
            case 200:
            goBackward();
            break;
            case 210;
            turnRightBackwards();
            break;
            case 220:
            turnLeftBackwards();
            break;
            case 999:
            stop();
            break;
            case 300:
            autoDrive = 1;
            break;
            case 310:
            autoDrive = 0;
            break;
            case 400:
            autoLights = 0;
            digitalWrite(led, HIGH);
            break;
            case 410:
            autoLights = 0;
            digitalWrite(led, LOW);
            break;
            case 420:
            autoLights = 1;
        }
    }
    if (autoLights == 1) {
        lightLevel = map(analogRead(lightDetect), 0, 1023, 1, 100);
        if (lightLevel =< 50) {
            digitalWrite(led, HIGH);
        }
        else {
            digitalWrite(led, LOW);
        }   
    }
    

}