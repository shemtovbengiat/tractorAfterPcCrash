/*
There are 5 strips of neopixles in the tractor:
1. 1 strip 42 leds within the motor chassis as -- motorNeopixles
2. 2 rings "big" 5 cm diameter as headlights in front of the tractor, 12 leds each as -- headNeopixles
3. 2 rings "small" 3 cm diameter as rearlights in the back of the tractor, 8 leds each as -- backNeopixles
4. 1 ring "huge" 10 cm diameter as exhaust light on top of the motor cover of the tractor as -- exhaustNeopixles
5. 1 strip ??50  leds in the interior of the cabine tractor for ambient atmoshere - interiorlNeopixle


#define neoMotorNo       42     //number of leds for engine NeoPixel 
#define neoHeadNo        12     //number of leds for head light NeoPixel
#define neoBackNo         8     //number of leds for back light  NeoPixel
#define neoInteriorNo    50     //number of leds for interior NeoPixel
#define neoExhaostNo     16     //number of leds for exhaost NeoPixel ring 

// ----------------   neopixle INITIALIZATION routine  -----------------
void neopixleIni()
{
// constructing 5 classs for each neopixle
Adafruit_NeoPixel neoMotor = Adafruit_NeoPixel(neoMotorNo, neoMotorPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoHead = Adafruit_NeoPixel(neoHeadNo, neoHeadPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoBack = Adafruit_NeoPixel(neoBackNo, neoBackPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoInterior = Adafruit_NeoPixel(neoInteriorNo, neoInteriorPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoExhaost = Adafruit_NeoPixel(neoExhaostNo, neoExhaostPin, NEO_GRB + NEO_KHZ800);

  neoMotor.begin();           // initilaze the 5 classe
  neoHead.begin();
  neoBack.begin();
  neoInterior.begin();
  neoExhaost.begin();
  
}//-END of INITIALIZATION routine
*/
