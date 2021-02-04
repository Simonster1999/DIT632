/*====================================
File name : exerc_2_2.c
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
#include <time.h>
#include <stdlib.h>

// Define section
#define MAX 10      // defines maximum numbers to generate
#define UPPER 99    // defines the highest number that can be generated
#define LOWER 1     // defines the lowest number that can be generated

// Function prototype declaration
int sum(int* array, int size);

// Main program section

/**
 * This program uses a random number generator to fill an array and prints info about it
 * and its content
 * 
 * Purpose: Demonstration of Exerc_2_2
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

void main() {

    // variable declarations
    int array[MAX];
    
    // program logic

    // generating the first random number
    srand(time(0));

    // generate a random number for each index using i and MAX
    for(int i = 0; i < MAX; i++) {
        array[i] = rand() % UPPER + LOWER;
    }

    printf("\nThe value of the label array (address) is: %p", &array);
    printf("\nFirst integer in the array is (array[0]) : %d", array[0]);
    printf("\nThe size of an integer (number of bytes) is : %d", sizeof(array[0])); // size of first element
    printf("\nThe size of the whole array is : %d", sizeof(array));                 // size of array
    printf("\nThe sum of the all values is : %d\n\n", sum(array, MAX));               // sum of array

    // prints each element and its double value
    for(int i = 0; i < MAX; i++) {
        int* num = &array[i];
        // unclear whether to double the value or to cast it to a double, therefore both are included
        printf("[%i] value: %d, \tdoubled value: %d, \tdouble type: %f\n", i, *num, *num * 2, (double) *num);
    }

}

// returns the sum of an array
int sum(int* array, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += *array;
        array++;
    }
    return sum;
}
