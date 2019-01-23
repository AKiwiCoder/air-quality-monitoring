/*
MIT License

Copyright (c) 2018 Andrew Norman

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <Arduino.h>
#include <Wire.h>

#include "sensors/gas.h"
#include "sensors/lux.h"
#include "sensors/particle.h"
#include "sensors/pressure.h"
#include "sensors/temperature.h"
#include "sensors/ultraviolet.h"

#include "display/display.h"

Lux lux = Lux();
Ultraviolet uv = Ultraviolet();
Pressure pressure = Pressure();
Temperature temperature = Temperature();
Gas gas = Gas();
Particle particle = Particle();

Sensor *sensors[] = {&lux, &uv, &pressure, &temperature, &gas, &particle};

Display display(lux, uv, pressure, temperature, gas, particle);

int state = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Air Quality Monitor: Setup");

  display.setup();
}

void loop() {
  if (state == 0) {
    display.showBootScreen();
  }

  if (state == 1) {
    display.showInitialisationScreen();

    for (Sensor *sensor : sensors) {
      sensor->setupSensor();
 
      display.showInitialisationScreen();
    }
  }

  if (state == 2) {
    for (Sensor *sensor : sensors) {
      sensor->updateReadings();
    }
    display.showInformationScreen();
  }
}