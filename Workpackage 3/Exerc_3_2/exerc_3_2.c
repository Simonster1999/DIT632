/*====================================
File name : exerc_3_2.c
Date : 2021 - 02 - 11
Group nr 7
Members that contribute to the solutions
Emil Gustafsson
Simon Engström
Mattias Ekdahl
Member not present at demonstration time :
---
Demonstration code : [QEGF-Z6Z6-5V4G-WULS]
====================================== */

//include section
#include <stdio.h>
#include <string.h>

//function declaration
int search_number(int number, int tab[], int size);
void sort(int tab[], int size);

//main program section
/**
 * This program finds the number n in an array and displays its position
 * Performs bubblesort on the array to sort the contents in ascending order
 *
 * Purpose: Demonstration of Exerc_3_1
 * DIT632
 *
 * Author: Emil Gustafsson, 2021
 *
**/
void main() {
    // declaring value to search for
    int n = 13;
    // array of values to be searched through and sorted
    int test[] = { 1,2,34,5,67,3,23,12,13,10 };
    // length of array test
    int length = (sizeof(test) / sizeof(test[0]));
    // this variable stores the returned value from the search_number function call
    int existsInTable = search_number(n, test, length);
    printf("Search results:");
    // a search value of -1 means that the number does not exist in the array
    if (existsInTable == -1) {
        printf("\nThe number n does not exist in the array.");
    }
    // if search_number returns any other value than -1, that will be the index that contains the number n
    else {
        printf("\nThe number n first appears at the index %d in the array", existsInTable);
        printf("\nThe array's content: \n");
        // print the content of every index in the array
        for (int i = 0; i < length; i++) {
            printf("%d ", test[i]);
        }
    }

    printf("\n\nSorting array...");
    // call the sort function to sort the array test
    sort(test, length);
    printf("\nThe array's content after sorting: \n");
    // print the content of every index in the array after a sort has been performed
    for (int i = 0; i < length; i++) {
        printf("%d ", test[i]);
    }

    // the next 12 lines consist of a repeat of the first search, to display what has changed after the sort
    printf("\n\nSearch results after sorting array:");
    existsInTable = search_number(n, test, length);
    if (existsInTable == -1) {
        printf("\nThe number n does not exist in the array.");
    }
    else {
        printf("\nThe number n first appears at the index %d in the array\n", existsInTable);
        printf("\nThe array's content: \n");
        for (int i = 0; i < length; i++) {
            printf("%d ", test[i]);
        }
    }
}

// this function receives a number, an array and the length of the array and goes through each index to check if that number exists within it
int search_number(int number, int tab[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        // if the current index contains the same value as number, set result to i
        if (tab[i] == number) {
            result = i;
            // break out of the loop because a match was found
            break;
        }
        // if the current index contains a different value than number, set result to -1
        else {
            result = -1;
            // we don't break out of the loop here so that the function doesn't return -1 before it has checked every index of the array
        }
    }
    // after the loop, the result variable will represent whether or not the number exists in the array, and if so, which index it appears at
    return result;
}

// this function performs bubble sort on the array it receives
void sort(int tab[], int size) {
    int temp = 0;
    // bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        // for every index (i), compare every following index to the index after it
        for (int j = 0; j < size - i - 1; j++) {
            // if the value after j is greater than the value of j, store j's value in the temp variable
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                // then, store the next value after j in index j
                tab[j] = tab[j + 1];
                // and finally, get the value that was previously in j and put it in the index after j
                tab[j + 1] = temp;
            }
        }
    }

}