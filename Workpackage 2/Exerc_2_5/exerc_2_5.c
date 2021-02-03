// include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant section
#define MAX 100
#define MAXNUMBER 20

//function declaration
void create_random(int *tab);
void count_frequency(int *tab, int *freq);
void draw_histogram(int *freq);

// Main program section

/**
 * This program generates 100 random numbers and displays the frequency of each number in a list.
 * 
 * 
 * Purpose: Demonstration of Exerc_2_5
 * DIT632
 * 
 * Author: Emil Gustafsson, 2021
 * 
**/

int main(void) {
	int table[MAX], n;  // array to put generated random numbers in
	int frequency[MAXNUMBER];   // array to store the frequency of each number

	create_random(table);
	count_frequency(table, frequency);
	draw_histogram(frequency);
}

// this function generates random numbers and stores them in the table array
void create_random(int *tab) {
	srand(time(0));
    // put one random number between 0 and MAXNUMBER into each index of the array
	for (int i = 0; i < MAX; i++) {
		tab[i] = rand() % MAXNUMBER;
	}
}

// this function stores the frequency of each value in the array
void count_frequency(int *tab, int *freq) {
	int count = 0; // this integer will increment by 1 for each time the same element appears in the array
    // compare every index to every other index
	for (int i = 0; i < MAXNUMBER; i++) {
        // set count to 0 every time this loops
		count = 0;
		for (int j = 0; j < MAX; j++) {
            // if-statement checks for indexes with values equal to i, and if one is found, count is increased by 1
			if (tab[j] == i) {
				count++;
			}
		}
        // set value of current index to count
		freq[i] = count;
	}
}

// this function displays the numbers and their frequencies in a list
void draw_histogram(int *freq) {
	char x = 'x';
	printf("\n");
    // loop through all frequency values
	for (int i = 0; i < MAXNUMBER; i++) {
        // any value that has a frequency of 0 will not be printed
		if (freq[i] != 0) {
            // display the value of current index
			printf("\n%d: ", i);
            // display one 'x' for how many times said value appears
			for (int j = 0; j < freq[i]; j++) {
				printf("%c", x);
			}
		}
	}

}