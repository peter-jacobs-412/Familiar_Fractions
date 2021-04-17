/*----------------------------------------------------------------------------------------------------
This file is the Header of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------
the diffculty counter will be a 2x1 array that stores
Diffuculties of fractions (P)
  will be given as either 1 2 or 3 with (easy, medium, hard)
And the versus level (V)
 ranges from 1-6 with 
 1 Numerical vs Numerical
 2 Numerical vs Square
 3 Numerical vs Circle
 4 Square vs Square
 5 Circle vs Circle
 6 Cricle vs Square
EX: diffculty of {1,3} gives an easy numerical vs circle problem
EX: diffculty of {2,6} gives an Medium Circle vs Square problem

the general formula for the names of the functions that call these diffrent diffculties is
dispDiff_P_V(); -- these functions dont require any inputs
------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include "Display_Custom_Write.h"



class FracComp {
  private:
    DisplayCustomWrite screen = DisplayCustomWrite();
    //these three arrays are used to store the possibilities that a,
    //diffculty 1 2 or 3 denominator could take on (Cirlce and Square only).
    //accpeted values for diff 1 are 2-6
    int diff_1_denoms[5] = {2,3,4,5,6};
    //accepted values for diff 2 are 3,5-12
    int diff_2_denoms[9] = {3,5,6,7,7,9,10,11,12};
    //accepted values for diff 3 are 11-25
    int diff_3_denoms[15] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    /*these are the denomiantors that can be displayed in a square fashion of diffculty 1, 2, or 3
    these operator as a list of dimensions with each denominator residing in a specific column .
    EX denominator 3 = diff[0][2]*diff[1][2]
    //                     x-dim     y-dim
    note here that we always want the y dimension to be the larger of the two values*/
    //for diff 1 we will use denoms of 3,4,6,8
    int diff_1_sq[2][4] = {
      {1,2,2,2},  //x dimsension
      {3,2,3,4}   //correseponding y dimesnion
    };
    //for diff 2 we will use 3,4,6,8,9,10,12,16
    int diff_2_sq[2][8] = {
      {1,2,2,2,3,2,3,4},  //x dimsension
      {3,2,3,4,3,5,4,4}   //correseponding y dimesnion
    };
    //for diff 3 we will use 9,12,16,24,25,28,30,42,54
    int diff_3_sq[2][9] = {
      {3,3,4,4,5,4,5,6,6}, //x dimensions
      {3,4,4,6,5,7,6,7,9}  //corresponding y dimensions
    };

    //stores the pin values for the two buttons
    int left_button;
    int right_button;
  public:
    //constructor that intializes the button pins and uses sets them to INPUT_PULLUP
    FracComp(int left_pin, int right_pin);

    //used to create acceptable numerators for a fraction problem, such that the fractions arent equal
    //also at somepoint we could make sure the fractions are within in some given range of eachother
    void makeNumer(int &numer1, int &numer, int denom1, int denom2);

    //evaluates whether the user got the answer correct and, 
    //calls the aproaite functions to communicaten that to the user (Display and Audio)
    void evalAnswer(int numer1, int numer2, int denom1, int denom2);

    //used to test things
    void testerFunc();

    //these are the 3 vs level 1 problems (Numerical Vs Numerical)    
    void dispDiff_1_1();
    void dispDiff_2_1();
    void dispDiff_3_1();

    //these are the 3 vs level 1 problems (Numerical Vs Square) 
    void dispDiff_1_2();
    void dispDiff_2_2();
    void dispDiff_3_2();

    //these are the 3 vs level 1 problems (Numerical Vs Circle) 
    void dispDiff_1_3();
    void dispDiff_2_3();
    void dispDiff_3_3();

    //these are the 3 vs level 4 problems (Square Vs Square)
    void dispDiff_1_4();
    void dispDiff_2_4();
    void dispDiff_3_4();

    //these are the 3 vs level 5 problems (Circle Vs Circle)
    void dispDiff_1_5();
    void dispDiff_2_5();
    void dispDiff_3_5();

    //these are the 3 vs level 6 problems (Circle Vs Square)
    void dispDiff_1_6();
    void dispDiff_2_6();
    void dispDiff_3_6();
};
