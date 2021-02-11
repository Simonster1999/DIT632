/*====================================
File name : exerc_3_3.c
Date : 2021 - 02 - 11
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [QEGF-Z6Z6-5V4G-WULS]
====================================== */

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5           // the initial number of records in the list upon creation

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
void print_list(REGTYPE* cur_post);

/**
 * This program demostraits how to create a doubly linked list of structs
 * using pointers and how to update and read integers inside structs.
 * First the program creates the list of five records then it adds a new record
 * to the beginning of the list.
 * 
 * Purpose: Demonstration of Exerc_3_3
 * DIT632
 * 
 * Author: Mattias Ekdahl, 2021
 * 
**/

//###### Main program #######
int main(int argc, char *argv[])
{
    REGTYPE *cur_post, 
            *head = NULL; // stores the pointer to the first record of the linked list
    srand(time(0)); //   Random seed
    
    // creates a new list of records and assigns the first records pointer
    head = random_list();

    // prints each record in the list, tests that the list was created
    print_list(head);

    // add a new record first to the list, assigns head with the new first record pointer
    head = add_first(head, rand() % 101);

    // prints each record in the list, tests that the list was updated
    print_list(head);

    // --- Free of allocated memory  ---
    while ((cur_post = head) != NULL)
    {
        head = cur_post->next;
        free(cur_post);
    } 
    
    //------------------                   
    return 0;
}
// ====     End of main   ======================================

REGTYPE* random_list(void){
    
    REGTYPE *top,   // first record pointer
            *old,   // previous record pointer
            *item;  // current record pointer
    
    // creates MAX records and links them together in a doubly linked list
    for(int i = 0; i < MAX; i++) {

        // allocating memory for the new record
        item = malloc(sizeof(REGTYPE)); // new record

        // gives number a random value between 0 and 100
        item->number = rand() % 101;

        // special case for first record
        if (i == 0) {

            // keep track of the first record
            top = item;
            // first record should not have a previous record
            old = NULL;
        }
        
        // set prev of the current record to old, which is either the previous record or NULL
        item->prev = old;
        
        if (old != NULL) {

            // set next pointer for the previous record to the current one
            // only if old is not NULL, which it is for the first record only
            old->next = item;
        }

        // point old to current record, saves the record for the next iteration
        old = item;
    }
    // last record should not have a next record
    item->next = NULL;
    
    // returns the pointer of the first record of the list
    return(top);
}

// receives the first record pointer in a linked list and a number,
// creates a new record with the number and places it first in the list
// returns the new first record pointer
REGTYPE* add_first(REGTYPE* head, int data){
    
    // allocating memory for the new record
    REGTYPE *rec = malloc(sizeof(REGTYPE)); // new record

    // assign the data value to number
    rec->number = data;

    // set the prev value for the new first record to NULL
    rec->prev = NULL;

    // set the next value to the previous head of the list
    rec->next = head;

    // sets the prev value to the new record, making it no longer NULL
    head->prev = rec;

    // returns the pointer of the new first record in the list
    return rec;
}

// itirates over and prints a linked list from its first record to last via pointers
void print_list(REGTYPE* cur_post) {
    // code was moved to a seperate function from the main to avoid repetition 
    //  due to needing to print multiple times
    int nr = 0;
    while (cur_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, cur_post->number);
        cur_post = cur_post->next;
    }
    printf("\n");
}