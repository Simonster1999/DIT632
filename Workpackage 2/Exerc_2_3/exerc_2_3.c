/*====================================
File name : exerc_2_3.c
Date : 2021 - 02 - 04
Group nr 7
Members that contribute to the solutions
Emil Gustafsson
Mattias Ekdahl
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [FQ74-RF3M-MB8V-45W6]
====================================== */

// include section
#include <stdio.h>
#include <string.h>

// function declaration
void cmp(char *input, char *input2);
void nocmp(char *input, char *input2);

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

// main receives strings from command line and stores them in argv. argc keeps track of how many strings
void main(int argc, char *argv[])
{
	// ./exerc_2_3.exe hello world		must be compiled before, .exe must exist
	// checks argc passed into main, and if it's exactly 3, run the two functions (3, not 2 because file name counts as a passed string)
	if (argc == 3)
	{
		// the second and third string is passed into the functions
		cmp(argv[1], argv[2]);
		nocmp(argv[1], argv[2]);
		// program ends if argc is not exactly 3
	}
	else
	{
		printf("Must write exactly two strings");
	}
}

// compare strings using strcmp
void cmp(char *input, char *input2)
{
	// variable containing the comparison between the strings
	int comparison = strcmp(input, input2);
	// print this if strcmp returns 0
	if (comparison == 0)
	{
		printf("These strings are equal.\n");
	}
	// print this if strcmp returns -1 or 1
	else
	{
		printf("These strings are not equal.\n");
	}
}

// compare strings without using strcmp
void nocmp(char *input, char *input2)
{
	int isequal = 1;
	// loop through every letter of  the string
	// compare every corresponding letter in the other string to current index and set isequal to 1 if they are the same
	if (sizeof(input) == sizeof(input2))
	{
		for (int i = 0; i < sizeof(input); i++)
		{
			if (input[i] != input2[i])
			{
				isequal = 0;
			}
			// if they aren't the same, set isequal to 0
		}
	}
	else
	{
		isequal = 0;
	}

	// print this if isequal equals 1
	if (isequal == 1)
	{
		printf("These strings are equal.");
	}
	// print this if isequal equals any other value
	else
	{
		printf("These strings are not equal.");
	}
}