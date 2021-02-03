/*====================================
File name : exerc_2_6.c
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

//define section
#define MAX 5

//method that recieves an array and fills it with -1
void initQue(int list[], int max)
{
    for (int i = 0; i < max; i++)
    {
        list[i] = -1;
    }
}

//method that recieves an array and an integer, then puts it into first "empty" index in the array, then returns 1 if array is not empty, and 0 otherwise
int input(int list[], int number, int max)
{
    if (list[max - 1] != -1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < max; i++)
        {
            if (list[i] == -1)
            {
                list[i] = number;

                return 1;
            }
        }
    }
}

//method that recieves an array and first checks if first index is equal to -1, if true means array is empty
//if false it removes the number in the first index and shifts the numbers in the other indexes one step to the left and adds -1 to the last index
int output(int list[], int max)
{
    if (list[0] == -1)
    {
        return 0;
    }
    else
    {
        int number = list[0];
        int n = 1;

        for (int i = 0; i < max; i++)
        {
            list[i] = list[n];
            n++;
        }
        list[max - 1] = -1;
        return number;
    }
}

// Main program section

/**
 * This program demonstrates the functions required for exerc_2_6.
 * 
 * Purpose: Demonstration of Exerc_2_6
 * DIT632
 * 
 * Author: Simon Engström, 2021
 * 
**/


void main()
{
    //init array
    int array[MAX];

    initQue(array, MAX);

    //prints the starting array
    for (int i = 0; i < MAX; i++)
    {
        printf("%d", array[i]);
    }

    printf("\n");

    //fills array with numbers starting at 0 and increasing, stops when full
    int number = 0;
    for (int i = 0; i < MAX + 1; i++)
    {
        if (input(array, number, MAX) == 1)
        {
            for (int i = 0; i < MAX; i++)
            {
                printf("%d", array[i]);
            }
        }
        else
        {
            printf("Array is full");
        }
        number++;
        printf("\n");
    }

    //uses output method to remove first index one by one, then prints array
    for (int i = 0; i < MAX; i++)
    {
        output(array, MAX);

        for (int i = 0; i < MAX; i++)
        {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}
