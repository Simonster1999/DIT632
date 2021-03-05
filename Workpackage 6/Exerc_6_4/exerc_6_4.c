/*====================================
File name : exerc_6_4.c
Date : 2021 - 03 - 05
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [PZU6-9MDJ-TCWT-F4XY]
====================================== */

//include section
#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//function section
void *time_count();
void *read_inport();
double get_time_ms();

//variables section
int count;            //used in main to compare with program_time
int countPrint = 5;   //used in main to compare with program_time
int program_time;     
double ms;            //used to get get_time_ms() as soon as the program starts

/**
 * This program runs three threads including main, that prints the program time in the console every second,
 * and every 5 second prints "Reading Inport now"
 *
 * Purpose: Demonstration of Exerc_6_4
 * DIT632
 *
 * Author: Simon Engström, 2021
 *
**/

int main()
{
    //gets the current time in ms as soon as the program starts
    ms = get_time_ms();

    //create IDs for each of the threads
    pthread_t ptrThread0, ptrThread1;

    //creating the threads
    pthread_create(&ptrThread0, NULL, time_count, NULL);
    pthread_create(&ptrThread1, NULL, read_inport, NULL);

    while (program_time < 50)
    {
        //both program_time and count start at 0, program_time increases by 1 every second in the time_count() function
        //this if-statement will then be true once every second and print the current value of program_time
        if (program_time > count)
        {
            count = count + 1;
            printf("%d ", program_time);
        }
    }
}

//increases program_time by 1 every second
void *time_count()
{
    while (program_time < 50)
    {
        //uses ms as a starting point, checks to see if a second has passed
        if (get_time_ms() >= ms + 100)
        {
            program_time = program_time + 1;
            ms = get_time_ms();
        }
    }
    pthread_exit(0);
}

//prints "Reading Inport now" in the console every 5 seconds
void *read_inport()
{
    while (program_time < 50)
    {
        //compares program_time to countPrint, if program_time has reached 5 seconds countPrint will increase by 5, and
        //"Reading Inport now" will be printed to the console
        if (program_time >= countPrint)
        {
            countPrint = countPrint + 5;
            printf("\nReading Inport now\n");
        }
    }
    pthread_exit(0);
}

double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}