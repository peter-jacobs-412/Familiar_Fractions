#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include "ZFraction_Compare.h"
#include "Fraction_Create.h"

// ====================================================== //
// =================== PIN DEFINITIONS ================== //
// ====================================================== //
//Button 1 and 2 are the two buttons that are on our board below the display 
//each corelating to one hafl of the dispay with button 1 on the left and button 2 on the right
#define BUTTONLEFT 22
#define BUTTONRIGHT 23

//ROTARY ENCODE PINS
#define ROTARY_CLK 46
#define ROTARY_DT 47
#define SLIDER A8

//Pins here are defined as part of the adafruit RA8875 driver board
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9


//Pin 13 is onboard LED
#define ON_BOARD_LED 13

//declares the display
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
FracCreate create=FracCreate(ROTARY_CLK,ROTARY_DT,SLIDER,BUTTONLEFT,BUTTONRIGHT);
//FracComp compare = FracComp(BUTTONLEFT, BUTTONRIGHT);

void setup() {
  //intializing the button pins
  pinMode(BUTTONLEFT, INPUT_PULLUP);
  pinMode(BUTTONRIGHT, INPUT_PULLUP);

  pinMode(ON_BOARD_LED, OUTPUT);
  
  //intialzing the rotary encode pins
  pinMode(ROTARY_CLK, INPUT);
  pinMode(ROTARY_DT,INPUT);
  pinMode(SLIDER,INPUT_PULLUP);

  
  //intializing rand seed
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
  //create.dispDiff1_1();
  //delay(2500);
  create.dispDiff1_2();
  delay(2500);
  //testing V=1
  compare.dispDiff_1_1();
  delay(2500);
  compare.dispDiff_2_1();
  delay(2500);
  compare.dispDiff_3_1();
  delay(2500);
  //testing V=2
  compare.dispDiff_1_2();
  delay(2500);
  compare.dispDiff_2_2();
  delay(2500);
  compare.dispDiff_3_2();
  delay(2500);
  //testing v=3
  compare.dispDiff_1_3();
  delay(2500);
  compare.dispDiff_2_3();
  delay(2500);
  compare.dispDiff_3_3();
  delay(2500);
  //testing v=4
  compare.dispDiff_1_4();
  delay(2500);
  compare.dispDiff_2_4();
  delay(2500);
  compare.dispDiff_3_4();
  delay(2500);
  //testing v=5
  compare.dispDiff_1_5();
  delay(2500);
  compare.dispDiff_2_5();
  delay(2500);
  compare.dispDiff_3_5();
  delay(2500);
  //testing V=6
  compare.dispDiff_1_6();
  delay(2500);
  compare.dispDiff_2_6();
  delay(2500);
  compare.dispDiff_3_6();
  delay(2500);
  //compare.testerFunc();
}
