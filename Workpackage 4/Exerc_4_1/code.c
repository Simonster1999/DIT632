/*====================================
File name : code.c
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

// Main program section

/**
 * This program reads five arguments for five different values, the values are checked to be within
 * the allowed ranges and are then packed into a byte and printed out as a hexadecimal number.
 * 
 * Purpose: Demonstration of Exerc_4_1
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main(int argc, char *argv[]) {

    // variable declarations
    unsigned char byte;     // stores the combined values
    int sum[5];             // stores each individual value

    // program logic

    // check for exactly 5 arguments
    if (argc == 6) {
        
        // casts each string argument to an integer and turns '0-9' to 0-9 by subtracting 48
        for (int i = 0; i < 5; i++) {

            sum[i] = (int) *argv[i + 1] - 48;
        }

        // check that the numbers provided do not fit within the ranges specified
        // also exits if non numbers were provided, 'abc' for example
        if ((sum[0] != 0 && sum[0] != 1) || 
            (sum[1] >  4) || 
            (sum[2] >  2) || 
            (sum[3] != 0 && sum[3] != 1) || 
            (sum[4] != 0 && sum[4] != 1)) {

            printf("Invalid number provided, number out of allowed ranges\n");
            exit(1);
        }
        // all five numbers should be stored in one byte and has their own bits,
        // the values must therefore be multplied to be moved to seperate bits.
        // when summing up the different values their position in the byte has to be taken into account
        // turning value to correct binary number then convert to decimal
        byte = (sum[0] * 128 
                + sum[1] * 16
                + sum[2] * 4
                + sum[3] * 2
                + sum[4]);

        // print as uppercase hexadecimal number
        printf("%X", byte);
    }
    else {
        printf("Must inlcude excatly 5 argument\n");
        exit(1);
    }
}
