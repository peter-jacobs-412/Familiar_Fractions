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

//these constans are defined this way in order to properly shift when we want to display text to the right side of the screen. since bar is 10u wide and starts at 395 the Right display starts at 405 therefor right = 405
#define LEFT 0
#define RIGHT 405

FracComp::FracComp() {
}

void FracComp::dispDiff1() {
  //generate random index between 0 and 4
  int rand_index = random(4.9999999);
  Serial.println("rand index");
  Serial.println(rand_index);
  //later will need to figure out how to do numerator
  int left_numerator = 1;
  int right_numerator = 3;
  
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_1_denoms[rand_index];
  Serial.println("Denom:");
  Serial.println(denominator);
  //reformat and print the fractions to the screen
  format();
  dispFrac(left_numerator, denominator, LEFT);
  dispFrac(right_numerator, denominator, RIGHT);

  
  //this is how to function was previously written dont want to delte just yet but now with dispFrac it shouldnt be needed
  /*//Reformat Screen to Regular Display Mode
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
  screen.textWrite(denom);*/
}
void FracComp::format() {
  screen.graphicsMode();//this might be wrong need to look at library
  screen.fillScreen(RA8875_WHITE);
  screen.fillRect(395, 0, 10, 480, RA8875_BLACK);
}

void FracComp::dispFrac(int numerator, int denominator, int display_number) {
  //taking numerator and denominator and converting them to strings
  Serial.println("Fraction:");
  char numerator_char[3];
  char denominator_char[3];
  itoa(numerator, numerator_char, 10);
  itoa(denominator, denominator_char, 10);
  //string that stores our fraction line
  char fraction_line[6] = {"-----"};
  //intializing display for text and setting it size to 5
  screen.textMode();
  screen.textEnlarge(5);
  /*display will look like this things are given in (width, height)
   *            space (400px, 100px)
   * space(150px,75px) numerator(95px,75px) space(150px,75px)
   * space(150px,50px) Fraction line(95px,50px) space(150px,50px)
   * space(150px,75px) denominator(95px,75px) space(150px,75px)
   *            space (400px, 100px)
   */
   //Numerator
   screen.textSetCursor(150 + display_number, 100);
   screen.textTransparent(RA8875_BLACK);
   screen.textWrite(numerator_char);
   Serial.println(numerator_char);
   //Fraction line
   screen.textSetCursor(150 + display_number, 195);
   screen.textTransparent(RA8875_BLACK);
   screen.textWrite(fraction_line);
   //Serial.println(fraction_line);
   //Denominator
   screen.textSetCursor(150 + display_number, 245);
   screen.textTransparent(RA8875_BLACK);
   screen.textWrite(denominator_char);
   Serial.println(denominator_char);
}
