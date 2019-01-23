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
#include "utils/air_quality_calculator.h"

/*
Index	Ozone, Running 8 hourly mean (μg/m3)	Nitrogen Dioxide, Hourly mean (μg/m3)	Sulphur Dioxide, 15 minute mean (μg/m3)	PM2.5 Particles, 24 hour mean (μg/m3)	PM10 Particles, 24 hour mean (μg/m3)
1	    0–33	                                0–67	                                0–88	                                0–11	                                0–16
2	    34–66	                                68–134                              	89–177	                                12–23	                                17–33
3	    67–100	                                135–200	                                178–266	                                24–35	                                34–50
4	    101–120	                                201–267	                                267–354	                                36–41	                                51–58
5	    121–140	                                268–334	                                355–443	                                42–47	                                59–66
6	    141–160	                                335–400	                                444–532	48–53	67–75
7	    161–187	                                401–467	                                533–710	54–58	76–83
8	    188-213	                                468–534	                                711–887	59–64	84–91
9	    214–240	                                535–600	                                888–1064	65–70	92–100
10	    ≥ 241	                                ≥ 601	                                ≥ 1065	≥ 71	≥ 101
*/
