//include section
#include <stdio.h>
#include <string.h>

enum DIRECTION { N, E, S, W };
typedef struct {
	int xpos;
	int ypos;
	enum DIRECTION dir;
} ROBOT;

//function declaration
void move(int* x, int* y, enum DIRECTION* d);
void turn(enum DIRECTION* d);

//main program section
void main() {
	ROBOT rob;
	rob.xpos = 0;
	rob.ypos = 0;
	rob.dir = N;
	char movement[20];

	while (1) {
		printf("\nPlease enter the robot's starting x position (0-99): ");
		scanf("%d", &rob.xpos);
		if (rob.xpos < 0 || rob.xpos > 99) {
			printf("\nInvalid x position.");
			continue;
		}
		else {
			printf("\nPlease enter the robot's starting y position (0-99): ");
			scanf("%d", &rob.ypos);
			if (rob.ypos < 0 || rob.ypos > 99) {
				printf("\nInvalid y position.");
				continue;
			}
			else {
				printf("\nPlease enter movement combination: ");
				scanf("%20s", movement);

			}

		}

		for (int i = 0; i < (strlen(movement)); i++) {
			if (movement[i] == 'm' || movement[i] == 'M') {
				printf("\nMoving one step forward");
				move(&rob.xpos, &rob.ypos, &rob.dir);
			}
			else if (movement[i] == 't' || movement[i] == 'T') {
				printf("\nTurning 90 degrees");
				turn(&rob.dir);
			}
			else {
				printf("\n%c is an invalid character.", movement[i]);
			}
		}
		printf("\nThe robot moved to: \nx: %d\ny: %d\n", rob.xpos, rob.ypos);
	}
}

void move(int* x, int* y, enum DIRECTION* d) {
	if (*d == N) {
		if (*y < 99) (*y)++;
	}
	else if (*d == E) {
		if(*x < 99) (*x)++;
	}
	else if (*d == S) {
		if(*y > 0) (*y)--;
	}
	else if (*d == W) {
		if(*x > 0 ) (*x)--;
	}
}

void turn(enum DIRECTION* d) {
	if (*d == 0) {
		*d = 1;
	}
	else if (*d == 1) {
		*d = 2;
	}
	else if (*d == 2) {
		*d = 3;
	}
	else if (*d == 3) {
		(*d) = 4;
	}
}