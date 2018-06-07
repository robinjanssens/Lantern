#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN D6

// define positions of pixels in mm in reference to first led.
const float positions[300][2] = { {0.0,0.0}, {0.842,16.667}, {1.683,33.333}, {2.525,50.0}, {3.367,66.667}, {4.208,83.333}, {5.05,100.0}, {5.892,116.667}, {6.733,133.333}, {7.575,150.0}, {8.417,166.667}, {9.258,183.333}, {10.1,200.0}, {10.942,14.667}, {11.783,31.333}, {12.625,48.0}, {13.467,64.667}, {14.308,81.333}, {15.15,98.0}, {15.992,114.667}, {16.833,131.333}, {17.675,148.0}, {18.517,164.667}, {19.358,181.333}, {20.2,198.0}, {21.042,12.667}, {21.883,29.333}, {22.725,46.0}, {23.567,62.667}, {24.408,79.333}, {25.25,96.0}, {26.092,112.667}, {26.933,129.333}, {27.775,146.0}, {28.617,162.667}, {29.458,179.333}, {30.3,196.0}, {31.142,10.667}, {31.983,27.333}, {32.825,44.0}, {33.667,60.667}, {34.508,77.333}, {35.35,94.0}, {36.192,110.667}, {37.033,127.333}, {37.875,144.0}, {38.717,160.667}, {39.558,177.333}, {40.4,194.0}, {41.242,8.667}, {42.083,25.333}, {42.925,42.0}, {43.767,58.667}, {44.608,75.333}, {45.45,92.0}, {46.292,108.667}, {47.133,125.333}, {47.975,142.0}, {48.817,158.667}, {49.658,175.333}, {50.5,192.0}, {51.342,6.667}, {52.183,23.333}, {53.025,40.0}, {53.867,56.667}, {54.708,73.333}, {55.55,90.0}, {56.392,106.667}, {57.233,123.333}, {58.075,140.0}, {58.917,156.667}, {59.758,173.333}, {60.6,190.0}, {61.442,4.667}, {62.283,21.333}, {63.125,38.0}, {63.967,54.667}, {64.808,71.333}, {65.65,88.0}, {66.492,104.667}, {67.333,121.333}, {68.175,138.0}, {69.017,154.667}, {69.858,171.333}, {70.7,188.0}, {71.542,2.667}, {72.383,19.333}, {73.225,36.0}, {74.067,52.667}, {74.908,69.333}, {75.75,86.0}, {76.592,102.667}, {77.433,119.333}, {78.275,136.0}, {79.117,152.667}, {79.958,169.333}, {80.8,186.0}, {81.642,0.667}, {82.483,17.333}, {83.325,34.0}, {84.167,50.667}, {85.008,67.333}, {85.85,84.0}, {86.692,100.667}, {87.533,117.333}, {88.375,134.0}, {89.217,150.667}, {90.058,167.333}, {90.9,184.0}, {91.742,200.667}, {92.583,15.333}, {93.425,32.0}, {94.267,48.667}, {95.108,65.333}, {95.95,82.0}, {96.792,98.667}, {97.633,115.333}, {98.475,132.0}, {99.317,148.667}, {100.158,165.333}, {101.0,182.0}, {101.842,198.667}, {102.683,13.333}, {103.525,30.0}, {104.367,46.667}, {105.208,63.333}, {106.05,80.0}, {106.892,96.667}, {107.733,113.333}, {108.575,130.0}, {109.417,146.667}, {110.258,163.333}, {111.1,180.0}, {111.942,196.667}, {112.783,11.333}, {113.625,28.0}, {114.467,44.667}, {115.308,61.333}, {116.15,78.0}, {116.992,94.667}, {117.833,111.333}, {118.675,128.0}, {119.517,144.667}, {120.358,161.333}, {121.2,178.0}, {122.042,194.667}, {122.883,9.333}, {123.725,26.0}, {124.567,42.667}, {125.408,59.333}, {127.092,92.667}, {127.933,109.333}, {128.775,126.0}, {129.617,142.667}, {130.458,159.333}, {131.3,176.0}, {132.142,192.667}, {132.983,7.333}, {133.825,24.0}, {134.667,40.667}, {135.508,57.333}, {136.35,74.0}, {137.192,90.667}, {138.033,107.333}, {138.875,124.0}, {139.717,140.667}, {140.558,157.333}, {141.4,174.0}, {142.242,190.667}, {143.083,5.333}, {143.925,22.0}, {144.767,38.667}, {145.608,55.333}, {146.45,72.0}, {147.292,88.667}, {148.133,105.333}, {148.975,122.0}, {149.817,138.667}, {150.658,155.333}, {151.5,172.0}, {152.342,188.667}, {153.183,3.333}, {154.025,20.0}, {154.867,36.667}, {155.708,53.333}, {156.55,70.0}, {157.392,86.667}, {158.233,103.333}, {159.075,120.0}, {159.917,136.667}, {160.758,153.333}, {161.6,170.0}, {162.442,186.667}, {163.283,1.333}, {164.125,18.0}, {164.967,34.667}, {165.808,51.333}, {166.65,68.0}, {167.492,84.667}, {168.333,101.333}, {169.175,118.0}, {170.017,134.667}, {170.858,151.333}, {171.7,168.0}, {172.542,184.667}, {173.383,201.333}, {174.225,16.0}, {175.067,32.667}, {175.908,49.333}, {176.75,66.0}, {177.592,82.667}, {178.433,99.333}, {179.275,116.0}, {180.117,132.667}, {180.958,149.333}, {181.8,166.0}, {182.642,182.667}, {183.483,199.333}, {184.325,14.0}, {185.167,30.667}, {186.008,47.333}, {186.85,64.0}, {187.692,80.667}, {188.533,97.333}, {189.375,114.0}, {190.217,130.667}, {191.058,147.333}, {191.9,164.0}, {192.742,180.667}, {193.583,197.333}, {194.425,12.0}, {195.267,28.667}, {196.108,45.333}, {196.95,62.0}, {197.792,78.667}, {198.633,95.333}, {199.475,112.0}, {200.317,128.667}, {201.158,145.333}, {202.0,162.0}, {202.842,178.667}, {203.683,195.333}, {204.525,10.0}, {205.367,26.667}, {206.208,43.333}, {207.05,60.0}, {207.892,76.667}, {208.733,93.333}, {209.575,110.0}, {210.417,126.667}, {211.258,143.333}, {212.1,160.0}, {212.942,176.667}, {213.783,193.333}, {214.625,8.0}, {215.467,24.667}, {216.308,41.333}, {217.15,58.0}, {217.992,74.667}, {218.833,91.333}, {219.675,108.0}, {220.517,124.667}, {221.358,141.333}, {222.2,158.0}, {223.042,174.667}, {223.883,191.333}, {224.725,6.0}, {225.567,22.667}, {226.408,39.333}, {227.25,56.0}, {228.092,72.667}, {228.933,89.333}, {229.775,106.0}, {230.617,122.667}, {231.458,139.333}, {232.3,156.0}, {233.142,172.667}, {233.983,189.333}, {234.825,4.0}, {235.667,20.667}, {236.508,37.333}, {237.35,54.0}, {238.192,70.667}, {239.033,87.333}, {239.875,104.0}, {240.717,120.667}, {241.558,137.333}, {242.4,154.0}, {243.242,170.667}, {244.083,187.333}, {244.925,2.0}, {245.767,18.667}, {246.608,35.333}, {247.45,52.0}, {248.292,68.667}, {249.133,85.333}, {249.975,102.0}, {250.817,118.667}, {251.658,135.333}, {252.5,152.0} };
const float max_width = 202;
const float max_height = 252.5;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(301, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel remappedStrip = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800);

uint8_t matrix[25][12][3]; // rows, columns, color

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  remappedStrip.begin();
  show(); // Initialize all pixels to 'off'
}

void loop() {
//  char state;
//  state=Serial.read();
//  if (state==32){
//    // off state
//  }
//  else {
    // fire(1000);
    // rowtest(500);
//    columntest(500);
  rotation();
//  police();
//  }
}

void rotation() {
  for (float offset=0; offset<=1; offset=offset+0.01) {
    for (uint16_t led=0; led<300; led++) {
      float value = positions[led][1]/max_width;  // 0 -> 1
      if ((value+offset>0 && value+offset<0.5) || (value+offset>1 && value+offset<1.5)) {
        float value2 = (1-cos(2*PI*2*(value+offset)))/2;
        remappedStrip.setPixelColor(led, strip.Color(0, 0, 32*value2));
      }
      else {
        remappedStrip.setPixelColor(led, strip.Color(0, 0, 0));
      }
    }
    remappedStrip.show();
    delay(5);
  }
}

void police() {
  for (float offset=0; offset<=1; offset=offset+0.01) {
    for (uint16_t led=0; led<300; led++) {
      float value = positions[led][1]/max_width;  // 0 -> 1
      float value2 = (1-cos(2*PI*2*(value+offset)))/2;
      if ((value+offset>0 && value+offset<0.5) || (value+offset>1 && value+offset<1.5)) {
        remappedStrip.setPixelColor(led, strip.Color(0, 0, 255*value2));
      }
      else {
        remappedStrip.setPixelColor(led, strip.Color(255*value2, 0, 0));
      }
    }
    remappedStrip.show();
    delay(5);
  }
}

void rowtest(uint16_t duration) {
  for (uint8_t row=0; row<=24; row++) {     // row iterator
    for (uint8_t i=0; i<=24; i++) {     // row iterator
      for (uint8_t j=0; j<=11; j++) {   // column iterator
        if (i==row) {
          matrix[i][j][1] = 0;
          matrix[i][j][2] = 0;
          matrix[i][j][3] = 127;
        }
        else {
          matrix[i][j][1] = 0;
          matrix[i][j][2] = 0;
          matrix[i][j][3] = 0;
        }
      }
    }
    map();
    show();
    delay(duration);
  }
}
void columntest(uint16_t duration) {
  for (uint8_t column=0; column<=11; column++) {     // column iterator
    for (uint8_t i=0; i<=24; i++) {     // row iterator
      for (uint8_t j=0; j<=11; j++) {   // column iterator
        if (j==column) {
          matrix[i][j][1] = 0;
          matrix[i][j][2] = 0;
          matrix[i][j][3] = 127;
        }
        else {
          matrix[i][j][1] = 0;
          matrix[i][j][2] = 0;
          matrix[i][j][3] = 0;
        }
      }
    }
    map();
    show();
    delay(duration);
  }
}

void fire(uint16_t duration) {
  unsigned long stopTime = millis() + duration;
  byte rand;
  while(millis()<=stopTime)
  {
    for (int i=0; i < strip.numPixels(); i++)
    {
      rand = random(10,100);
      strip.setPixelColor(i,rand,rand * 0.75,0);
    }
    show();
    delay(random(20));
  }
}

void test() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void map() {
  uint16_t led = 0;
  for (uint8_t i=0; i<=24; i++) {    // row iterator
    for (uint8_t j=0; j<=11; j++) {  // column iterator
      strip.setPixelColor(led, strip.Color(matrix[i][j][1], matrix[i][j][2], matrix[i][j][3]));
      led++;
    }
  }
}

void show() {
  for (uint16_t i=0; i<remappedStrip.numPixels(); i++) {
    if(i<150) {
      remappedStrip.setPixelColor(i, strip.getPixelColor(i));
    }
    else {
      remappedStrip.setPixelColor(i, strip.getPixelColor(i+1));
    }
  }
  remappedStrip.show();
}
