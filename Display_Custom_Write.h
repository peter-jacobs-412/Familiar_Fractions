#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

//This class is used to have a standard set of functions used to display frractions in difrent formats to the screen
class DisplayCustomWrite {
  private:
    //this is the local object that is used to write to the display
    //Note that as long as the two CS and RST pins are the same here then all the setup done in main will transfer over
    Adafruit_RA8875 display1 = Adafruit_RA8875(10, 9);
    //these three varibles store the chracter sequence used to represent a fraction line
    char fraction_line_1[2] = {"-"};
    char fraction_line_2[3] = {"--"};
    char fraction_line_3[4] = {"---"};
    //stores the height at which the numerator is diplayed in a fraction
    int numer_height;
    //stores the hieght of the fraciton line in fractions
    int frac_line_height= 195;
    //stores the height at which the denominator is displayed
    int denom_height;
    //this stores the diffrent allignemnt values that are used to properly center a fractions
    //it goes in the order of 1,2,3 digit alignment values
    int hori_alignments[3] = {180, 162, 144};
  public:
    //Constructor--Curently nothing is done here, 
    //likely once speaker integration is done it might need to recieve the speaker pin
    //it could also recieve the pins used for RST and CS for the display in main, but not nesecary
    DisplayCustomWrite();

    //this is used to display a fraction as a square, 
    //the denominator is given as a two dimensiaonal vector since it is the product of the dimensions of the sqaure
    void dispSquareFrac(int numer, int denom[], int display_num);
    //this function is used to display the grid that goes over the Sqaure fraction display
    void dispSquareGrid(int dimensions[], int x_padding, int y_padding, int box_dim, int display_num);
    //this functioned is used by the two functions above and is used to find how to postion to sqaure frac
    void getPadding(int dimensions[], int &x_padding, int &y_padding, int &box_dim);

    void dispCircleFrac(int numer, int denom, int display_num);
    void dispPolarGrid(int denom, int display_num);
    void partialCirleHelper(double theta, int display_num);
    //These functions display N digits that is properly centered based on display num,
    //and whether its supposed to be numerator or denominator
    void disp_1_Digit(int number, bool num_or_denom, int display_num);
    void disp_2_Digit(int number, bool num_or_denom, int display_num);
    void disp_3_Digit(int number, bool num_or_denom, int display_num);

    //this is used to display a frac line based upon the max amount of digits in a fraction
    void dispFracLine(int digits, int display_num);

    //this formats the screen for a compare problem
    void formatCompare();

    //this displays a numerical fraction given a display num a numerator and a denominator
    void dispFrac(int numer, int denom, int display_num);

    //displays to the user that they got the problem right
    void dispCorrect();

    //displays to the user they got the problem wrong
    void dispWrong();
};
