#include "LightSensor.h"

LightSensor::LightSensor(int pin) : pin(pin) {} //constructorul clasei LightSensor

int LightSensor::readValue() { // obtinerea valorii citite de fotorezistor
    return analogRead(pin);
}
