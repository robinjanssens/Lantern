// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>
#include "Background.h"

#define PIN D6

SYSTEM_THREAD(ENABLED);

enum State { rainbow, police, fire, flashes, off } state;

uint8_t x_offset = 0; // automatically rolls over at 256.

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip(300, PIN, WS2812B);

Background background(&strip, &x_offset);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// ------------------------------
// External accessable functions
// ------------------------------

int setRainbow(String userInput) {
  state = rainbow;
  return 0;
}

int setPolice(String userInput) {
  state = police;
  return 0;
}

int setFire(String userInput) {
  state = fire;
  return 0;
}

int setFlashes(String userInput) {
  state = flashes;
  return 0;
}

int setOff(String userInput) {
  state = off;
  return 0;
}

// ------------------------------
// Internal accessable functions
// ------------------------------

void setup() {
  // register the cloud function
  waitUntil(Particle.connected);
  Particle.function("rainbow", setRainbow);
  Particle.function("police", setPolice);
  Particle.function("fire", setFire);
  Particle.function("flashes", setFlashes);
  Particle.function("off", setOff);
  Particle.variable("state",state);
  // code
  state = rainbow;
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  switch (state) {
  case rainbow:
    background.rainbow();
    // background.flashes();
    x_offset++; // increment x offset
    delay(5);   // wait for 5ms
    break;
  case police:
    background.police();
    x_offset++; // increment x offset
    delay(1);
    break;
  case fire:
    background.fire();
    delay(random(20));
    break;
  case flashes:
    background.solid(0,0,0);
    background.flashes();
    delay(5);   // wait for 5ms
    break;
  case off:
    background.solid(0,0,0);
    delay(100);  // wait 100ms
    break;
  default:
    state = rainbow;
    break;
  }
}
