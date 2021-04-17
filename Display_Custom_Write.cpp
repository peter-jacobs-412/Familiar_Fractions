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
    count++;
  }
  dispSquareGrid(denom, x_padding, y_padding, box_dim, display_num);
}
void DisplayCustomWrite::dispSquareGrid(int dimensions[], int x_padding, int y_padding, int box_dim, int display_num) {
  for (int i = 0; i < dimensions[1]; i++) {
    for (int j = 0; j < dimensions[0]; j++)
    display1.drawRect(x_padding + j * box_dim + display_num, y_padding + i * box_dim, box_dim, box_dim, RA8875_BLACK);
  }
}
void DisplayCustomWrite::getPadding(int dimensions[], int &x_padding, int &y_padding, int &box_dim) {
  //find the box dimensions
  box_dim = 395;
  while (box_dim * dimensions[0] > 365 or box_dim * dimensions[1] > 450) {
    box_dim -= 1;
  }
  Serial.println("Box dims are:");
  Serial.println(box_dim);
  //find the two paddings using the formula of (maxlength - lengthused) / 2 rounded up
  x_padding = ((395 - box_dim * dimensions[0]) / 2) + ((395 - box_dim * dimensions[0]) % 2);
  y_padding = ((480 - box_dim * dimensions[1]) / 2) + ((480 - box_dim * dimensions[1]) % 2);
  Serial.println("Xpadding is:");
  Serial.println(x_padding);
  Serial.println("Ypadding is:");
  Serial.println(y_padding);
}
// ##################################################################### //
// ###################### CIRLCE FRACTION METHODS ###################### //
// ##################################################################### //
void DisplayCustomWrite::dispCircleFrac(int numer, int denom, int display_num) {
  //calculate the angle theta of a arc that should be displayed
  double theta = 2.0 * PI * numer / denom;

  //display the whole cirle here
  display1.fillCircle(198 + display_num, 240, 180, RA8875_CYAN);

  
  //this var stores the angle at which the polar grid is supposed to start at
  //it is based upon the angle that was vut out in qudrant one(thi)
  double intial_angle;
  //call partial circle heklper to turn full cirlce into an arc
  intial_angle = partialCirleHelper(theta, display_num);

  //display the polar gird showing each single part of the denominator
  dispPolarGrid(denom, intial_angle, display_num);
}
void DisplayCustomWrite::dispPolarGrid(int steps, double intial_angle, int display_num) {
  double step_size = 2.0 * PI / steps;
  //bug testing thing here
  //display1.fillCircle(198 + 180 * cos(intial_angle) + display_num, 240 - 180 * sin(intial_angle), 10, RA8875_RED);
  for (int i = 0; i < steps; i++) {
    display1.drawLine(198 + display_num, 240, 198 + 180 * cos(i * step_size + intial_angle) + display_num, 240 - 180 * sin(i * step_size + intial_angle) , RA8875_BLACK);
  }
}
double DisplayCustomWrite::partialCirleHelper(double theta, int display_num) {
  //holds the number of quarter sections of an arc that theta has
  int whole_quads = 0;
  //finds the number of quarter sections that should be left filled and gives us our residual theta
  while (theta > (PI / 2)) {
    whole_quads ++;
    theta -= PI / 2;
  }

  //this is also reffered to as the angle of cut
  double thi = PI/2 - theta;

  //This section is used to cutout the right angle from the first quadrant
  //THI LIMIT is the max angle we can cut out of the first quadrant with a triagnle 
  //before the math for the 3rd point would try and place it off the screen and thus cause errors
  if (thi < THI_LIMIT) {
    //in this case all we need is one cutout which is ezpz
    Serial.println("trigger1");
    display1.fillTriangle(198 + display_num, 240, 378 + display_num, 240, 378 + display_num, 240 - 180 * tan(thi), RA8875_WHITE);
  } else if (thi > THI_LIMIT) {
    Serial.println("trigger2");
    //this is the double triangle case in which we create the cutout by using two triangles instead of just one
    display1.fillTriangle(198 + display_num, 240, 378 + display_num, 240, 378 + display_num, 0, RA8875_WHITE);
    //the second triagnle shares its diagnol with the first and has a static 
    //first(orgin) and second point(where first triangle intersect cirlce) 
    //with its third point being dependent on theta
    display1.fillTriangle(198 + display_num, 240, 306 + display_num, 96, 198 + 240 * tan(theta) + display_num, 0, RA8875_WHITE);
  }

  //in this case we cover up everything but the first quadrant
  if (whole_quads == 0) {
    //cover up quad 4
    //this draws a rectangle with upperleft hand corner at orgin with size = r
    display1.fillRect(198 + display_num, 240, 180, 180, RA8875_WHITE);
    //cover up quad 3
    //this draws a rectangle with upperleft hand corner at location of theta = pi with size = r
    display1.fillRect(18 + display_num, 240, 180, 180, RA8875_WHITE);
    //cover up quad 2 
    //this draws a rectangle with upper left location of 180 px away in both directions from the orgin with size = r
    display1.fillRect(18 + display_num, 60, 180, 180, RA8875_WHITE);
  }
  //in this case we cover up everything except for the 1st and 2nd quadrant
  else if (whole_quads == 1) {
    //cover up quad 4
    //this draws a rectangle with upperleft hand corner at orgin with size = r
    display1.fillRect(198 + display_num, 240, 180, 180, RA8875_WHITE);
    //cover up quad 3
    //this draws a rectangle with upperleft hand corner at location of theta = pi with size = r
    display1.fillRect(18 + display_num, 240, 180, 180, RA8875_WHITE);
  }
  //in this case we only cover up the 4th quadrant
  else if (whole_quads == 2) {
    //cover up quad 4
    //this draws a rectangle with upperleft hand corner at orgin with size = r
    display1.fillRect(198 + display_num, 240, 180, 180, RA8875_WHITE);
  }
  //return the angle at which the fraction starts, which is equal to our angle of cut
  return (thi);
}
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
