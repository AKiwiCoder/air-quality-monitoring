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
#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <U8g2lib.h>

#include "sensors/gas.h"
#include "sensors/lux.h"
#include "sensors/particle.h"
#include "sensors/pressure.h"
#include "sensors/temperature.h"
#include "sensors/ultraviolet.h"

class Display {
 public:
  Display(Lux &lux, Ultraviolet &uv, Pressure &pressure, Temperature &temperature,
          Gas &gas, Particle &particle);
  ~Display();

    void setup();

    void showBootScreen();
    void showInitialisationScreen();
    void showInformationScreen();
    
 private:
  Lux &lux;
  Ultraviolet &uv;
  Pressure &pressure;
  Temperature &temperature;
  Gas &gas;
  Particle &particle;

  U8G2_ST7920_128X64_F_SW_SPI u8g2;
};

#endif  //__DISPLAY_H
