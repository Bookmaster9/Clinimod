#include <FastLED.h>
#define NUM_LEDS 3
#define DATA_PIN 26
#define BUTTON_ONE 25
#define BUTTON_TWO 33
CRGB leds[NUM_LEDS];
long currentMillis = 0;
bool OnePressed = false;
bool TwoPressed = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(BUTTON_ONE, INPUT);
  pinMode(BUTTON_TWO, INPUT);
  FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  FastLED.setBrightness(84);
}

void loop() {
  // put your main code here, to run repeatedly:

  while (currentMillis < 10000){
    currentMillis = millis();
    leds[0] = CRGB(255,0,0);
    leds[1] = CRGB(255,0,0);
    leds[2] = CRGB(255,0,0);
    FastLED.show();
    Serial.println(currentMillis/1000);
  }
  if (digitalRead(BUTTON_ONE) == 1){
    OnePressed = true;
  }
  if (digitalRead(BUTTON_TWO) == 1){
    TwoPressed = true;
  }
  if (OnePressed == true && digitalRead(BUTTON_ONE) == 0){
    leds[2] = CRGB(0,255,0);
  }
  if (TwoPressed == true && digitalRead(BUTTON_TWO) == 0){
    leds[0] = CRGB(0,255,0);
  }
  //Serial.println("button one: ");
  //Serial.print(digitalRead(BUTTON_ONE));
  //Serial.println(OnePressed);
  //Serial.println("");
  //Serial.println("button two:");
  //Serial.print(digitalRead(BUTTON_TWO));
  //Serial.println(TwoPressed)
  //Serial.println("");
 // delay(200);
  FastLED.show();
}
