// Necessary libraries: Servo
#include <Servo.h>

const int motorrp = 10;
const int motorrn = 11;
const int motorlp = 12;
const int motorln = 13;
const int trig = 5;
const int echo = 6;
const int ledr = 7;
const int ledl = 8;

Servo sweepServo;

void setup() {
    pinMode(motorrp, OUTPUT);
    pinMode(motorrn, OUTPUT);
    pinMode(motorlp, OUTPUT);
    pinMode(motorln, OUTPUT);
    pinMode(ledr, OUTPUT);
    pinMode(ledl, OUTPUT);
    sweepServo.attach(9);
    sweepServo.write(90);
    
}

void loop() {
    digitalWrite(motorrp, HIGH);
    digitalWrite(motorlp, HIGH);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorln, LOW);
    delay(2000);
    digitalWrite(motorrp, LOW);
    delay(500);
    digitalWrite(motorrp, HIGH);
    delay(1000);
    digitalWrite(motorlp, LOW);
    delay(500);
    digitalWrite(motorlp, HIGH);
    delay(1000);
    digitalWrite(motorrp, LOW);
    digitalWrite(motorlp, LOW);
    delay(5000);
    digitalWrite(motorrn, HIGH);
    digitalWrite(motorln, HIGH);
    delay(2000);
    digitalWrite(motorrn, LOW);
    delay(500);
    digitalWrite(motorrn, HIGH);
    delay(1000);
    digitalWrite(motorln, LOW);
    delay(500);
    digitalWrite(motorln, HIGH);
    delay(1000);
    digitalWrite(motorrn, LOW);
    digitalWrite(motorln, LOW);
    delay(10000);

}