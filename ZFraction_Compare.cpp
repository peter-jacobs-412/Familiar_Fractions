/*----------------------------------------------------------------------------------------------------
This file is the defintion of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include "ZFraction_Compare.h"

FracComp::FracComp() {
}

void FracComp::dispDiff1() {
  //Reformat Screen to Regular Display Mode
  format();
  //Swap to text mode
  screen.textMode();
  //Generate denominator
  char denom[2];
  int random_index = random(4.99999999);
  itoa(diff_1_denoms[random_index], denom, 10);
  Serial.println(denom);
  Serial.println(random_index);
  //enlarge text size
  screen.textEnlarge(3);
  //set cursor in upper left hand corner of left display
  screen.textSetCursor(15,40);
  screen.textTransparent(RA8875_BLACK);
  screen.textWrite(denom);
  //set cursor in upper left hand corner of right display
  screen.textSetCursor(15 + 405,40);
  screen.textTransparent(RA8875_BLACK);
  screen.textWrite(denom);
}
void FracComp::format() {
  screen.fillScreen(RA8875_WHITE);
  screen.fillRect(395, 0, 10, 480, RA8875_BLACK);
}
