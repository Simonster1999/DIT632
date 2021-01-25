// Include section
#include <stdio.h>

// Constant section
void sort();
int userInput();

// Main program section

/**
 * This program accepts a number between 1-5, and prints a predifined string 
 * depending on the number that was entered. If the user does not enter a number between 1-5
 * the string "Stopped" will print.
 * 
 * 
 * Purpose: Demonstration of Exerc_1_1
 * DIT632
 * 
 * Author: Simon Engström, 2021
 * 
**/


void main()
{

   //the sort method uses the value returned from the userInput method.

   sort(userInput());
}

//method to read the input from the user

int userInput()
{

   // variable declarations

   int input; //variable to store user input

   // program logic

   printf("Enter a number between 1 and 5: ");
   scanf("%d", &input); //gets user input and stores it to the input variable

   return input; //returns the input variable
}

//method to print a certain string depending on the value inserted

void sort(int value)
{

  //a switchcase that use value as expression and checks for a number of cases. if the value corresponds with one
  //of the cases it will print the number entered to the console and then run the sort method again. if the value does not correspond 
  //with any of the cases, then "stopped" will be printed and the program stops.

   switch (value)
   {
   case 1:
      printf("Entered 1 \n");
      sort(userInput());
      break;
   case 2:
      printf("Entered 2 \n");
      sort(userInput());
      break;
   case 3:
      printf("Entered 3 \n");
      sort(userInput());
      break;
   case 4:
      printf("Entered 4 \n");
      sort(userInput());
      break;
   case 5:
      printf("Entered 5 \n");
      sort(userInput());
      break;
   default:
      printf("Stopped \n");
   }
}