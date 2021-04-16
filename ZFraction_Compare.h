/*----------------------------------------------------------------------------------------------------
This file is the Header of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------
Diffuculties of fractions will be given as either 1 2 or 3 with (easy, medium, hard)
the diffculty counter will be a 2x1 array that stores 
the current diffculty level and the versus level
the versus level ranges from values 1-4 and goes from 
frac-frac frac-square frac-cirlce circle-square
------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include "Display_Custom_Write.h"



class FracComp {
  private:
    DisplayCustomWrite screen = DisplayCustomWrite();
    //used to store the possibilities that a diffculty 1 denominator could take on
    int diff_1_denoms[5] = {2,3,4,5, 6};
    //stores the pin values for the two buttons
    int left_button;
    int right_button;
  public:
    FracComp(int left_pin, int right_pin);
    //displays a diffculty one problem
    void dispDiff1_1();
    //used to create acceptable numerators for a fraction problem
    void makeNumer(int &numer1, int &numer, int denom1, int denom2);
    //evaluates whether the user got the answer correct
    void evalAnswer(int numer1, int numer2, int denom1, int denom2);
    //used to test things
    void testerFunc();
    void dispDiff_1_2();
};
