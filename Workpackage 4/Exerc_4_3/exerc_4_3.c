/*====================================
File name : exerc_4_3.c
Date : 2021 - 02 - 19
Group nr 7
Members that contribute to the solutions
Emil Gustafsson
Mattias Ekdahl
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [VGP9-HVEG-QSCW-K7ZD]
====================================== */

// include section
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// function prototyping
void f_delay(int);
unsigned char random_inport( void);
void printport( int);
void convert(int bin[4]);

/**
 * This program simulates a key being pressed on a keyboard and outputs the hexadecimal value of the key that was pressed.
 *
 *
 * Purpose: Demonstration of Exerc_4_3
 * DIT632
 *
 * Author: Emil Gustafsson, Mattias Ekdahl 2021
 *
**/

// main method copied from the provided file.
int main(){
	int nr;
	unsigned char port;
	srand(time(0)); 
	for ( nr=0; nr < 10; nr++){   
		// generate random number.
		port = random_inport();  
		// generate bytes based on the previously generated random number.
		printport( port);   
		// delay each loop by half a second.
		f_delay(5);
	}
	return(0);
}

// delay function copied from provided file.
// generates a delay of half seconds equal to the number passed into it as an argument.
void f_delay( int tenth_sec){   
	clock_t start_t, end_t;   
	long int i;   
	start_t = clock();   
	do{      
		for(i=0; i< 10000000; i++);      
		end_t = clock();
	}while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
	return;
}

// random number generator function copied from provided file.
// generates a random number from 0 to 256 to be .
unsigned char random_inport( void){
	unsigned char inport = 0;
	inport=  rand() % 256;
	return (inport);
}

// printport function copied from the provided file.
// the function has been slightly modified to print only the bits and to call the new convert function.
// converts the random number into binary.
void printport( int portvalue){
	int binchar[8], key[4], rest,j, i=0;
	rest = portvalue;
	while(rest!=0){
		binchar[i++]= rest % 2;
		rest = rest / 2;
	}
	// fill to 8 bits
	while( i<8){
		binchar[i++]=0;
	}
	// if the 7th bit is 0, print the 8 bits and put the first 4 into the key array
	for (j = i - 1;j > -1;j--) {
		if(binchar[7] == 0) {
			printf("  %d", binchar[j]);
			if (j < 4) key[j] = binchar[j];
		}
	}
	// if the 7th bit is 0, call convert function and pass only the 4 first bits as an argument
	if (binchar[7] == 0) {
		convert(key);
		printf("\n");
	}
	return;
}

	// this function receives the first four bits from the previously generated byte
void convert(int bin[4]) {
	int key = 0, hex = 0;
	// start at last value and count down to 0
	for (int i = 3; i > -1; i--) {
		// rotate bits one step to the left
		key = key << 1;
		// add the value of current index to key
		key += bin[i];
	}
	// output the hexadecimal conversion of key
	printf("\nThe %1X-key was pressed\n", key);
}