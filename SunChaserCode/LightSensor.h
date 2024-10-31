#ifndef LightSensor_h
#define LightSensor_h

#include <Arduino.h>

// clasa pentru fotorezistori

class LightSensor {
private:
    int pin;

public:
    LightSensor(int pin);
    int readValue();
};

#endif
