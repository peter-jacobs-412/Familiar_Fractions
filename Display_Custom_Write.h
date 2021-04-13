#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"

//these constans are defined this way in order to properly shift when we want to display text to the right side of the screen. since bar is 10u wide and starts at 395 the Right display starts at 405 therefor right = 405

class DisplayCustomWrite {
  private:
    Adafruit_RA8875 display1 = Adafruit_RA8875(10, 9);
    char fraction_line_1[2] = {"-"};
    char fraction_line_2[3] = {"--"};
    char fraction_line_3[4] = {"---"};
  public:
    DisplayCustomWrite();
    void disp_1_DigitFrac(int numer, int denom, int display_num);
    void disp_2_DigitFrac(int numer, int denom, int display_num);
    void disp_3_DigitFrac(int numer, int denom, int display_num);
    void formatCompare();
    void dispFrac(int numer, int denom, int display_num);
};
