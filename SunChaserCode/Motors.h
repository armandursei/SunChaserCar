#ifndef Motors_h
#define Motors_h

#include <Arduino.h>
#include <AFMotor.h>

// clasa pentru actionarea motoarelor, dezvoltata cu ajutorul clasei AFMotor.h

class Motors {
private:
    int pwmPin1;
    int pwmPin2;
    int pwmPin3;
    int pwmPin4;
    int dirClockPin;
    int dirEnablePin;
    int dataPin;
    int dirLatchPin;

public:
    Motors(int pwm1, int pwm2, int pwm3, int pwm4, int clock, int enable, int data, int latch);
    void setup();
    void setSpeed(int speed1, int speed2, int speed3, int speed4);
    void setDirection(int direction);
};

#endif
