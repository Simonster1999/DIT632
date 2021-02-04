// include section
#include <stdio.h>
#include <string.h>

// Main program section

/**
 * This program checks whether or not a string is a palindrome.
 *
 *
 * Purpose: Demonstration of Exerc_2_4
 * DIT632
 *
 * Author: Emil Gustafsson, 2021
 *
**/

int main()
{
	char inputString[10];	// string to store user input in
	int isPalindrome;

	printf("Enter a string to find out whether or not it's a palindrome:\n");
	// get user input
	gets(inputString);

	// declare variables to store start and end of the user input string
	int start = 0;
	int end = strlen(inputString) - 1;

	// compare start and end
	for (int i = 0; i < (sizeof(inputString)); i++) {
		// for every loop, increase start by 1 and decrease end by 1
		if (inputString[start] != inputString[end]) {
			// isPalindrome will be set to 0 when the loop finds a set of non-matching characters
			isPalindrome = 0;
			// break out of the loop because we know the word is not a palindrome the moment one set of characters do not match
			break;
		}
		else {
			// if the compared characters do match, set isPalindrome to 1
			isPalindrome = 1;
			start++;
			end--;
		}
	}
	// print this if isPalindrome equals 0
	if (isPalindrome == 0) {
		printf("This string is not a palindrome.\n");
	}
	// print this if isPalindrome has any other value than 0
	else {
		printf("This string is a palindrome.\n");
	}
	return 0;
}