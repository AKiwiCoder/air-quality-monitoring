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
#include "sensors/pressure.h"

#include <Arduino.h>
#include <Wire.h>

Pressure::Pressure() : Sensor("Pressure") {

}

Pressure::~Pressure(){}

bool Pressure::setup() {
 if (!baro.begin()) {
    Serial.println("Cannot find barometric sensor");
    return false;
  }

  return true;
}

bool Pressure::poll() {
    float pascals = baro.getPressure();
  float millibars = pascals * 0.01;  // 1 pascal == 0.01 millibar
  Serial.print("Pressure: ");
  Serial.print(millibars);
  Serial.println(" mb"); 
  return true;
}