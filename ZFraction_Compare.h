/*----------------------------------------------------------------------------------------------------
This file is the Header of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include "Display_Custom_Write.h"



class FracComp {
  private:
    DisplayCustomWrite screen = DisplayCustomWrite();
    //used to store the possibilities that a diffculty 1 denominator could take on
    int diff_1_denoms[4] = {2,3,4,5};

  public:
    FracComp();
    //displays a diffculty one problem
    void dispDiff1();
    //used to create acceptable numerators for a fraction problem
    void makeNumer(int &numer1, int &numer, int denom1, int denom2);
    //used to automatically display a fraction given a numerator and a denominator and given either left or right as its inputs
    //void dispFrac(int numerator, int denominator, int display_number);
};
