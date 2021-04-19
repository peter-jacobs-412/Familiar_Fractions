#include <Arduino.h>
#include "Fraction_Create.h"

#define LEFT 0
#define RIGHT 405


 int anaRMax=1023;

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
  evalAnswer(numerator, denominator);
    
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
  evalAnswer(numerator, denominator);
    
}

void FracCreate::evalAnswer(bool isSlider, int numerator, int denominator)
{
    double fraction = (1.0*numerator)/(1.0*denominator);
    double userGuess, decNumer; //decNum holds user guessed numerator in decimal form
    int newNum;                 //used when get wrong anser
    
    //wait until they submit an answer using either button
    if (isSlider)
    {
        while (digitalRead(left_button)!=LOW && digitalRead(right_button)!=LOW){}
    }
    else
    {
        encoderVal=0;
        measureEncoder();
    }
    

        //evaluate if got it right or wrong, then display closest fraction to the right
        userGuess=getUserGuess(isSlider);
        if (abs(userGuess-fraction)<=0.1)
        {
            screen.dispFrac(numerator,denominator,RIGHT);
            delay(1000);
            screen.dispCorrect();
        }
        else
        {
            decNum=userGuess*denominator);
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
            }

            //output
            screen.dispFrac(newNum,denominator,RIGHT);
            delay(1000);
            screen.dispWrong();
        }
    
}
double getUserGuess(bool isSlider)
{
    if (isSlider)
    {
        return analogRead(slider)*1.0/(anaRMax*1.0);
    }
    else
    {
        return 1.0*encoderVal/20.0;
    }
}

//function to get value of the encoder
void measureEncoder()
{
        int rotation = digitalRead(clk);
    int value;
    while (digitalRead(left_button)!=LOW && digitalRead(right_button)!=LOW)
    {
           
  
     value = digitalRead(clk);
     if (value != rotation){ // we use the DT pin to find out which way we turning.
     if (digitalRead(DT) != value) {  // Clockwise
        if (encoderVal<20)
        {
           encoderVal ++; 
           screen.dispCircleFrac(encoderVal,20,RIGHT);
        }
       
     } else { //Counterclockwise
      if (encoderVal>0)
      {
         encoderVal--;
        screen.dispCircleFrac(encoderVal,20,RIGHT);
      }
       
     }
     // this will print in the serial monitor.
     
   } 
   rotation = value;
    }
}



