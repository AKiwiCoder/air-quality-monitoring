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
#ifndef __SENSORS_TEMPERATURE_H
#define __SENSORS_TEMPERATURE_H

#include <Adafruit_HTU21DF.h>

#include "sensors/sensor.h"

class Temperature : public Sensor {
 public:
  Temperature();
  virtual ~Temperature();

  float getTemperature() { return temperature; }
  float getHumidity() { return humidity; }

  uint32_t getAbsoluteHumidity();

protected:
  bool setup();
  bool poll();

 private:
  Adafruit_HTU21DF htu;

  float temperature;
  float humidity;
};

#endif  //__SENSORS_TEMPERATURE_H
