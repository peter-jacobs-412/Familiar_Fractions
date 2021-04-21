#include <Arduino.h>
#include "Display_Custom_Write.h"



class FracCreate {
  private:
    DisplayCustomWrite screen = DisplayCustomWrite();
    //used to store the possibilities that a diffculty 1 denominator could take on
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
    int slider;
    int clk;
    int dt;
    int encoderVal;
    int denominator;
  public:
    FracCreate(int clk_pin, int dt_pin, int slider_pin, int left_pin, int right_pin);
    //displays a diffculty one problem
    void dispDiff1_1();
    void dispDiff1_2();
    void dispDiff1_3();
    void dispDiff1_4();
    void dispDiff1_5();
    void dispDiff1_6();
    void dispDiff2_1();
    void dispDiff2_2();
    void dispDiff2_3();
    void dispDiff2_4();
    void dispDiff2_5();
    void dispDiff2_6();
    void dispDiff3_1();
    void dispDiff3_2();
    void dispDiff3_3();
    void dispDiff3_4();
    void dispDiff3_5();
    void dispDiff3_6();
    
    //used to create acceptable numerators for a fraction problem
    //evaluates whether the user got the answer correct
    void evalAnswer(bool isSlider, int numerator, int denominator);
    double getUserGuess(bool isSlider);
    void measureEncoder();
};
