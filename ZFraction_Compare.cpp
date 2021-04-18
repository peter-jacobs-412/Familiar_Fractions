/*----------------------------------------------------------------------------------------------------
This file is the defintion of the class FracCompare, this is what handles the generating and checking 
input of the comparing 2 fractions questions.It will be sent pins in its Creator and Send back if the 
used was correct in the destructor. It will also need to be given the current diffculty count, but will
have all the rules for diffculty stored inside of its self.  
----------------------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include "ZFraction_Compare.h"

#define LEFT 0
#define RIGHT 405

//Construtor
FracComp::FracComp(int left_pin, int right_pin) {
  left_button = left_pin;
  right_button = right_pin;
  pinMode(left_button, INPUT_PULLUP);
  pinMode(right_button, INPUT_PULLUP);
}

// ##################################################################### //
// ################ VERSUS LEVEL 1 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_1() {
  //getting denominator from the list of accepted denoms using a random index value from 0 - length of array
  //-- note that the max index of an array is length - 1 but since random generates a double and thats trucated,
  //into and integer we will never get a value = length of array for the index since that would cause a problem,
  //by being to big
  int left_denominator = diff_1_denoms[random(5)];
  int right_denominator = diff_1_denoms[random(5)];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, left_denominator, right_denominator);

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  screen.dispFrac(right_numerator, right_denominator, RIGHT);

  //evaluate the useres answer
  evalAnswer(left_numerator, right_numerator, left_denominator, right_denominator);
}
void FracComp::dispDiff_2_1() {
  //generate the random denominators based upon the accepted values for this diffculty
  int left_denominator = diff_2_denoms[random(9)];
  int right_denominator = diff_2_denoms[random(9)];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, left_denominator, right_denominator);

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  screen.dispFrac(right_numerator, right_denominator, RIGHT);

  //evaluate the useres answer
  evalAnswer(left_numerator, right_numerator, left_denominator, right_denominator);
}
void FracComp::dispDiff_3_1() {
  //generate the random denominators based upon the accepted values for this diffculty
  int left_denominator = diff_3_denoms[random(15)];
  int right_denominator = diff_3_denoms[random(15)];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, left_denominator, right_denominator);

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  screen.dispFrac(right_numerator, right_denominator, RIGHT);

  //evaluate the useres answer
  evalAnswer(left_numerator, right_numerator, left_denominator, right_denominator);
}

// ##################################################################### //
// ################ VERSUS LEVEL 2 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_2() {
  //left number denominator
  int left_denominator = diff_1_denoms[random(5)];
  //right square denominator
  int column_index = random(4);
  int square_denom[2] = {diff_1_sq[0][column_index], diff_1_sq[1][column_index]};
  
  //declare the numerators
  int left_numerator;
  int square_numerator;
  //genrate the numerators
  makeNumer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
  
  //reformat and print the numerical fraction to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  
  //reformat and print the square fraction to the screen
  screen.dispSquareFrac(square_numerator, square_denom, RIGHT);
  
  //evaluate users answer
  evalAnswer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
  
}
void FracComp::dispDiff_2_2() {
  //left number denominator
  int left_denominator = diff_2_denoms[random(9)];
  //right square denominator
  int column_index = random(8);
  int square_denom[2] = {diff_2_sq[0][column_index], diff_2_sq[1][column_index]};
  
  //declare the numerators
  int left_numerator;
  int square_numerator;
  //genrate the numerators
  makeNumer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
  
  //reformat and print the numerical fraction to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  
  //reformat and print the square fraction to the screen
  screen.dispSquareFrac(square_numerator, square_denom, RIGHT);
  
  //evaluate users answer
  evalAnswer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
}
void FracComp::dispDiff_3_2() {
  //left number denominator
  int left_denominator = diff_3_denoms[random(15)];
  //right square denominator
  int column_index = random(9);
  int square_denom[2] = {diff_3_sq[0][column_index], diff_3_sq[1][column_index]};
  
  //declare the numerators
  int left_numerator;
  int square_numerator;
  //genrate the numerators
  makeNumer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
  
  //reformat and print the numerical fraction to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, left_denominator, LEFT);
  
  //reformat and print the square fraction to the screen
  screen.dispSquareFrac(square_numerator, square_denom, RIGHT);
  
  //evaluate users answer
  evalAnswer(left_numerator, square_numerator, left_denominator, square_denom[0] * square_denom[1]);
}

// ##################################################################### //
// ################ VERSUS LEVEL 3 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_3() {

}
void FracComp::dispDiff_2_3() {

}
void FracComp::dispDiff_3_3() {

}

// ##################################################################### //
// ################ VERSUS LEVEL 4 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_4() {
  //left square denominator
  int column_index = random(4);
  int square_denom1[2] = {diff_1_sq[0][column_index], diff_1_sq[1][column_index]};
  
  //right square denominator
  column_index = random(4);
  int square_denom2[2] = {diff_1_sq[0][column_index], diff_1_sq[1][column_index]};

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //generate the numerators
  makeNumer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, square_denom1, LEFT);
  screen.dispSquareFrac(right_numerator, square_denom2, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);
}
void FracComp::dispDiff_2_4() {
  //left square denominator
  int column_index = random(8);
  int square_denom1[2] = {diff_2_sq[0][column_index], diff_2_sq[1][column_index]};
  
  //right square denominator
  column_index = random(8);
  int square_denom2[2] = {diff_2_sq[0][column_index], diff_2_sq[1][column_index]};

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //generate the numerators
  makeNumer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, square_denom1, LEFT);
  screen.dispSquareFrac(right_numerator, square_denom2, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);
}
void FracComp::dispDiff_3_4() {
  //left square denominator
  int column_index = random(9);
  int square_denom1[2] = {diff_3_sq[0][column_index], diff_3_sq[1][column_index]};
  
  //right square denominator
  column_index = random(9);
  int square_denom2[2] = {diff_3_sq[0][column_index], diff_3_sq[1][column_index]};

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //generate the numerators
  makeNumer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, square_denom1, LEFT);
  screen.dispSquareFrac(right_numerator, square_denom2, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, square_denom1[0] * square_denom1[1], square_denom2[0] * square_denom2[1]);
}

// ##################################################################### //
// ################ VERSUS LEVEL 5 FUNCTION DEFINITIONS ################ //
// ##################################################################### //

void FracComp::dispDiff_1_5() {
  //generate the circle denominator from its list of avaible denominators
  int circle_denom1 = diff_1_denoms[random(5)];
  int circle_denom2 = diff_1_denoms[random(5)];

  //declare the numerators
  int circle_numer1;
  int circle_numer2;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer1, circle_numer2;, circle_denom1, circle_denom2);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer1, circle_denom1, LEFT);
  screen.dispCircleFrac(circle_numer2, circle_denom2, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer1, circle_numer2, circle_denom1, circle_denom2);

}
void FracComp::dispDiff_2_5() {
    //generate the circle denominator from its list of avaible denominators
  int circle_denom1 = diff_2_denoms[random(9)];
  int circle_denom2 = diff_2_denoms[random(9)];

  //declare the numerators
  int circle_numer1;
  int circle_numer2;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer1, circle_numer2;, circle_denom, circle_denom);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer1, circle_denom1, LEFT);
  screen.dispCircleFrac(circle_numer2, circle_denom2, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer1, circle_numer2, circle_denom1, circle_denom2);

}
void FracComp::dispDiff_3_5() {
  void FracComp::dispDiff_2_5() {
  //generate the circle denominator from its list of avaible denominators
  int circle_denom1 = diff_3_denoms[random(15)];
  int circle_denom2 = diff_3_denoms[random(15)];

  //declare the numerators
  int circle_numer1;
  int circle_numer2;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer1, circle_numer2;, circle_denom, circle_denom);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer1, circle_denom1, LEFT);
  screen.dispCircleFrac(circle_numer2, circle_denom2, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer1, circle_numer2, circle_denom1, circle_denom2);

}

// ##################################################################### //
// ################ VERSUS LEVEL 6 FUNCTION DEFINITIONS ################ //
// ##################################################################### //

//for these functions well always have circle on the left and sqaure on the right
void FracComp::dispDiff_1_6() {
  //generate the circle denominator from its list of avaible denominators
  int circle_denom = diff_1_denoms[random(5)];
  
  //genrate the sqaure denom by copying the 1st and second row of a random column
  //for this we need 1 static column index
  int column_index = random(4);
  int square_denom[2] = {diff_1_sq[0][column_index], diff_1_sq[1][column_index]};

  //declare the numerators
  int circle_numer;
  int sqaure_numer;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer, circle_denom, LEFT);
  screen.dispSquareFrac(sqaure_numer, square_denom, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);
}
void FracComp::dispDiff_2_6() {
  //generate the circle denominator from its list of avaible denominators
  int circle_denom = diff_2_denoms[random(9)];
  
  //genrate the sqaure denom by copying the 1st and second row of a random column
  //for this we need 1 static column index
  int column_index = random(8);
  int square_denom[2] = {diff_2_sq[0][column_index], diff_2_sq[1][column_index]};

  //declare the numerators
  int circle_numer;
  int sqaure_numer;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer, circle_denom, LEFT);
  screen.dispSquareFrac(sqaure_numer, square_denom, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);
}
void FracComp::dispDiff_3_6() {
  //generate the circle denominator from its list of avaible denominators
  int circle_denom = diff_3_denoms[random(15)];
  
  //genrate the sqaure denom by copying the 1st and second row of a random column
  //for this we need 1 static column index
  int column_index = random(9);
  int square_denom[2] = {diff_3_sq[0][column_index], diff_3_sq[1][column_index]};

  //declare the numerators
  int circle_numer;
  int sqaure_numer;

  //make the numerators
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  makeNumer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);

  //display the fractions
  screen.formatCompare();
  screen.dispCircleFrac(circle_numer, circle_denom, LEFT);
  screen.dispSquareFrac(sqaure_numer, square_denom, RIGHT);

  //evaluate the answers
  //note that here we pass the right denominator as the product of the two dimensions of,
  //the square denominator since in essence that is the value of the sqaure denominator
  evalAnswer(circle_numer, sqaure_numer, circle_denom, square_denom[0] * square_denom[1]);
}

// ##################################################################### //
// ############# OTHER METHOD DEFINITIONS IN THE COMP CLASS ############ //
// ##################################################################### //
void FracComp::makeNumer(int &numer1, int &numer2, int denom1, int denom2) {
  //make random numerators
  numer1 = random(0, denom1 + 1);
  numer2 = random(0, denom2 + 1);
  //calculate the fraction that is created
  double frac1 = (numer1 * 1.0) / (denom1 * 1.0);
  double frac2 = (numer1 * 1.0) / (denom1 * 1.0);
  //if the fractions are equal regenrate the numerators
  //**** ADD THIS LATER or if their ratio is greater than upper limit or lower than lower limit then re generate
  while(frac1 == frac2) {
    //make random numerators
    numer1 = random(0, denom1 + 1);
    numer2 = random(0, denom2 + 1);
    //calculate the fraction that is created
    frac1 = (numer1 * 1.0) / (denom1 * 1.0);
    frac2 = (numer2 * 1.0) / (denom2 * 1.0);
  }
}

void FracComp::evalAnswer(int numer1, int numer2, int denom1, int denom2) {
  //Determine the useres choice
  //1 is left button 2 is right button
  int button_pressed = 0;
  while (button_pressed == 0) {
    /* this is for testing if buttons worked
    Serial.println("Entered LOOP");
    Serial.println("Left Button Is Reading");
    Serial.println(digitalRead(left_button));
    Serial.println("Right Button Is Reading");
    Serial.println(digitalRead(right_button));
    */
    if (digitalRead(left_button) == LOW) {
      button_pressed = 1;
    } else if (digitalRead(right_button) == LOW) {
      button_pressed = 2;
    }
  }
  //determine the correct answer
  //1 is left fraction 2 is right fraction
  int correct_ans = 0;
  if ((numer1 * 1.0 / denom1 * 1.0) > (numer2 * 1.0 / denom2 * 1.0)) {
    correct_ans = 1;
  } else {
    correct_ans = 2;
  }
  //feedback to the user whether or not they were right
  if(button_pressed == correct_ans) {
    screen.dispCorrect();
    //add audio stuff here
  } else {
    screen.dispWrong();
    //add audio stuff here
  }
}

void FracComp::testerFunc() {
  //int denom1[2] = {4,5};
  //int denom2[2] = {5,7};
  //screen.dispSquareFrac(9, denom1, LEFT);
  //screen.dispSquareFrac(24, denom2, RIGHT);
  for (int denom = 2; denom < 25; denom++) {
    for (int numer = 1; numer <= denom; numer++) {
      screen.formatCompare();
      screen.dispCircleFrac(numer, denom, LEFT);
      screen.dispFrac(numer, denom, RIGHT);
      delay(100);
    }
  }
}
