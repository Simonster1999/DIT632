/*====================================
File name : decode.c
Date : 2021 - 02 - 19
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [VGP9-HVEG-QSCW-K7ZD]
====================================== */

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define section
#define engine_on 0b10000000    // its bit in a byte
#define gear_pos  0b01110000    // its bits in a byte
#define key_pos   0b00001100    // its bits in a byte
#define brake1    0b00000010    // its bit in a byte
#define brake2    0b00000001    // its bit in a byte

// Main program section

/**
 * The program reads in hexadecimal value in the form of a string as a argument which it converts to an
 * integer and tries to assign the number to the five different values, engine_pos etc, by reading 
 * the bits which are allocated for each value. It also takes into account the number ranges described 
 * in Exerc_4_1 for each value. 
 * 
 * Purpose: Demonstration of Exerc_4_2
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main(int argc, char *argv[]) {
    
    // variable declarations
    unsigned char num;  // char for storing the hexadecimal number

    // program logic

    // checks if excatly one argument has been given
    if (argc == 2) {

        // loops through entire string of the argument, checks that the string given is a valid
        // hexadecimal number
        for (int i = 0; i < strlen(argv[1]); i++) {

            // check if argument is not 0-9 and a-f and A-F i. e. not a valid hexadecimal value
            if ((argv[1][i] < 48 || argv[1][i] > 57) &&
                (argv[1][i] < 97 || argv[1][i] > 102) &&
                (argv[1][i] < 65 || argv[1][i] > 70)) {

                printf("Invalid hexadecimal number provided\n");
                exit(1);
            }
        }

        // turns a string into a hexadecimal integer and stores the integer in num
        num = (int) strtol(argv[1], NULL, 16);

        // 203 is max number possible according to the number ranges specified
        if (num < 204) {

            // filter bits and check if values are within 
            // gear_pos and key_pos ranges specified in Exerc_4_1
            if ((num & gear_pos) < 65 && (num & key_pos) < 9) {

                printf("\nName\t\tValue\n");
                printf("---------------------\n");

                // filter bits for each value and shifts right
                printf("engine_on\t%d\n", (num & engine_on) >> 7);
                printf("gear_pos\t%d\n",  (num & gear_pos) >> 4);
                printf("key_pos\t\t%d\n", (num & key_pos) >> 2);
                printf("brake1\t\t%d\n",  (num & brake1) >> 1);
                printf("brake2\t\t%d\n",   num & brake2);
            }
            else {
                printf("Invalid number provided, number out of allowed ranges\n");
            }
        }
        else {
            printf("Invalid number provided, number too large\n");
        }
    }
    else {
        printf("Must inlcude excatly 1 argument\n");
    }
}
