// Include section
#include <stdio.h>

// Constant section
#define MAX 100

int countWords(char[]);
char *userInput();

// Main program section

/**
 * This program accepts a string as input and prints the amount of words within the string to the console.
 * 
 * 
 * Purpose: Demonstration of Exerc_1_2
 * DIT632
 * 
 * Author: Simon Engström, 2021
 * 
**/

void main()
{
    printf("%s %d", "Number of words: ", countWords(userInput()));
}

//method to read the input from the user

char *userInput()
{

// variable declarations

    char *words; //used to return the inputArray[]
    char inputValue[MAX], c; //inputValue[] will store each letter entered by the user
    int n = 0; //used to keep track of the amount of chars added to the inputValue array

    printf("%s", "Write something: \n");
    
    while((c = getchar()) != '\n') //gets the characters that the user enters into the command prompt, and assigns the character to the c variable
    {                              //as well as check that it does not equal to "\n"(enter)
        inputValue[n] = c; //stores each character entered by the user in the command prompt into the array
        n++;
    }
    inputValue[n] = '\0'; //adds "\0" to the end of the array
    words = inputValue;

    return words; //returns the string of words
}

//method that counts the amount of words in the string that the user input

int countWords(char value[])
{

    // variable declarations

    int nr_of_words = 0; //number of words
    int i = 0;

    // Program logic

    while (value[i] != '\0') //will run until the end of the value[] array
    {
        if (value[i] == ' ') //if it finds ' '(space) it will add +1 to the nr_of_words attribute
        {
            nr_of_words++;
        }
        i++;
    }
    return nr_of_words + 1; //returns the number of words found in value[]
}
