#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include "ZFraction_Compare.h"

// ====================================================== //
// =================== PIN DEFINITIONS ================== //
// ====================================================== //
//Button 1 and 2 are the two buttons that are on our board below the display 
//each corelating to one hafl of the dispay with button 1 on the left and button 2 on the right
#define BUTTONLEFT 22
#define BUTTONRIGHT 23
//Pins here are defined as part of the adafruit RA8875 driver board
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9
//This pin is used to send singles to the protobit and control the littlebit
#define PROTO_BIT 25
//Pin 13 is onboard LED
#define ON_BOARD_LED 13
//starts the display
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);

FracComp compare = FracComp(BUTTONLEFT, BUTTONRIGHT);

void setup() {
  //declaring pins used noy by the display
  pinMode(BUTTONLEFT, INPUT_PULLUP);
  pinMode(BUTTONRIGHT, INPUT_PULLUP);
  pinMode(PROTO_BIT, OUTPUT);
  pinMode(ON_BOARD_LED, OUTPUT);
  //intializing rand seed
  randomSeed(300);

  //start serial terminal
  Serial.begin(9600);
  //set up display
  Serial.println("RA8875 start");
  
  /* Initialize the display using 'RA8875_480x80', 'RA8875_480x128', 'RA8875_480x272' or 'RA8875_800x480' */
  if (!tft.begin(RA8875_800x480)) {
    Serial.println("RA8875 Not Found!");
    while (1);
  }

  Serial.println("Found RA8875");

  tft.displayOn(true);
  tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
  tft.PWM1out(255);
  //fill screen white
  tft.fillScreen(RA8875_WHITE);
}

void loop() {
  compare.dispDiff1();
  delay(5000);
  
}
