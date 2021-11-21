/*====================================
File name : exerc_3_1.c
Date : 2021 - 02 - 11
Group nr 7
Members that contribute to the solutions
Emil Gustafsson
Simon Engström
Mattias Ekdahl
Member not present at demonstration time :
---
Demonstration code : [QEGF-Z6Z6-5V4G-WULS]
====================================== */

//include section
#include <stdio.h>
#include <string.h>

//declare directional values
enum DIRECTION { N, E, S, W };
//declare structure for the robot
typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

//function prototyping
void move(int* x, int* y, enum DIRECTION* d);
void turn(enum DIRECTION* d);

//main program section

/**
 * This program simulates a robot that can move based on user input.
 *
 *
 * Purpose: Demonstration of Exerc_3_1
 * DIT632
 *
 * Author: Emil Gustafsson, 2021
 *
**/
void main() {
	//declare the robot rob
	ROBOT rob;
	//declare default values for the robot's variables
	rob.xpos = 0;
	rob.ypos = 0;
	rob.dir = N;
	//string for movement combination input
	char movement[20];

	//the main loop that calls the functions and takes input to operate on
	while (1) {
		printf("\nPlease enter the robot's starting x position (0-99): ");
		//receive x position from user input
		scanf("%d", &rob.xpos);
		//to prevent invalid coordinates; if x position is not in the range 0-99, go back to the beginning of the loop.
		if (rob.xpos < 0 || rob.xpos > 99) {
			printf("\nInvalid x position.");
			continue;
		}
		//if x input is valid, proceed to ask user for y input
		else {
			printf("\nPlease enter the robot's starting y position (0-99): ");
			//receive y position from user input
			scanf("%d", &rob.ypos);
			//if y position is not in the range 0-99, go back to the beginning of the loop.
			if (rob.ypos < 0 || rob.ypos > 99) {
				printf("\nInvalid y position.");
				continue;
			}
			//if y input is valid, ask user for movement combination input
			else {
				printf("\nPlease enter movement combination: ");
				scanf("%20s", movement);

			}

		}
		// operate on each character in the movement input, one by one
		for (int i = 0; i < (strlen(movement)); i++) {
			// do this if the current character is 'm' or 'M'
			if (movement[i] == 'm' || movement[i] == 'M') {
				printf("\nMoving one step forward");
				//call the move function with rob's x position, y position and direction as arguments
				move(&rob.xpos, &rob.ypos, &rob.dir);
			}
			// do this is the current character is 't' or 'T'
			else if (movement[i] == 't' || movement[i] == 'T') {
				printf("\nTurning 90 degrees");
				//call the turn function with rob's direction as argument
				turn(&rob.dir);
			}
			// in the case that a character in the string is anything other than what the previous logic checks for, ignore it and operate on the next character
			else {
				printf("\n%c is an invalid character.", movement[i]);
			}
		}
		// display result of the movement input
		printf("\nThe robot moved to: \nx: %d\ny: %d\n", rob.xpos, rob.ypos);
	}
	// loop back to get new starting position, as per the assignment description
}

// this function changes the x and y position based on input
void move(int* x, int* y, enum DIRECTION* d) {
	// if direction is north, increase y position by 1
	if (*d == N) {
		// only increment if y is less than 99
		if (*y < 99) (*y)++;
	}
	// if direction is east, increase x position by 1
	else if (*d == E) {
		// only increment if x is less than 99
		if(*x < 99) (*x)++;
	}
	// if direction is south, decrease y position by 1
	else if (*d == S) {
		// only decrease if y position is greater than 0
		if(*y > 0) (*y)--;
	}
	// if direction is west, decrease x position by 1
	else if (*d == W) {
		// only decrease if x position is greater than 0
		if(*x > 0 ) (*x)--;
	}
}

// this function changes the direction of the robot
void turn(enum DIRECTION* d) {
	// if direction is north, change direction to east
	if (*d == 0) {
		*d = 1;
	}
	// if direction is east, change direction to south
	else if (*d == 1) {
		*d = 2;
	}
	// if direction is south, change direction to west
	else if (*d == 2) {
		*d = 3;
	}
	// if direction is west, change direction to north
	else if (*d == 3) {
		(*d) = 4;
	}
}