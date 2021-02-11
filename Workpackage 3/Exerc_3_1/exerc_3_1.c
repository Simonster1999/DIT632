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
void move(int *x, int *y, enum DIRECTION *d);
void turn(enum DIRECTION *d);

//main program section
void main() {
	ROBOT rob;
	rob.xpos = 0;
	rob.ypos = 0;
	rob.dir = N;
	char movement[20];

	while (1) {
		printf("\nPlease enter the robot's starting x position (0-99):");
		scanf("%d", &rob.xpos);
		printf("\nPlease enter the robot's starting y position (0-99):");
		scanf("%d", &rob.ypos);
		printf("\nPlease enter movement combination\n");
		scanf("%20s", movement);

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

void move(int *x, int *y, enum DIRECTION *d) {
	if (*d == N) {
		(*y)++;
	}
	else if (*d == E) {
		(*x)++;
	}
	else if (*d == S) {
		(*y)--;
	}
	else if (*d == W) {
		(*x)--;
	}
}

void turn(enum DIRECTION *d) {
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