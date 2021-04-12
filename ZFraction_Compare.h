/*----------------------------------------------------------------------------------------------------
This file is the Header of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"


class FracComp {
  private:
    Adafruit_RA8875 screen = Adafruit_RA8875(10, 9);
    //used to store the possibilities that a diffculty 1 denominator could take on
    int diff_1_denoms[5] = {1,2,3,4,5};
  public:
    FracComp();
    //displays a diffculty one problem
    void dispDiff1();
    //takes the screen and reformats it Filling with white and then drawing divider line
    void format();
    //used to automatically display a fraction given a numerator and a denominator and given either left or right as its inputs
    void dispFrac(int numerator, int denominator, int display_number);
};
