#include <Arduino.h>
#include "Adafruit_GFX.h"
#include "Adafruit_RA8875.h"
#include "Display_Custom_Write.h"

//SUPER INMPORTANT NOTE TEXT SIZE OF 3 MEANS A CHARACTER IS 36 PIXELS WIDE AND 44 PIXELS TALL
DisplayCustomWrite::DisplayCustomWrite() {

}

// ##################################################################### //
// ########### N DIGIT NUMERICAL FRACTION DISPLAY FUNCTIONS ############ //
// ##################################################################### //
void DisplayCustomWrite::disp_1_Digit(int number, bool num_or_denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char number_char[4];
  itoa(number, number_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //set display height based on if its numerator or denominator
  int height;
  if(num_or_denom == true) {
    height = 145;
  } else {
    height = 245;
  }

  //display number at given postion
  display1.textSetCursor(180 + display_num, height); //this has been aporiatley horizontally centterted
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(number_char);
}
void DisplayCustomWrite::disp_2_Digit(int number, bool num_or_denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char number_char[4];
  itoa(number, number_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //set display height based on if its numerator or denominator
  int height;
  if(num_or_denom == true) {
    height = 145;
  } else {
    height = 245;
  }
  
  //display number at given postion
  display1.textSetCursor(162 + display_num, height); //The 150 here is the horizontal offset that needs to be calculated
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(number_char);
}
void DisplayCustomWrite::disp_3_Digit(int number, bool num_or_denom, int display_num) {
  //Converting the numbers into strings that can be displayed
  char number_char[4];
  itoa(number, number_char, 10);

  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);

  //set display height based on if its numerator or denominator
  int height;
  if(num_or_denom == true) {
    height = 145;
  } else {
    height = 245;
  }

  //display number at given postion
  display1.textSetCursor(144 + display_num, height); //The 150 here is the horizontal offset that needs to be calculated
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite(number_char);
}
// ##################################################################### //
// ########################## FORMAT FUNCTIONS ######################### //
// ##################################################################### //
void DisplayCustomWrite::formatCompare() {
  //this formats the screen as white with a 10px wide black divider bar in the middle
  display1.graphicsMode();
  display1.fillScreen(RA8875_WHITE);
  display1.fillRect(395, 0, 10, 480, RA8875_BLACK);
}
// ##################################################################### //
// ################# OTHER NUMERICAL FRACTION FUNCTIONS ################ //
// ##################################################################### //
void DisplayCustomWrite::dispFracLine(int digits, int display_num) {
  //swap to text mode and put text at the largest possible size
  display1.textMode();
  display1.textEnlarge(3);
  //display fraction line given digits
  if(digits == 1) {
    display1.textSetCursor(180 + display_num, 195);
    display1.textTransparent(RA8875_BLACK);
    display1.textWrite(fraction_line_1);
  } else if (digits == 2) {
    display1.textSetCursor(162 + display_num, 195);
    display1.textTransparent(RA8875_BLACK);
    display1.textWrite(fraction_line_2);
    //This is added here in order to have it display one contious line, by overlaying a single and double well have that
    display1.textSetCursor(180 + display_num, 195);
    display1.textTransparent(RA8875_BLACK);
    display1.textWrite(fraction_line_1);
  } else if (digits == 3) {
    display1.textSetCursor(144 + display_num, 195);
    display1.textTransparent(RA8875_BLACK);
    display1.textWrite(fraction_line_3);
    //This is added here in order to have it display one contious line overlaying a triple and double will do so
    display1.textSetCursor(162 + display_num, 195);
    display1.textTransparent(RA8875_BLACK);
    display1.textWrite(fraction_line_2);
  } else {
    Serial.println("ERROR FRAC TO BIG");
  }
}
void DisplayCustomWrite::dispFrac(int numer, int denom, int display_num) {
  if (numer < 10) {
    //display numerator with 1 digit
    disp_1_Digit(numer, true, display_num);
    //display the denominator with the correct number of digits
    //since numer only has 1 digit in this chain the fraction line is dependent only on the denominator
    if (denom < 10) {
      dispFracLine(1, display_num);
      disp_1_Digit(denom, false, display_num);
    }
    else if (denom < 100) {
      dispFracLine(2, display_num);
      disp_2_Digit(denom, false, display_num);
    }
    else if (denom < 1000) {
      dispFracLine(3, display_num);
      disp_3_Digit(denom, false, display_num);
    }
    else {
      Serial.println("ERROR FRAC TO BIG");
    }
  }

  else if (numer < 100) {
    //display numerator with 2 digits
    disp_2_Digit(numer, true, display_num);
    //display the denominator with the correct number of digits
    //since numer has 2 digits frac line is 2 for all but a denom of 3 digits
    if (denom < 10) {
      dispFracLine(2, display_num);
      disp_1_Digit(denom, false, display_num);
    }
    else if (denom < 100) {
      dispFracLine(2, display_num);
      disp_2_Digit(denom, false, display_num);
    }
    else if (denom < 1000) {
      dispFracLine(3, display_num);
      disp_3_Digit(denom, false, display_num);
    }
    else {
      Serial.println("ERROR FRAC TO BIG");
    }
  }

  else if (numer < 1000) {
    //display numerator with 3 digits
    disp_3_Digit(numer, true, display_num);
    //since numer has 3 digits the frac line will always be 3 so we will move it outside of the if else chain for denom size
    dispFracLine(3, display_num);
    //display the denominator with the correct number of digits
    if (denom < 10) {
      disp_1_Digit(denom, false, display_num);
    }
    else if (denom < 100) {
      disp_2_Digit(denom, false, display_num);
    }
    else if (denom < 1000) {
      disp_3_Digit(denom, false, display_num);
    }
    else {
      Serial.println("ERROR FRAC TO BIG");
    }
  }

  else {
    Serial.println("ERROR FRAC TO BIG");
  }
}
// ##################################################################### //
// ###################### SQAURE FRACTION METHODS ###################### //
// ##################################################################### //
void DisplayCustomWrite::dispSquareFrac(int numer, int denom[], int display_num) {
  //this holds the padding between the fraction being displayed and the left edge of the screen
  int x_padding;
  //this holds the padding between the fraction being displayed and the top of the screen
  int y_padding;
  //this holds this size of the each box IE one numerator
  int box_dim;
  //find the padding and individual element size
  getPadding(denom, x_padding, y_padding, box_dim);
  //display the fraction
  int count = 0;
  int i = 0;
  int j = 0;
  while (count < numer) {
    display1.fillRect(x_padding + j * box_dim + display_num, y_padding + i * box_dim, box_dim, box_dim, RA8875_GREEN);
    j++;
    if (j == denom[0]) {j = 0; i++;}
  }
  dispSquareGrid(denom, x_padding, y_padding, box_dim, display_num);
}
void DisplayCustomWrite::dispSquareGrid(int dimensions[], int x_padding, int y_padding, int box_dim, int display_num) {
  for (int j = 0; j < dimensions[1]; j++) {
    for (int i = 0; i < dimensions[0]; i++)
    display1.drawRect(x_padding + j * box_dim + display_num, y_padding + i * box_dim, box_dim, box_dim, RA8875_BLACK);
  }
}
void DisplayCustomWrite::getPadding(int dimensions[], int &x_padding, int &y_padding, int &box_dim) {
  //find the box dimensions
  box_dim = 395;
  while (box_dim * dimensions[0] > 395 and box_dim * dimensions[1] > 400) {
    box_dim -= 5;
  }
  //find the two paddings using the formula of (maxlength - lengthused) / 2 rounded up
  x_padding = ((395 - box_dim * dimensions[0]) / 2) + ((395 - box_dim * dimensions[0]) % 2);
  y_padding = ((400 - box_dim * dimensions[1]) / 2) + ((400 - box_dim * dimensions[0]) % 2);
}
// ##################################################################### //
// ###################### CIRLCE FRACTION METHODS ###################### //
// ##################################################################### //

// ##################################################################### //
// ############## CORRECT AND INCORRECT DISPLAY FUNCTIONS ############## //
// ##################################################################### //
void DisplayCustomWrite::dispCorrect() {
  display1.graphicsMode();
  display1.fillScreen(RA8875_GREEN);
  display1.textMode();
  display1.textEnlarge(3);
  display1.textSetCursor(85, frac_line_height);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite("That Was Correct!!");
  
}
void DisplayCustomWrite::dispWrong() {
  display1.graphicsMode();
  display1.fillScreen(RA8875_RED);
  display1.textMode();
  display1.textEnlarge(3);
  display1.textSetCursor(85, frac_line_height);
  display1.textTransparent(RA8875_BLACK);
  display1.textWrite("That Was Incorrect");
}
