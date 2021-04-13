#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include "Display_Custom_Write.h"

DisplayCustomWrite::DisplayCustomWrite() {

}
void DisplayCustomWrite::disp_1_DigitFrac(int numer, int denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char numer_char[4];
  char denom_char[4];
  itoa(numer, numer_char, 10);
  itoa(denom, denom_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //display numerator
  display1.textSetCursor(150 + display_num, 100);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(numer_char);
  
  //display fraction line
  display1.textSetCursor(150 + display_num, 195);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(fraction_line_1);
  
  //display denominator
  display1.textSetCursor(150 + display_num, 245);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(denom_char);
}
void DisplayCustomWrite::disp_2_DigitFrac(int numer, int denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char numer_char[4];
  char denom_char[4];
  itoa(numer, numer_char, 10);
  itoa(denom, denom_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //display numerator
  display1.textSetCursor(150 + display_num, 100);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(numer_char);
  
  //display fraction line
  display1.textSetCursor(150 + display_num, 195);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(fraction_line_2);

  display1.textSetCursor(150 + display_num, 245);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(denom_char);
}
void DisplayCustomWrite::disp_3_DigitFrac(int numer, int denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char numer_char[4];
  char denom_char[4];
  itoa(numer, numer_char, 10);
  itoa(denom, denom_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //display numerator
  display1.textSetCursor(150 + display_num, 100);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(numer_char);

  //display fraction line
  display1.textSetCursor(150 + display_num, 195);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(fraction_line_3);

  //display denominator
  display1.textSetCursor(150 + display_num, 245);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(denom_char);
}
void DisplayCustomWrite::formatCompare() {
  display1.graphicsMode();//this might be wrong need to look at library
  display1.fillScreen(RA8875_WHITE);
  display1.fillRect(395, 0, 10, 480, RA8875_BLACK);
}
void DisplayCustomWrite::dispFrac(int numer, int denom, int display_num) {
  if (numer < 10 and denom < 10) {
    disp_1_DigitFrac(numer, denom, display_num);
  }
  else if (numer < 100 and denom < 100) {
    disp_2_DigitFrac(numer, denom, display_num);
  }
  else if (numer < 1000 and denom < 1000) {
    disp_3_DigitFrac(numer, denom, display_num);
  }
  else {
    Serial.println("ERROR FRAC TO BIG");
  }
}
