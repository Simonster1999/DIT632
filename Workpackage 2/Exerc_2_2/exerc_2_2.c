#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10
#define UPPER 99
#define LOWER 1

int sum(int* array, int size);

void main() {

    srand(time(0));

    int array[MAX];

    for(int i = 0; i < MAX; i++) {
        array[i] = rand() % UPPER + LOWER;
    }

    printf("\nThe value of the label array (address) is: %p", &array);
    printf("\nFirst integer in the array is (array[0]) : %d", array[0]);
    printf("\nThe size of an integer (number of bytes) is : %d", sizeof(array[0]));
    printf("\nThe size of the whole array is : %d", sizeof(array));
    printf("\nThe sum of the all values is : %d\n", sum(array, MAX));

    for(int i = 0; i < MAX; i++) {
        int* num = &array[i];
        printf("[%i] value: %d, double: %d\n", i, *num, *num * 2);
    }

}

int sum(int* array, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += *array;
        array++;
    }
    return sum;
}
