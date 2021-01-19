#include <stdio.h>

//Code done by Simon Engström

//Declaring our input() function
void input();

void main()
{
   input();
}

void input()
{
   //Declaring a variable of type int
   int inputValue;

   //Prints "Enter a number between 1 and 5: " to the console
   printf("Enter a number between 1 and 5: ");

   //Gets input from the user, "%d" means we want an integer, and we assign the value that the user inputs to our variable "inputValue"
   scanf("%d", &inputValue);

   //A switch case that takes our variable "inputValue" as expression, then checks if it matches any of the cases. If it does not match any of the cases
   //it will go to the default case and print "Stopped"
   switch (inputValue)
   {
   case 1:
      printf("Entered 1 \n");
      input();
      break;
   case 2:
      printf("Entered 2 \n");
      input();
      break;
   case 3:
      printf("Entered 3 \n");
      input();
      break;
   case 4:
      printf("Entered 4 \n");
      input();
      break;
   case 5:
      printf("Entered 5 \n");
      input();
      break;
   default:
      printf("Stopped \n");
   }
}