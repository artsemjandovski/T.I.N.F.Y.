#include <FastLED.h>
#include <GyverButton.h>

#define but_pin 12
#define data_led 13
#define col_mode 3
#define led_count 5
GButton but(but_pin);
byte mode;
struct CRGB leds[led_count];
void one_color_all(int cred, int cgrn, int cblu) {
  for (int i = 0 ; i < led_count; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(data_led, OUTPUT);
  
}

void loop() {
  but.tick();
  byte pressnum;
  if(but.hasClicks()){
    pressnum = but.getClicks();
    if(pressnum == 1){
      mode = ++mode%col_mode;
    }else if(pressnum == 2) mode = --mode - 255 + col_mode - 1;
  }
  switch (mode) {
    case 0:
      one_color_all(0, 0, 0); LEDS.show();
    break;
    case 1:
      one_color_all(255, 255, 255); LEDS.show(); break;
    break;
    case 2:
      one_color_all(255, 0, 0); LEDS.show(); break;
    break;
  }
}
