  #include <Servo.h>
  #include "BluetoothCar.h"
  #include "LightSensor.h"

  #define SERVOPINH  10 // definirea portului servo-ului orizontal
  #define SERVOPINV  9  // definirea portului servo-ului vertical

  #define dtime   20   // Delay in milisecunde 
  #define tol   10      // intervalul de raspuns la lumina, mai mic, 
                        //mai sensibil (intre 10 si 100, depinzand de intensitatea luminii ambientale)

  #define spe 155

  Servo horizontal;             // initializarea servo-ului orizontal
  int servoh = 90;              // unghi default 
  int servohLimitHigh = 175;    // unghi maxim de rotatie orizonatala
  int servohLimitLow = 5;       // unghi minim de rotatie orizonatala

  Servo vertical;               // initializarea servo-ului vertical
  int servov = 5;               // unghi default 
  int servovLimitHigh = 85;     // unghi maxim de rotatie verticala
  int servovLimitLow = 5;       // unghi minim de rotatie verticala

  LightSensor ldrlt(A1);   // initializarea fotorezistorului stanga-sus
  LightSensor ldrrt(A3);   // initializarea fotorezistorului dreapta-sus
  LightSensor ldrld(A2);   // initializarea fotorezistorului stanga-jos
  LightSensor ldrrd(A0);   // initializarea fotorezistorului dreapta-jos

  BluetoothCar car; // initializarea masinii

  void setup() { // setup-ul general
      car.setup();

      horizontal.attach(SERVOPINH);
      vertical.attach(SERVOPINV);
      horizontal.write(servoh);
      vertical.write(servov);
      delay(100);
  }

  void loop() {
    car.loop();

    int lt = ldrlt.readValue();
    int rt = ldrrt.readValue();
    int ld = ldrld.readValue();
    int rd = ldrrd.readValue();

    // Calcularea mediei valorilor senzorilor adiacenți
    int avt = (lt + rt) / 2; 
    int avd = (ld + rd) / 2; 
    int avl = (lt + ld) / 2; 
    int avr = (rt + rd) / 2; 
    
    // Calcularea diferenței mediei valorilor orizontale și verticale
    int dvert = avt - avd;    // Diferența verticală
    int dhoriz = avl - avr;    // Diferența orizontală

    // Verificarea dacă diferența se încadrează în intervalul de toleranță; în caz contrar, schimbarea unghiului vertical
    if (-1*tol > dvert || dvert > tol) 
    {
      if (avt < avd)
      {
        servov = ++servov;
        if (servov > servovLimitHigh) 
        { 
          servov = servovLimitHigh;
        }
      }
      else if (avt > avd)
      {
        servov= --servov;
        if (servov < servovLimitLow)
        {
          servov = servovLimitLow;
        }
      }
      vertical.write(servov);
    }

    // Verificarea dacă diferența se încadrează în intervalul de toleranță; în caz contrar, schimbarea unghiului orizontal
    if (-1*tol > dhoriz || dhoriz > tol) 
    {
      if (avl < avr)
      {
        servoh = --servoh;
        if (servoh < servohLimitLow)
        {
          servoh = servohLimitLow;
        }
      }
      else if (avl > avr)
      {
        servoh = ++servoh;
        if (servoh > servohLimitHigh)
        {
          servoh = servohLimitHigh;
        }
      }
      horizontal.write(180-servoh); 
    }
    delay(dtime);
  }

