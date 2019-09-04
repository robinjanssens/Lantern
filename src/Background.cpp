#include "Background.h"
#include <neopixel.h>

Background::Background(Adafruit_NeoPixel* strip, uint8_t* x_offset) {
  this->strip = strip;
  this->x_offset = x_offset;
}

void Background::rainbow() {
  uint8_t value;
  uint8_t red, green, blue;
  for (uint16_t led=0; led<300; led++) {
    value = positions[led][1]+(*x_offset);  // 0 -> 255 (automatically modulo 256)
    red=rainbow_wave_table[value];
    green=rainbow_wave_table[(value+85)%256];
    blue=rainbow_wave_table[(value+171)%256];
    strip->setPixelColor(led, strip->Color(red/8, green/8, blue/8));
  }
  strip->show();
}

void Background::police() {
  uint8_t value, value2;
  for (uint16_t led=0; led<300; led++) {
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
  strip->show();
}

void Background::fire() {
  uint8_t rand;
  for (uint16_t led=0; led<300; led++) {
    rand = random(10,100);
    strip->setPixelColor(led, strip->Color(rand, rand*0.75, 0));
  }
  strip->show();
}

void Background::solid(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint16_t led=0; led<300; led++) {
    strip->setPixelColor(led, strip->Color(red, green, blue));
  }
  strip->show();
}
