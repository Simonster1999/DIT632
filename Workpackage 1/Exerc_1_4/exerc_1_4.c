/*====================================
File name : exerc_1_1.c
Date : 2021 - 01 - 28
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Member not present at demonstration time :
---
Demonstration code : [KF4E-N7V4-ZY7Q-U9AV]
====================================== */

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant section
const int MAX_NUMBER = 10;      // specifies the maximum number of allowed guesses per round
const int RAND_NUM_UPPER = 100; // specifies the upper limit of the range of random numbers
const int RAND_NUM_LOWER = 1;   // specifies the lower limit of the range of random numbers

// Main program section

/**
 * This program is a simple game where the user guesses a random number
 * between 1 and 100.
 * 
 * Purpose: Demonstration of Exerc_1_4
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main() {

    // variable declarations
    int play = 1,       // initialization of the condition to play a round
        rand_num,       // number to be guessed
        guess = RAND_NUM_LOWER - 1, // initialization of the guess,
                                    // the initial guess is guaranteed to be incorrect by default
        guess_counter;  // counter for number of guesses

    // program logic

    // generating the first random number
    srand(time(0));

    printf("\nWelcome to Guess the number\n");

    // the loop that generates new random numbers
    // each loop represents one round of the game
    // runs based on play equalling 1 as the condition
    while (play == 1) {

        // initialization of number to guess with a new random number
        // using the upper and lower limits
        rand_num = rand() % RAND_NUM_UPPER + RAND_NUM_LOWER;

        // initialization of the counter set to 0 by default
        guess_counter = 0;

        // the loop runs until the random number is correctly guessed,
        // or until the maximum number of guesses has been exceeded
        while (guess != rand_num && guess_counter <= MAX_NUMBER) {
            
            printf("Guess the number: ");
            // reading the user's guess
            scanf("%d", &guess);
            printf("\n");

            // check if the guess is within the range RAND_NUM_LOWER to RAND_NUM_UPPER
            if (guess < RAND_NUM_LOWER || guess > RAND_NUM_UPPER) {
                // notifies user to guess within the possible range of random numbers
                printf("Your guess must be within the range %d ...%d\n", RAND_NUM_LOWER, RAND_NUM_UPPER);
            }
            // check if guess is to high
            else if (guess > rand_num) {
                printf("Your guess is to high\n");
            }
            // check if guess is to low
            else if (guess < rand_num) {
                printf("Your guess is to low\n");
            }
            // increases the counter of guesses after each guess
            guess_counter++;

            // exits the loop if the guess is correct so no else statement is needed
        }
        // checks if the number of guesses exceeded the maximum,
        // otherwise the guess was correct
        if (guess_counter > MAX_NUMBER) {
            // prints the answer
            printf("The max number of guesses has been reached. The number was: %d\n", rand_num);
        } else {
            // prints the amount of guesses it took to win
            printf("You have guessed %d times and your guess is correct\n", guess_counter);
        }
        printf("Would you like to play again? Yes (1), no (0)\n");
        // asks user if they wish to play another round,
        // updates play to either make another loop or exit and stop the program
        scanf("%d", &play);
    }
}
