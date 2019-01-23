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
#include "sensors/particle.h"

#include <Arduino.h>
#include <Wire.h>

Particle::Particle() :Sensor("Particle"),  hpmaSerial(D6, D7), hpma115S0(hpmaSerial) {}

Particle::~Particle() {}

bool Particle::setup() {
  hpmaSerial.begin(9600);
  hpma115S0.Init();
  hpma115S0.StartParticleMeasurement();
  return true;
}

bool Particle::poll() {
    if (hpma115S0.ReadParticleMeasurement(&pm2_5, &pm10)) {
      Serial.println("PM 2.5: " + String(pm2_5) + " ug/m3");
      Serial.println("PM 10: " + String(pm10) + " ug/m3");
    }
    return true;
}