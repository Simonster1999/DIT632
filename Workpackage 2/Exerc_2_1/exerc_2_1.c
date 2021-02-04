/*====================================
File name : exerc_2_1.c
Date : 2021 - 02 - 04
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Simon Engström
Emil Gustafsson
Member not present at demonstration time :
---
Demonstration code : [FQ74-RF3M-MB8V-45W6]
====================================== */

// Include section
#include <stdio.h>
#include <string.h>

// Define section
#define MAX 20      // defines the maximum number of chars to read

// Function prototype declaration
void copyString(char* target, char* origin);

// Main program section

/**
 * This program showcases how to copy a string using two functions,
 * also using the terminal and a seperate file as input.
 * 
 * Purpose: Demonstration of Exerc_2_1
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main() {
    
    // variable declarations
    char str[MAX];      // Original string
    char strCopy[MAX];  // Copy of original string

    // program logic

    // get the string, either from console or separete file
    printf("Type the string to copy: ");
    
    // reads MAX + 1 because otherwise the last index woyld contain null or end of file,
    // this way we get MAX amount of readable chars from the user
    fgets(str, MAX + 1, stdin);
    
    // copy the string using function from string.h
    strcpy(strCopy, str);
    printf("\nstrcpy: %s\n", strCopy);

    // make the two strings unequal again, to show that section function works
    strCopy[0] = '\0';

    // copy string using own function
    copyString(strCopy, str);
    printf("copyString: %s\n", strCopy);
}

// method that copies a string from one pointer to another
void copyString(char* target, char* origin) {

    // loops through entire string
    for(int i = 0; i < MAX; i++) {

        // finds end of string
        if (*origin != '\0') {

            // copies one char at a time
            *target = *origin;

            // change index of pointers by one
            origin++, target++;
        } else {
            break;
        }
    }
}
