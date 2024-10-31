#include "BluetoothCar.h"

BluetoothCar::BluetoothCar() : motor(11, 3, 6, 5, 4, 7, 8, 12), speed1(spe), speed2(spe), speed3(spe), speed4(spe) {} // constructorul clasei BluetoothCar

void BluetoothCar::setup() { //setup-ul masinii care consta in setup-ul motoarelor si a modului bluetooth
    Serial.begin(9600);
    motor.setup();
}

void BluetoothCar::loop() { // bucla pentru instructiunile primite prin bluetooth
    HC05();
}

void BluetoothCar::Motor(int direction) {  //setarea masinii sa mearga intr-o directie cu o viteza
    motor.setSpeed(speed1, speed2, speed3, speed4);
    motor.setDirection(direction);
}

void BluetoothCar::HC05() { // setarea directiei de mers a masinii in fucntie de comanda primita prin modulul bluetooth de la smartphone
    if (Serial.available() > 0) { 
        char serialData = Serial.read();

        if ('F' == serialData) cmd = 'F';
        else if ('B' == serialData) cmd = 'B';
        else if ('L' == serialData) cmd = 'L';
        else if ('R' == serialData) cmd = 'R';
        else if ('S' == serialData) cmd = 'S';
        else if ('C' == serialData) cmd = 'C';
        else if ('D' == serialData) cmd = 'D';
        
    }

    if ('F' == cmd) Motor(39);
    else if ('B' == cmd) Motor(216);
    else if ('L' == cmd) Motor(116);
    else if ('R' == cmd) Motor(139);
    else if ('S' == cmd) Motor(0);
    else if ('C' == cmd) Motor(106);
    else if ('D' == cmd) Motor(149);
}
