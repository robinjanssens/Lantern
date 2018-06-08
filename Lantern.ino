#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN D6

// define positions of pixels in reference to first led.
const uint8_t positions[300][2] = { {0,0}, {1,21}, {2,42}, {3,63}, {3,84}, {4,105}, {5,126}, {6,147}, {7,168}, {8,189}, {9,210}, {9,231}, {10,252}, {11,19}, {12,40}, {13,61}, {14,82}, {14,103}, {15,124}, {16,145}, {17,166}, {18,187}, {19,208}, {20,229}, {20,250}, {21,16}, {22,37}, {23,58}, {24,79}, {25,100}, {26,121}, {26,142}, {27,163}, {28,184}, {29,205}, {30,226}, {31,247}, {31,13}, {32,35}, {33,56}, {34,77}, {35,98}, {36,119}, {37,140}, {37,161}, {38,182}, {39,203}, {40,224}, {41,245}, {42,11}, {43,32}, {43,53}, {44,74}, {45,95}, {46,116}, {47,137}, {48,158}, {48,179}, {49,200}, {50,221}, {51,242}, {52,8}, {53,29}, {54,50}, {54,72}, {55,93}, {56,114}, {57,135}, {58,156}, {59,177}, {60,198}, {60,219}, {61,240}, {62,6}, {63,27}, {64,48}, {65,69}, {65,90}, {66,111}, {67,132}, {68,153}, {69,174}, {70,195}, {71,216}, {71,237}, {72,3}, {73,24}, {74,45}, {75,66}, {76,88}, {77,109}, {77,130}, {78,151}, {79,172}, {80,193}, {81,214}, {82,235}, {82,1}, {83,22}, {84,43}, {85,64}, {86,85}, {87,106}, {88,127}, {88,148}, {89,169}, {90,190}, {91,211}, {92,232}, {93,253}, {94,19}, {94,40}, {95,61}, {96,82}, {97,104}, {98,125}, {99,146}, {99,167}, {100,188}, {101,209}, {102,230}, {103,251}, {104,17}, {105,38}, {105,59}, {106,80}, {107,101}, {108,122}, {109,143}, {110,164}, {111,185}, {111,206}, {112,227}, {113,248}, {114,14}, {115,35}, {116,56}, {116,77}, {117,98}, {118,120}, {119,141}, {120,162}, {121,183}, {122,204}, {122,225}, {123,246}, {124,12}, {125,33}, {126,54}, {127,75}, {128,117}, {129,138}, {130,159}, {131,180}, {132,201}, {133,222}, {133,243}, {134,9}, {135,30}, {136,51}, {137,72}, {138,93}, {139,114}, {139,135}, {140,157}, {141,178}, {142,199}, {143,220}, {144,241}, {145,7}, {145,28}, {146,49}, {147,70}, {148,91}, {149,112}, {150,133}, {150,154}, {151,175}, {152,196}, {153,217}, {154,238}, {155,4}, {156,25}, {156,46}, {157,67}, {158,88}, {159,109}, {160,130}, {161,151}, {162,173}, {162,194}, {163,215}, {164,236}, {165,2}, {166,23}, {167,44}, {167,65}, {168,86}, {169,107}, {170,128}, {171,149}, {172,170}, {173,191}, {173,212}, {174,233}, {175,254}, {176,20}, {177,41}, {178,62}, {179,83}, {179,104}, {180,125}, {181,146}, {182,167}, {183,189}, {184,210}, {184,231}, {185,252}, {186,18}, {187,39}, {188,60}, {189,81}, {190,102}, {190,123}, {191,144}, {192,165}, {193,186}, {194,207}, {195,228}, {196,249}, {196,15}, {197,36}, {198,57}, {199,78}, {200,99}, {201,120}, {201,141}, {202,162}, {203,183}, {204,205}, {205,226}, {206,247}, {207,13}, {207,34}, {208,55}, {209,76}, {210,97}, {211,118}, {212,139}, {212,160}, {213,181}, {214,202}, {215,223}, {216,244}, {217,10}, {218,31}, {218,52}, {219,73}, {220,94}, {221,115}, {222,136}, {223,157}, {224,178}, {224,199}, {225,220}, {226,242}, {227,8}, {228,29}, {229,50}, {230,71}, {230,92}, {231,113}, {232,134}, {233,155}, {234,176}, {235,197}, {235,218}, {236,239}, {237,5}, {238,26}, {239,47}, {240,68}, {241,89}, {241,110}, {242,131}, {243,152}, {244,173}, {245,194}, {246,215}, {247,236}, {247,3}, {248,24}, {249,45}, {250,66}, {251,87}, {252,108}, {252,129}, {253,150}, {254,171}, {255,192} };

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
  for (uint8_t offset=0; offset<=255; offset++) {
    for (uint16_t led=0; led<300; led++) {
      uint8_t value = positions[led][1]+offset;  // 0 -> 255 (automatically modulo 256)
      if (value>0 && value<128) {
        uint8_t value2 = round((1-cos(2*PI*2*value/255))/2*255);
        remappedStrip.setPixelColor(led, strip.Color(0, 0, value2/4));
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
  for (uint8_t offset=0; offset<=255; offset++) {
    for (uint16_t led=0; led<300; led++) {
      uint8_t value = positions[led][1]+offset;  // 0 -> 255 (automatically modulo 256)
      uint8_t value2 = round((1-cos(2*PI*2*value/255))/2*255);
      if (value>0 && value<128) {
        remappedStrip.setPixelColor(led, strip.Color(0, 0, value2/4));
      }
      else {
        remappedStrip.setPixelColor(led, strip.Color(value2/4, 0, 0));
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
