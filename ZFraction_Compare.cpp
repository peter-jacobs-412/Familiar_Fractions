/*----------------------------------------------------------------------------------------------------
This file is the defintion of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include "ZFraction_Compare.h"

#define LEFT 0
#define RIGHT 405


FracComp::FracComp() {
}

void FracComp::dispDiff1() {
  //generate random index between 0 and 4
  int rand_index = random(4);
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int left_numerator = 1;
  int right_numerator = 3;
  //genrate the numerators
  //Function is currently bugged will bug fix when i have the chance
  //makeNumer(left_numerator, right_numerator, denominator, denominator);

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, denominator, LEFT);
  screen.dispFrac(right_numerator, denominator, RIGHT);
}
void FracComp::makeNumer(int &numer1, int &numer2, int denom1, int denom2) {
  //make random numerators
  numer1 = random(0, denom1 + 1);
  numer2 = random(0, denom2 + 1);
  //calculate the fraction that is created
  double frac1 = (numer1 * 1.0) / (denom1 * 1.0);
  double frac2 = (numer1 * 1.0) / (denom1 * 1.0);
  //if the fractions are equal regenrate the numerators
  //**** ADD THIS LATER or if their ratio is greater than upper limit or lower than lower limit then re generate
  while(frac1 == frac2) {
    //make random numerators
    numer1 = random(0, denom1 + 1);
    numer2 = random(0, denom2 + 1);
    //calculate the fraction that is created
    frac1 = (numer1 * 1.0) / (denom1 * 1.0);
    frac2 = (numer2 * 1.0) / (denom2 * 1.0);
  }
}


/*void FracComp::dispFrac(int numerator, int denominator, int display_number) {
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
}*/
