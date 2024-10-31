#include "Motors.h"

Motors::Motors(int pwm1, int pwm2, int pwm3, int pwm4, int clock, int enable, int data, int latch)
    : pwmPin1(pwm1), pwmPin2(pwm2), pwmPin3(pwm3), pwmPin4(pwm4),
      dirClockPin(clock), dirEnablePin(enable), dataPin(data), dirLatchPin(latch) {} //constructorul clasei motor

void Motors::setup() { //setup-ul motoarelor
    pinMode(dirClockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(dirEnablePin, OUTPUT);
    pinMode(dirLatchPin, OUTPUT);
    pinMode(pwmPin1, OUTPUT);
    pinMode(pwmPin2, OUTPUT);
    pinMode(pwmPin3, OUTPUT);
    pinMode(pwmPin4, OUTPUT);
}

void Motors::setSpeed(int speed1, int speed2, int speed3, int speed4) { //setarea vitezei motoarelor
    analogWrite(pwmPin1, speed1);
    analogWrite(pwmPin2, speed2);
    analogWrite(pwmPin3, speed3);
    analogWrite(pwmPin4, speed4);
}

void Motors::setDirection(int direction) { //setarea motoarelor pentru ca masina sa parcurga directia dorita
    digitalWrite(dirLatchPin, LOW);
    shiftOut(dataPin, dirClockPin, MSBFIRST, direction);
    digitalWrite(dirLatchPin, HIGH);
}
