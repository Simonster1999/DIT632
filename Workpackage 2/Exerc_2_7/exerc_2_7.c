/*====================================
File name : exerc_2_7.c
Date : 2021 - 02 - 04
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [FQ74-RF3M-MB8V-45W6]
====================================== */

// Include section
#include <stdio.h>
#include <stdlib.h>

// Define section
#define MAX 10      // defines the size of a person number,
                    // person number syntax: yymmddxxxc

// Function prototype declaration
void readPersnr(char* person);
int controlDigit(const char* persnr);

// Main program section

/**
 * The program checks whether a entered swedish person number, entered as a string,
 * is valid by checking that the month and day are within the correct range and then 
 * calculates the correct control number and compares it to the one provided.
 * This progam demonstrates the use of pointers, casting of chars to ints, and handling of arrays.
 * 
 * Purpose: Demonstration of Exerc_2_7
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main() {
    
    // variable declarations
    char spn[MAX];      // string for the swedish person number

    // program logic

    // asks user to type a swedish person number,
    // checks whether it is correct or not using the control number
    // prints the result to user
    // stops running when user enters 'q'
    while (1) {

        // reads user input
        readPersnr(spn);

        // checks if user typed q
        if (spn[0] == 'q') {
            exit(1);
        }

        // check if the calculated control number matches that one provided
        // converts char to int, like for example '1' to 1
        if (controlDigit(spn) == (int) spn[9] - 48) {
            printf("%s is a valid swedish person number", spn);
        }
        else {
            printf("%s is an invalid swedish person number", spn);
        }
        printf("\n");
    }
}

// asks user for input, reads at most ten chars
void readPersnr(char* person) {

    printf("\nEnter a person number: ");
    scanf("%10s", person);
}

// converts string of numbers as chars to integers
// checks whether month and day are within correct range
// calculates the control number using the Luhn-algorithm
int controlDigit(const char* persnr) {

    // variable declarations
    int spn[MAX],   // swedish person number as seperate numbers in an array
        mon,        // the two month integers combined
        day,        // the two day integers combined
        sum = 0;    // the sum used for the Luhn-algorithm

    // loops through all chars pointed to by persnr and converts and stores them in spn
    for (int i = 0; i < MAX; i++) {

        // checks if the char is not a number (0-9), if so then exits
        if ((int) *persnr - 48 < 0 || (int) *persnr - 48 > 9) {
            exit(1);
        }
        // stores converted char in spm array, a char '0' is cast to an int as 48
        // therefore the -48, similarly '1' becomes 49 etc
        spn[i] = (int) *persnr - 48;

        // moves pointer to next index
        // persnr[i] could be used but doesn't show the current value while debugging, only first index
        persnr++;
    }
    
    // month and day are stored following yymmddxxxc
    // calculates the month number, January becomes 0 * 10 + 1 = 1
    //                              December becomes 1 * 10 + 2 = 12
    mon = spn[2] * 10 + spn[3];

    // calculates the day number, same method as for months: 0 * 10 + 6 = 6, 3 * 10 + 0 = 30
    day = spn[4] * 10 + spn[5];

    // check whether the month and day are withing the corect ranges, if not then exits
    if (mon > 0 && mon < 13) {
        // if Febuary
        if (mon == 2) {
            // assumes it is a leap year
            if (day < 1 || day > 29) {
                printf("Invalid day");
                exit(1);
            }
        }
        // else if April, June, September, November
        else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
            if (day < 1 || day > 30) {
                printf("Invalid day");
                exit(1);
            }
        }
        // other months
        else {
            if (day < 1 || day > 31) {
                printf("Invalid day");
                exit(1);
            }
        }
    }
    else {
        printf("Invalid month");
        exit(1);
    }

    // implemtation of Luhn-algorithm
    // multiplies every other number with 2 or 1, starting with 2
    // if the resulting interger is greater than 9 e.g. 10 or more
    // then the number should be split 17 -> 1 and 7
    // all numbers are then added together
    // subtracting 9 instead of splitting gives the same result:
    //      10 -> 1 + 0 == 10 - 9, 19 -> 1 + 9 == 19 - 9
    // loops MAX - 1 times beacuse the last number is the control number,
    // which is not part of the equation, rather the supposed result, if the spn is valid
    for (int i = 0; i < MAX - 1; i++) {
        
        // statement is true every other iteration, initially true
        if (i % 2 == 0){
            // checks if number becomes greater than 9, in which case subtract 9, incase of splitting
            if (spn[i] * 2 > 9) {
                // multiply number by 2 and subtract 9 then add to sum
                sum += spn[i] * 2 - 9;
            }
            else {
                // multiply number by 2 and add to sum
                sum += spn[i] * 2;
            }
        }
        else {
            // add number to sum, do not have to multiply by 1
            sum += spn[i];
        }
    }
    
    // sum is then supposed to be removed from its closest higher tens,
    // i.e. if sum is 33 then take 40 - 33 and get 7
    // dividing by ten and using the rest does the same thing
    // 40 is supposed to give 0 for example
    // the returned value should be between 0 and 9
    if (sum % 10 == 0) {
        return 0;
    }
    else {
        // if the sum % 10 is not 0, then remove the rest from 10. 40 - 33 == 10 - 3 etc
        return 10 - sum % 10;
    }
}