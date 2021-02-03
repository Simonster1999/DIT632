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

int main()
{
	cmp();
	nocmp();
}

// compare strings using strcmp
int cmp() {
	char a[] = "Hello";
	char b[] = "Hiya";
	// compare string a to b
	int comparison = strcmp(a, b);
	// print this if strcmp returns 0
	if (comparison == 0) {
		printf("String a and string b are equal.\n");
	}
	// print this if strcmp returns -1 or 1
	else {
		printf("String a and string b are not equal.\n");
	}
}

// compare strings without using strcmp
int nocmp() {
	char a[] = "Hello";
	char b[] = "Hello";
	int isequal;
	// loop through every letter of  the string
	for (int i = 0; i < (sizeof(a)); i++) {
		// compare every corresponding letter in the other string to current index and set isequal to 1 if they are the same
		if (a[i] == b[i]) {
			isequal = 1;
		}
		// if they aren't the same, set isequal to 0 and break out of the loop
		else {
			isequal = 0;
			break;
		}
	}
	// print this if isequal equals 1
	if (isequal == 1) {
		printf("String a and string b are equal.");
	}
	// print this if isequal equals any other value
	else {
		printf("String a and string b are not equal.");
	}
}