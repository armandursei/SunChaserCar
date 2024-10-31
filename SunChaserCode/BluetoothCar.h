#ifndef BluetoothCar_h
#define BluetoothCar_h

#include <Arduino.h>
#include "Motors.h"

define spe 155

//clasa pentru controlul masinii bluetooth, utilizand clasa Motors.h

class BluetoothCar {
private:
    Motors motor;
    int speed1;
    int speed2;
    int speed3;
    int speed4;
    char cmd;

public:
    BluetoothCar();
    void setup();
    void loop();
    void Motor(int direction);
    void HC05();
};

#endif
