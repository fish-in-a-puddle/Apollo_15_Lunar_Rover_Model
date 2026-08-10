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
const int lightDetect = A0;
int lightLevel;
long duration;
int distance;
int distance2;
int obstacleRight;
int obstacleLeft;
int autoDrive = 0; 
int autoLights;
int btIn;
int ran;

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
    delay(random(50, 100));
}

void loop() {
    if (Serial.available() > 0) {
        btIn = Serial.read();
        Serial.println(btIn);
        switch (btIn) {
            case 119:
            Serial.println("go forward");
            goForward();
            break;
            case 100:
            Serial.println("turn right");
            turnRight();
            break;
            case 97:
            Serial.println("turn left");
            turnLeft();
            break;
            case 115:
            Serial.println("go backwards");
            goBackward();
            break;
            case 99:
            Serial.println("turn right backwards");
            turnRightBackwards();
            break;
            case 122:
            Serial.println("turn left backwards");
            turnLeftBackwards();
            break;
            case 120:
            Serial.println("stop");
            stop();
            break;
            case 114:
            Serial.println("auto drive on");
            autoDrive = 1;
            break;
            case 101:
            Serial.println("auto drive off");
            autoDrive = 0;
            break;
            case 102:
            Serial.println("lights on");
            autoLights = 0;
            digitalWrite(led, HIGH);
            break;
            case 103:
            Serial.println("lights off");
            autoLights = 0;
            digitalWrite(led, LOW);
            break;
            case 104:
            Serial.println("auto lights active");
            autoLights = 1;
            break;
       }
    }
    if (autoDrive == 1) {
            digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration = pulseIn(echoPin2, HIGH);
    distance2 = duration * 0.034 / 2;
    if (distance <= 30 || distance2 <= 30) {
        stop();
        obstacleRight = (digitalRead(irr));
        if (obstacleRight == HIGH) {
            obstacleLeft = (digitalRead(irl));
            if (obstacleLeft == HIGH) {
                stop();
            }
            turnLeftBackwards();
        }
        else {
            turnRightBackwards();
        }
    }
    else {
        goForward();
    }
    delay(200);
    }
    if (autoLights == 1) {
        lightLevel = map(analogRead(lightDetect), 0, 1023, 1, 100);
        if (lightLevel << 51) {
            digitalWrite(led, HIGH);
        }
        else {
            digitalWrite(led, LOW);
        }
    }
    ran = random(1, 4);
    if (ran == 3){
        servoMotion();
    }

    

}