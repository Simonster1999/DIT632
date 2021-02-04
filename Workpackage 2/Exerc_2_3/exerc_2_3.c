// include section
#include <stdio.h>
#include <string.h>

// function declaration
int cmp();
int nocmp();

// Main program section

/**
 * This program receives strings and checks whether they are equal or not.
 *
 *
 * Purpose: Demonstration of Exerc_2_3
 * DIT632
 *
 * Author: Emil Gustafsson, 2021
 *
**/

int main(int argc, char* argv[])
{
	// ./exerc_2_3.exe hello world		must be compiled before, .exe must exsist
	// printf("%s", argv[1]);
	// printf("%d", (int) argc);
	if (argc == 3) {
		cmp(argv[1], argv[2]);
		nocmp(argv[1], argv[2]);
	} else {
		printf("Must write excatly two strings");
	}
	
}

// compare strings using strcmp
int cmp(char* input, char* input2) {
	//char a[] = "Hello";
	//char b[] = "Hiya";
	// compare string a to b
	int comparison = strcmp(input, input2);
	// print this if strcmp returns 0
	if (comparison == 0) {
		printf("These strings are equal.\n");
	}
	// print this if strcmp returns -1 or 1
	else {
		printf("These strings are not equal.\n");
	}
}

// compare strings without using strcmp
int nocmp(char* input, char* input2) {
	//char a[] = "Hello";
	//char b[] = "Hello";
	int isequal = 1;
	// loop through every letter of  the string
	//for (int i = 0; i < (sizeof(input[0])); i++) {
		// compare every corresponding letter in the other string to current index and set isequal to 1 if they are the same
	if (sizeof(input) == sizeof(input2)) {
		for (int i = 0; i < sizeof(input); i++) {
			if (input[i] != input2[i]) {
				isequal = 0;
			}
			// if they aren't the same, set isequal to 0 and break out of the loop
		}
	} else {
		isequal = 0;
	}
	
	// print this if isequal equals 1
	if (isequal == 1) {
		printf("These strings are equal.");
	}
	// print this if isequal equals any other value
	else {
		printf("These strings are not equal.");
	}

	
}