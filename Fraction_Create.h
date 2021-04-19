#include <Arduino.h>
#include "Display_Custom_Write.h"



class FracCreate {
  private:
    DisplayCustomWrite screen = DisplayCustomWrite();
    //used to store the possibilities that a diffculty 1 denominator could take on
    int diff_1_denoms[5] = {2,3,4,5, 6};
    int diff_2_denoms[9]={3,5,6,7,8,9,10,11,12};
    //stores the pin values for the two buttons
    int left_button;
    int right_button;
    int slider;
    int clk;
    int dt;
    int encoderVal;
  public:
    FracCreate(int clk_pin, int dt_pin, int slider_pin, int left_pin, int right_pin)
    //displays a diffculty one problem
    void dispDiff1_1();
    void dispDiff1_2();
    //used to create acceptable numerators for a fraction problem
    //evaluates whether the user got the answer correct
    void evalAnswer(bool isSlider, int numerator, int denominator);
    double getUserGuess(bool isSlider)
    void measureEncoder();
};