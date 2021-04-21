#include <Arduino.h>
#include "Fraction_Create.h"

#define LEFT 0
#define RIGHT 405


 #define anaRMax 1023

FracCreate::FracCreate(int clk_pin, int dt_pin, int slider_pin, int left_pin, int right_pin) {
  left_button = left_pin;
  right_button = right_pin;
  slider=slider_pin;
  clk=clk_pin;
  dt=dt_pin;
  pinMode(left_button, INPUT_PULLUP);
  pinMode(right_button, INPUT_PULLUP);
  pinMode(slider,INPUT);
  pinMode(clk,INPUT);
  pinMode(dt,INPUT);
}

//number to linear
void FracCreate::dispDiff1_1()
{
     //generate random index between 0 and 5
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff1_2()
{
     //generate random index between 0 and 5
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//square to linear
void FracCreate::dispDiff1_3()
{
     //generate random index between 0 and 8
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_1_sq[0][rand_index]*diff_1_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//square to circle
void FracCreate::dispDiff1_4()
{
     //generate random index between 0 and 8
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_1_sq[0][rand_index]*diff_1_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);
  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//circle to linear
void FracCreate::dispDiff1_5()
{
     //generate random index between 0 and 5
  int rand_index = random(5);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_1_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispCircleFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff1_6()
{
    dispDiff1_5(); 
}

//number to linear
void FracCreate::dispDiff2_1()
{
     //generate random index between 0 and 5
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_2_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff2_2()
{
     //generate random index between 0 and 5
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_2_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//square to linear
void FracCreate::dispDiff2_3()
{
     //generate random index between 0 and 8
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_2_sq[0][rand_index]*diff_2_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//square to circle
void FracCreate::dispDiff2_4()
{
     //generate random index between 0 and 8
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_2_sq[0][rand_index]*diff_2_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);
  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//circle to linear
void FracCreate::dispDiff2_5()
{
     //generate random index between 0 and 8
  int rand_index = random(9);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_2_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispCircleFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff2_6()
{
    dispDiff2_5(); 
}//number to linear
void FracCreate::dispDiff3_1()
{
     //generate random index between 0 and 5
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_3_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff3_2()
{
     //generate random index between 0 and 5
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_3_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//square to linear
void FracCreate::dispDiff3_3()
{
     //generate random index between 0 and 8
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_3_sq[0][rand_index]*diff_3_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//square to circle
void FracCreate::dispDiff3_4()
{
     //generate random index between 0 and 8
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_3_sq[0][rand_index]*diff_3_sq[1][rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispSquareFrac(numerator, denominator, LEFT);
  //evaluate the useres answer
  evalAnswer(false,numerator, denominator);
    
}
//circle to linear
void FracCreate::dispDiff3_5()
{
     //generate random index between 0 and 5
  int rand_index = random(15);
  //getting denominator from the list of accepted denoms using a random index value
  denominator = diff_3_denoms[rand_index];

  //declare the numerators
  int numerator=random(0,denominator+1);
  

  //reformat and print the fractions to the screen
  screen.formatCompare();
  screen.dispCircleFrac(numerator, denominator, LEFT);

  //evaluate the useres answer
  evalAnswer(true,numerator, denominator);
    
}

//number to circle
void FracCreate::dispDiff3_6()
{
    dispDiff3_5(); 
}

void FracCreate::evalAnswer(bool isSlider, int numerator, int denominator)
{
    double fraction = (1.0*numerator)/(1.0*denominator);
    double userGuess, decNum; //decNum holds user guessed numerator in decimal form
    int newNum;                 //used when get wrong anser
    
    //wait until they submit an answer using either button
    if (isSlider)
    {
        while (digitalRead(left_button)!=LOW && digitalRead(right_button)!=LOW){
          }
    }
    else
    {
        encoderVal=0;
        measureEncoder();
    }
    

        //evaluate if got it right or wrong, then display closest fraction to the right
        userGuess=getUserGuess(isSlider);
        Serial.println(userGuess);
        if (abs(userGuess-fraction)<=0.1)
        {
            screen.dispFrac(numerator,denominator,RIGHT);
            delay(1000);
            screen.dispCorrect();
        }
        else
        {
            decNum=userGuess*denominator;
            if (round(decNum)!=numerator)
            {
                newNum=round(decNum);
            }
            //go to denominator 2x as big 
            //example 8ths become 16ths
            else
            {
                if (decNum<numerator)
                {
                    newNum=numerator*2-1;
                    denominator=denominator*2;
                }
                else
                {
                    newNum=numerator*2+1;
                    denominator=denominator*2;
                }
                //output
            screen.dispFrac(newNum,denominator,RIGHT);
            delay(1000);
            Serial.println("Wrong");
            screen.dispWrong();
            }

            
        }
    
}
double FracCreate::getUserGuess(bool isSlider)
{
    if (isSlider)
    {
        Serial.println(analogRead(slider));
        return analogRead(slider)*1.0/(anaRMax*1.0);
    }
    else
    {
        return 1.0*encoderVal/40.0;
    }
}
//function to get value of the encoder
void FracCreate::measureEncoder()
{
    screen.dispCircleFrac(0,20,RIGHT);
    int rotation = digitalRead(clk);
    int value;
    while (digitalRead(left_button)!=LOW && digitalRead(right_button)!=LOW)
    {
           
  
     value = digitalRead(clk);
     if (value != rotation){ // we use the DT pin to find out which way we turning.
     if (digitalRead(dt) != value) {  // Clockwise
        if (encoderVal<40)
        {
           encoderVal ++; 
           //screen.dispCircleFrac(floor(encoderVal/2),20,RIGHT);
        }
       
     } else { //Counterclockwise
        if(encoderVal>0)
        {
            encoderVal--;
        //screen.dispCircleFrac(floor(encoderVal/2),20,RIGHT);
        }
       
     }
     // this will print in the serial monitor.
     
   } 
   rotation = value;
 } 
    
}
