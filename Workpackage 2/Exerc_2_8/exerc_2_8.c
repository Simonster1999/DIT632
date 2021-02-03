/*====================================
File name : exerc_2_8.c
Date : 2021 - 02 - 04
Group nr 7
Members that contribute to the solutions
Simon Engström
Member not present at demonstration time :
---
Demonstration code : []
====================================== */
 
//include section
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//define section
#define MAX_COINS 13

//constant section
const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner(int player);

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle(int player);

/* --------------------- Utilities -------------*/
void clear_stdin();

// Main program section

/**
 * This program is a game of NIM.
 * 
 * Purpose: Demonstration of Exerc_2_8
 * DIT632
 * 
 * Author: Simon Engström, 2021
 * 
**/
int main()
{
    int pile,    /* This is how many coins we have */
        player,  /* Who is playing? */
        n_coins; /* Number of coins taken */

    srand(time(0)); /* Setup random */

    printf("Välkommen till NIM by Simon Engström \n");

    pile = MAX_COINS; /* Set start values (= init) */
    player = HUMAN;

    /* 
   *  Program main loop 
   */
    while (true)
    {

        printf("Det ligger %d  mynt i högen\n", pile);

        if (player == HUMAN)
        {
            n_coins = human_choice(pile);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
        }
        pile -= n_coins;
        player = toggle(player);

        if (pile <= 1)
        {
            break;
        }
    }
    /*
   * end main loop
   */

    write_winner(player);

    //if play_again() returns 'true', then we play again, else we stop
    if (play_again() == true)
    {
        main();
    }
    else
    {
        printf("Avslutat\n");
    }
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}

//method that gets input from the user and makes checks according to the rules, then returns the input
int human_choice(int pile)
{
    int input;

    printf("- Jag tar: ");
    scanf("%d", &input);
    clear_stdin();
    
    //checks to see of user input is smaller than pile, less or equal to 3 and more than 0
    if (input < pile && input <= 3 && input > 0)
    {
        return input;
    }
    else
    {
        printf("\n Ogiltigt, försök igen \n\n");
        human_choice(pile);
    }
}

//method to generate a random integer between 1 and 3, has some AI if the pile is equal to 4 or less, then returns the integer
int computer_choice(int pile)
{
    int randomNum;

    switch (pile)
    {
    case 4:
        randomNum = 3;
        break;
    case 3:
        randomNum = 2;
        break;
    case 2:
        randomNum = 1;
        break;
    default:
        randomNum = rand() % (3) + 1;
    }

    return randomNum;
}

//method that prints the winner
void write_winner(int player)
{
    if (player == 0)
    {
        printf("\nCOMPUTER vann! \n\n");
    }
    else
    {
        printf("\nHUMAN vann!  \n\n");
    }
}

//method that asks the user if they want to play again, and returns either true or false
int play_again()
{
    char input;

    printf("Do you want to play again? (Y/N)\n");
    scanf("%c", &input);
    clear_stdin();

    //Checks user input to see if it equals 'n' or 'N'
    if (input == 'n' || input == 'N')
    {
        return false;
    }
    else
    {
        return true;
    }

}

//method that decides if it's player or computers turn to take coins
int toggle(int player)
{
    if (player == HUMAN)
    {
        player = COMPUTER;
    }
    else
    {
        player = HUMAN;
    }
    return player;
}
