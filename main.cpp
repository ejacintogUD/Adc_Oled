/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "I2C.h"
#include "ThisThread.h"
#include "mbed.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h" 


// Blinking rate in milliseconds
#define BLINKING_RATE     1000ms

I2C i2c (D14,D15);
Adafruit_SSD1306_I2c oled (i2c, D0);


AnalogIn ain(A0);

float Vin=0.0;
int ent=0;
int dec=0;

int main()
{
    oled.begin();
    oled.display();
    ThisThread::sleep_for(3000ms);

    while (true) {

        Vin = ain*3.3;
        ent = int(Vin); // casting
        dec = int((Vin-ent)*10000); 
        printf("El voltaje es: %01u.%04u volts \n\r", ent, dec);

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
