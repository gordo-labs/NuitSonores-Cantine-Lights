
#define FASTLED_INTERNAL
#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 284
#define MAX_LEDS 284
#define AV_LEDS 284
#define BRIGHTNESS  100

#define INIT_LED 17

CRGB leds[NUM_LEDS];

#define BUTTONPIN 2

int buttonState = LOW;  
int BASE = 0;

int cycle = 0;
int cycleValue = 6;

int progressiveTime = 40;

int mode = 0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  set_max_power_in_volts_and_milliamps(5, 20000); 

  pinMode(BUTTONPIN, INPUT_PULLUP);
  
}
void loop() {
  for (int i = 0; i <= MAX_LEDS; i++) {
    leds[i] = CRGB (0, 0, 0);
  }
  FastLED.show();

  buttonState = digitalRead(BUTTONPIN);
 
  if (buttonState == HIGH) {
    cycleMode(255, 255, 255);
    //easeProgression(300);
    //progresiveMode(255,255,255);
    //progresiveModeFarmacy(255,255,255);
    //glitchMode();
    //glitchModeFast();
    //randomColorMode();
    //delay(5000);
    
  } else if  (buttonState == LOW) {
    //progresiveMode(255, 255, 255);
    //glitchMode();
    switchOn(255,255,255);
  }

 //progresiveMode(255, 255, 255); 

 //binaryMode(255,255,255);

 //glitchMode();
 //test(255,255,255);
 
}

void cycleMode(int R, int G, int B){
  int inc = 2;
  if (cycle >= 0 && cycle < cycleValue) {
   
    progresiveMode(R, G, B);
    cycle = cycle + 1;
  } else if (cycle >= cycleValue && cycle < cycleValue * 3) {
    glitchMode();
    cycle = cycle + 1;
    inc = inc + 1;
  } else if (cycle >= cycleValue * 3 && cycle < cycleValue * 4) {
    glitchModeFast();
    cycle = cycle + 1;
    inc = inc + 1;
  } else if (cycle >= cycleValue * 4 && cycle < cycleValue * 5) {
    progresiveModeFarmacy(R, G, B);
    cycle = cycle + 1;
    inc = inc + 1;
  } else if (cycle >= cycleValue * 5 && cycle < cycleValue * 8) {
    randomColorMode();
    cycle = cycle + 1;
    inc = inc + 1;
  } else if (cycle >= cycleValue * 8 && cycle < cycleValue * 9) {
    glitchMode();
    jumpsMode(R, G, B, 5);
    cycle = cycle + 1;
    inc = inc + 1;
  } else if (cycle >= cycleValue * 9 && cycle < cycleValue * 10) {
    progresiveModeExp(R, G, B, 5);
    cycle = cycle + 1;
    inc = inc + 1;
  } else {
    cycle = 0;
  }
}

void switchOffLoop(){
  for (int i = 0; i <= AV_LEDS; i++) {
    leds[i] = CRGB ( 0, 0, 0);
  }
  FastLED.show();
}

void progresiveMode(int R, int G,int B){
  for (int i = 0; i <= MAX_LEDS; i++) {
    leds[i] = CRGB (0, 0, 0);
  }
  FastLED.show();
  
  for (int i = INIT_LED; i <= AV_LEDS; i++) {
    leds[i] = CRGB (R, G, B);
    FastLED.show();
    delay(progressiveTime);
  }
  
  for (int i = AV_LEDS; i > 0; i--) {
    leds[i] = CRGB (0, 0, 0);
    FastLED.show();
    delay(progressiveTime);
  }
}


void progresiveModeFarmacy(int R, int G,int B){
  for (int i = 0; i <= MAX_LEDS; i++) {
    leds[i] = CRGB (0, 0, 0);
  }
  FastLED.show();
  
  for (int i = INIT_LED; i <= AV_LEDS; i++) {
    leds[i] = CRGB (R, G, B);
    FastLED.show();
    delay(progressiveTime);
  }
  
  for (int i = INIT_LED; i <= AV_LEDS; i++) {
    leds[i] = CRGB (0, 0, 0);
    FastLED.show();
    delay(progressiveTime);
  }
}

void progresiveModeExp(int R, int G,int B, int amount){

  int cycles = 10;
  int total = MAX_LEDS / amount - amount;
    for (int a = 0; a <= cycles; a++) {
      
      for (int i = 0; i <= total; i++) {
        
        for (int o = 0; o <= MAX_LEDS; o++) {
          leds[o] = CRGB (0, 0, 0);
        }
    
        int initLed = INIT_LED + amount * i;
        int endLed = INIT_LED + (amount * (i +1));
        for (int o = initLed; o <= endLed; o++) {
          leds[o] = CRGB (R, G, B);
        }
        FastLED.show();
        delay(400);
    
      }
    }
}


void sidesMode(int R, int G,int B){
  int longSide = 57;
  int shortSide = 17;
  int value = 10;
  for (int i = 0; i <= value; i++) {
    
    for (int i = 0; i <= MAX_LEDS; i++) {
      leds[i] = CRGB (0, 0, 0);
    }
    for (int i = INIT_LED; i <= INIT_LED + longSide * 1 + shortSide * 0 ; i++) {
      leds[i] = CRGB (R, G, B);
    }
    FastLED.show();
    delay(400);
   
    for (int i = 0; i <= MAX_LEDS; i++) {
      leds[i] = CRGB (0, 0, 0);
    }
    FastLED.show();
    for (int i = INIT_LED + longSide * 1 + shortSide * 0; i <= INIT_LED + longSide * 1 + shortSide * 1; i++) {
      leds[i] = CRGB (R, G, B);
    }
    FastLED.show();
    delay(400);

    
  }
}

void jumpsMode(int R, int G,int B, int amount){

  int cycles = 10;

    for (int i = 0; i <= MAX_LEDS; i++) {
      
      for (int o = 0; o <= MAX_LEDS; o++) {
        leds[o] = CRGB (0, 0, 0);
      }
  
      int initLed = INIT_LED + amount * i;
      int endLed = INIT_LED + (amount * (i + 1));
      for (int o = initLed; o <= endLed; o++) {
        leds[o] = CRGB (R, G, B);
      }
      FastLED.show();
      delay(400);
  
    }
   
}

void randomColorMode(){
  int value = 10;
  for (int i = 0; i <= value; i++) {
    for (int i = INIT_LED; i <= AV_LEDS; i++) {
      int rnd = random(0,255);
      leds[i] = CRGB (rnd, rnd, rnd);
    }
    FastLED.show();
    delay(40);
  }
}

void glitchMode(){
    switchOn(255,255,255);
    delay(1000);
    switchOff(1000);
    
    switchOn(255,255,255);
    delay(100);
    switchOff(100);
    
    switchOn(255,255,255);
    delay(2000);
    switchOff(1000);
    
    switchOn(255,255,255);
    delay(100);
    switchOff(1000);
        
    switchOn(255,255,255);
    delay(50);
    switchOff(100);
        
    switchOn(255,255,255);
    delay(100);
    switchOff(100);
        
    switchOn(255,255,255);
    delay(50);
    switchOff(1000);
    
    switchOn(255,255,255);
    delay(500);
    switchOff(100);
            
    switchOn(255,255,255);
    delay(50);
    switchOff(2000);
    
    switchOn(255,255,255);
    delay(500);
    switchOff(100);
}


void glitchModeFast(){
    switchOn(255,255,255);
    delay(500);
    switchOff(500);
    
    switchOn(255,255,255);
    delay(100);
    switchOff(100);
    
    switchOn(255,255,255);
    delay(200);
    switchOff(200);
    
    switchOn(255,255,255);
    delay(100);
    switchOff(500);
        
    switchOn(255,255,255);
    delay(50);
    switchOff(100);
        
    switchOn(255,255,255);
    delay(100);
    switchOff(100);
        
    switchOn(255,255,255);
    delay(50);
    switchOff(500);
    
    switchOn(255,255,255);
    delay(100);
    switchOff(100);
            
    switchOn(255,255,255);
    delay(50);
    switchOff(1000);
    
    switchOn(255,255,255);
    delay(200);
    switchOff(100);
}


void switchOn(int R, int G,int B){
  for (int i = INIT_LED; i <= AV_LEDS; i++) {
    leds[i] = CRGB (R, G, B);
  }
  FastLED.show();
}


void switchOff(int time){
  for (int i = AV_LEDS; i > 0; i--) {
    leds[i] = CRGB (0, 0, 0);
  }
  FastLED.show();
  delay(time);
}
