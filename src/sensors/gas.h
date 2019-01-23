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
#ifndef __SENSORS_GAS_H
#define __SENSORS_GAS_H

#include <Adafruit_SGP30.h>

#include "sensors/sensor.h"

class Gas : public Sensor {
 public:
  Gas();
  virtual ~Gas();

  uint16_t getVOCppb() { return tvoc; }
  uint16_t getECO2ppm() { return eco2; }

 protected:
  bool setup();
  bool poll();

 private:
  Adafruit_SGP30 sgp;

  uint16_t tvoc;
  uint16_t eco2;
};

#endif  //__SENSORS_GAS_H
