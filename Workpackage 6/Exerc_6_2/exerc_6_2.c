/*====================================
File name : exerc_6_2.c
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
#include <stdio.h>
#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;
int search;

// create additional runners for each of the threads
void* runner0(void* param);
void* runner1(void* param);
void* runner2(void* param);

/**
 * This program generates random numbers from 0 - 200, lets the user decide the maximum possible value for said numbers
 * and then search for a particular number in the array
 *
 * Purpose: Demonstration of Exerc_6_2
 * DIT632
 *
 * Author: Emil Gustafsson, 2021
 *
**/

int main() {
	time_t t;
	// create IDs for each of the threads
	pthread_t tid0;
	pthread_t tid1;
	pthread_t tid2;

	// create attributes for each of the threads
	pthread_attr_t attr0;
	pthread_attr_t attr1;
	pthread_attr_t attr2;

	srand((unsigned)time(&t));

	// initialize each of the attributes
	pthread_attr_init(&attr0);
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);

	// user is prompted for max value and search value before the threads run
	printf("Enter max value\n");
	scanf("%d", &max_value);

	printf("Enter value to find\n");
	scanf("%d", &search);

	/* the three threads are created and are each followed by a join in order to make sure that the 
	threads finish their work before the main method executes the rest of its code. */
	// each thread prints what the current step is

	// first thread generates 200 random numbers
	pthread_create(&tid0, &attr0, runner0, NULL);
	pthread_join(tid0, NULL);

	// second thread sorts the numbers in ascending order
	pthread_create(&tid1, &attr1, runner1, NULL);
	pthread_join(tid1, NULL);

	// third thread searches for and finds the entered search value
	pthread_create(&tid2, &attr2, runner2, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

// generates random numbers and fills the array with them
void* runner0(void* param) {
	printf("Generating numbers.");
	int c = 0, n = 0;

	for (c = 0; c < num_elems; c++) {
		for (n = 0; n < 1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}

	pthread_exit(0);
}

// sorts the array in ascending order
void* runner1(void* param) {
	printf("\nSorting numbers.");
	int c, d, swap;

	for (c = 0; c < num_elems; c++) {
		for (d = 0; d < num_elems - c - 1; d++) {
			if (array[d] > array[d + 1]) {
				swap = array[d];
				array[d] = array[d + 1];
				array[d + 1] = swap;
			}
		}
	}
}

// finds the entered search value number within the array
void* runner2(void* param) {
	printf("\nFinding number.");
	int first = 0;
	int last = num_elems - 1;
	int middle = (first + last) / 2;
	int n;
	for (n = 0; n < num_elems; n++) {
		printf("\n %d", array[n]);
	}

	// compares every value in the array to the entered search value, stops after the last index has been reached or if the entered value was found
	while (first <= last) {
		if (array[middle] < search)
			first = middle + 1;
		else if (array[middle] == search) {
			printf("\n %d found at location %d.\n", search, middle + 1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	// if the algorithm reaches the end of the array without having found the entered value, print this
	if (first > last)
		printf("\n Not found! %d is not present in the list.\n", search);
}