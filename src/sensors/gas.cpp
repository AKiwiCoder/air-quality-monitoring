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
#include "sensors/gas.h"

#include <Arduino.h>
#include <Wire.h>

Gas::Gas() : Sensor("Gas") {}

Gas::~Gas() {}

bool Gas::setup() {
  if (!sgp.begin()) {
    Serial.println("Sensor not found :(");
    return false;
  }

  // If stored in eeprom
  // sgp.setIAQBaseline(0x8E68, 0x8F41);  // Will vary for each sensor!
  return true;
}

bool Gas::poll() {
  if (!sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return false;
  }

  tvoc = sgp.TVOC;
  eco2 = sgp.eCO2;

  Serial.print("TVOC ");
  Serial.print(tvoc);
  Serial.print(" ppb\t");
  Serial.print("eCO2 ");
  Serial.print(eco2);
  Serial.println(" ppm");

  // Once every 30 seconds
  /*
 counter++;
  if (counter == 30) {
    counter = 0;

    uint16_t TVOC_base, eCO2_base;
    if (! sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
      Serial.println("Failed to get baseline readings");
      return;
    }
    Serial.print("****Baseline values: eCO2: 0x"); Serial.print(eCO2_base, HEX);
    Serial.print(" & TVOC: 0x"); Serial.println(TVOC_base, HEX);
  }
  */
 return true;
}