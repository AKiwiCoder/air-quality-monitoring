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
#include "display/display.h"

Display::Display(Lux &lux, Ultraviolet &uv, Pressure &pressure,
                 Temperature &temperature, Gas &gas, Particle &particle)
    : lux(lux),
      uv(uv),
      pressure(pressure),
      temperature(temperature),
      gas(gas),
      particle(particle),
      u8g2(U8G2_R0, 13, 11, 12, U8X8_PIN_NONE) {}

Display::~Display() {}

void Display::setup() { u8g2.begin(); }

void Display::showBootScreen() {
  u8g2.clearBuffer();

  u8g2.drawLine(64, 0, 64, 64);
  u8g2.drawLine(0, 32, 128, 32);
//   drawInfo(0, 0, &data[0]);
//   drawInfo(64, 0, &data[1]);
//   drawInfo(0, 32, &data[2]);
//   drawInfo(64, 32, &data[3]);
  
  u8g2.sendBuffer();
}

void Display::showInitialisationScreen() {
  u8g2.clearBuffer();

  u8g2.drawLine(64, 0, 64, 64);
  u8g2.drawLine(0, 32, 128, 32);
//   drawInfo(0, 0, &data[0]);
//   drawInfo(64, 0, &data[1]);
//   drawInfo(0, 32, &data[2]);
//   drawInfo(64, 32, &data[3]);
  
  u8g2.sendBuffer();
}

void Display::showInformationScreen() {
  u8g2.clearBuffer();

  u8g2.drawLine(64, 0, 64, 64);
  u8g2.drawLine(0, 32, 128, 32);
//   drawInfo(0, 0, &data[0]);
//   drawInfo(64, 0, &data[1]);
//   drawInfo(0, 32, &data[2]);
//   drawInfo(64, 32, &data[3]);

  u8g2.sendBuffer();
}
