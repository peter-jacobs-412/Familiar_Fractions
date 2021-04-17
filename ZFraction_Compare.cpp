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
  //generate random index between 0 and 5
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, denominator, denominator);

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(left_numerator, denominator, LEFT);
  screen.dispFrac(right_numerator, denominator, RIGHT);

  //evaluate the useres answer
  evalAnswer(left_numerator, right_numerator, denominator, denominator);
}
void FracComp::dispDiff_2_1() {

}
void FracComp::dispDiff_3_1() {

}

// ##################################################################### //
// ################ VERSUS LEVEL 2 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_2() {

}
void FracComp::dispDiff_2_2() {

}
void FracComp::dispDiff_3_2() {

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
  //generate random index between 0 and 5
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, denominator, denominator);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, denominator, LEFT);
  screen.dispSquareFrac(right_numerator, denominator, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, denominator, denominator);
}
void FracComp::dispDiff_2_4() {
  //generate random index between 0 and 9
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_2_denoms[rand_index];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, denominator, denominator);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, denominator, LEFT);
  screen.dispSquareFrac(right_numerator, denominator, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, denominator, denominator);
}
void FracComp::dispDiff_3_4() {
  //generate random index between 0 and 15
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  int denominator = diff_3_denoms[rand_index];

  //declare the numerators
  int left_numerator;
  int right_numerator;
  //genrate the numerators
  makeNumer(left_numerator, right_numerator, denominator, denominator);

  //reformat and print the fractions represented as squares to the screen
  screen.formatCompare();
  screen.dispSquareFrac(left_numerator, denominator, LEFT);
  screen.dispSquareFrac(right_numerator, denominator, RIGHT);

  //evaluate the users answer
  evalAnswer(left_numerator, right_numerator, denominator, denominator);
}

// ##################################################################### //
// ################ VERSUS LEVEL 5 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_5() {

}
void FracComp::dispDiff_2_5() {

}
void FracComp::dispDiff_3_5() {

}

// ##################################################################### //
// ################ VERSUS LEVEL 6 FUNCTION DEFINITIONS ################ //
// ##################################################################### //
void FracComp::dispDiff_1_6() {

}
void FracComp::dispDiff_2_6() {

}
void FracComp::dispDiff_3_6() {

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
