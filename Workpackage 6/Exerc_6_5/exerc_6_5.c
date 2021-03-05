/*====================================
File name : exerc_6_5.c
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

// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.

// Define section
#define MAX 10      //buffer size

// Global variables
char letter = 'a';  //the starting letter
unsigned short count = 0;
char buffer[MAX];   // circular buffer
int inpos = 0;      // index for next character to be put in buffer (put)
int outpos = 0;     // index for next character to be read ( fetch )

// method prototypes
void *put();
void *fetch();

// Main program section

/**
 * This progam uses two additional threads to read and write from a circular buffer
 * using mutexes to lock and unlock to prevent inconsistencies in of the shared global variables
 * 
 * Purpose: Demonstration of Exerc_6_5
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

int main() {

    // variable declarations
    pthread_t threadP, threadF;
    int i;

    // program logic

    // creates threads threadP and threadF
    pthread_create(&threadP, NULL, &put, NULL);
    pthread_create(&threadF, NULL, &fetch, NULL);

    // runs indefinitely
    while (1) {

        printf("Main is executing\n");
        
    }
}

// threadPs method
void *put() {

    // runs indefinitely
    while (1) {

        // locks the thread
        pthread_mutex_lock(&count_mutex);

        // checks if buffer is full
        if (count == MAX) {
            // waits until buffers is not full, unlocks the thread
            pthread_cond_wait(&not_full, &count_mutex);
        }

        // stores letter in buffer at inpos
        buffer[inpos] = letter;

        printf("Buffer store\n");

        // increments inpos
        inpos++;

        // increments count
        count++;

        // increments letter, changing letter to the next char in the ascii table
        letter++;

        // if the inpos has reached the last index of buffer, start over at 0
        // thereby creating a circular buffer
        if (inpos == MAX) {
            inpos = 0;
        }

        // letters should range between 'a' and 'z' (122), 
        // if the next letter is above that range reset it to 'a'
        if(letter > 122) letter = 'a';

        // signal that the buffer is not empty after having added a letter
        pthread_cond_signal(&not_empty);

        // unlock thread
        pthread_mutex_unlock(&count_mutex);
    }
}

// threadFs method
void *fetch() {

    // runs indefinitely
    while (1) {

        // locks the thread
        pthread_mutex_lock(&count_mutex);

        // if the buffer is empty of new letters
        if (count == 0) {
            // waits until buffers is not empty, unlocks the thread
            pthread_cond_wait(&not_empty, &count_mutex);
        }

        // print out buffer at outpos
        printf("Buffer output: %c\n", buffer[outpos]);

        // decrease count
        count--;

        // increments count
        outpos++;

        // if the outpos has reached the last index of buffer, start over at 0
        // thereby creating a circular buffer
        if (outpos == MAX) {
            outpos = 0;
        }

        // signal that the buffer is no longer full after having printed one letter
        pthread_cond_signal(&not_full);

        // unlocks the thread
        pthread_mutex_unlock(&count_mutex);
    }
}
