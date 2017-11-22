#include "FastLED.h"
#include "map.h"


#define NUM_LEDS 40

CRGB leds[NUM_LEDS];
const uint8_t* index;

//uint8_t globe[80][40][3];

void setup() 
{ 
    delay(1000);
    LEDS.addLeds<APA102, 11, 13, BGR>(leds, NUM_LEDS);  // Use this for WS2801 or APA102
    FastLED.setBrightness(120);
}

void loop() 
{
    display_image();
}



void display_image()
{
  const uint8_t* index = map1;
  
  for(int colonne = 0; colonne < 80; colonne++)
  {
    for(int ligne = 39; ligne >= 0; ligne--)
    { 
      
      leds[ligne].r = pgm_read_byte(index++);
      leds[ligne].g = pgm_read_byte(index++);
      leds[ligne].b = pgm_read_byte(index++);
    }
    
    FastLED.show();
    delayMicroseconds(5);
  }
}




