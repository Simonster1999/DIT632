// Program for exercise 6.2alt in DIT632
// Version 2020-02-12
// File : sortandfind_20.c
// **************************************
#include <stdio.h>
#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;
int search;

void* runner0(void* param);
void* runner1(void* param);
void* runner2(void* param);

int main() {
	time_t t;
	pthread_t tid0;
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr;

	srand((unsigned)time(&t));
	pthread_attr_init(&attr);

	printf("Enter max value\n");
	scanf("%d", &max_value);

	printf("Enter value to find\n");
	scanf("%d", &search);

	pthread_create(&tid0, &attr, runner0, NULL);
	pthread_join(tid0, NULL);

	pthread_create(&tid1, &attr, runner1, NULL);
	pthread_join(tid1, NULL);

	pthread_create(&tid2, &attr, runner2, NULL);
	pthread_join(tid2, NULL);

	return 0;
}

void* runner0(void* param) {
	printf("Generating numbers.");
	int c = 0, n = 0;

	for (c = 0; c < num_elems; c++) {
		for (n = 0; n < 1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}

	pthread_exit(0);
}

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

void* runner2(void* param) {
	printf("\nFinding number.");
	int first = 0;
	int last = num_elems - 1;
	int middle = (first + last) / 2;
	int n;
	for (n = 0; n < num_elems; n++) {
		printf("\n %d", array[n]);
	}

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
	if (first > last)
		printf("\n Not found! %d is not present in the list.\n", search);
}