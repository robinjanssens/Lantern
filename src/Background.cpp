#include "Background.h"
#include <neopixel.h>

Background::Background(Adafruit_NeoPixel* strip, uint8_t* x_offset) {
  this->strip = strip;
  this->x_offset = x_offset;
}

// ------------------------------
// Backgrounds
// ------------------------------

void Background::rainbow() {
  uint8_t value;
  uint8_t red, green, blue;
  for (uint16_t led=0; led<strip->numPixels(); led++) {
    value = positions[led][1]+(*x_offset);  // 0 -> 255 (automatically modulo 256)
    red=rainbow_wave_table[value];
    green=rainbow_wave_table[(value+85)%256];
    blue=rainbow_wave_table[(value+171)%256];
    strip->setPixelColor(led, strip->Color(red/8, green/8, blue/8));
    // clear flashes_overlay
    flashes_overlay[0] = 0;
  }
}

void Background::police() {
  uint8_t value, value2;
  for (uint16_t led=0; led<strip->numPixels(); led++) {
    value = positions[led][1]+(*x_offset);  // 0 -> 255 (automatically modulo 256)
    if (value>0 && value<128) {
      value2 = 255-cosinus_table[2*value];
      strip->setPixelColor(led, strip->Color(0, 0, value2/8));
    }
    else {
      value2 = 255-cosinus_table[(2*value)%256];
      strip->setPixelColor(led, strip->Color(value2/8, 0, 0));
    }
  }
}

void Background::fire() {
  uint8_t rand;
  for (uint16_t led=0; led<strip->numPixels(); led++) {
    rand = random(10,100);
    strip->setPixelColor(led, strip->Color(rand, rand*0.75, 0));
  }
}

void Background::solid(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint16_t led=0; led<strip->numPixels(); led++) {
    strip->setPixelColor(led, strip->Color(red, green, blue));
  }
}

// ------------------------------
// Overlays
// ------------------------------

void Background::flashes() {
  uint16_t led;
  if ( (counter % 4) == 0 ) {
    led = random(strip->numPixels()); // select random led
    flashes_overlay[led] = 255; // turn on
  }
  counter++; // automatically rolls over
  for (led=0; led<strip->numPixels(); led++) {
    uint8_t flash_intensity = flashes_overlay[led]/4;
    strip->setPixelColor(led, strip->Color(flash_intensity+getRed(strip->getPixelColor(led)), flash_intensity+getGreen(strip->getPixelColor(led)), flash_intensity+getBlue(strip->getPixelColor(led))));
    if ( flashes_overlay[led] > 0 ) { // fade away
      if ( flashes_overlay[led] > 4 ) {
        flashes_overlay[led]-=4;
      } else {
        flashes_overlay[led]=0;
      }
    }
  }
}

// ------------------------------
// Support Functions
// ------------------------------
uint8_t Background::getRed(uint32_t color) {
  return (color >> 16) & 0xFF;
}
uint8_t Background::getGreen(uint32_t color) {
  return (color >> 8) & 0xFF;
}
uint8_t Background::getBlue(uint32_t color) {
  return color & 0xFF;
}
