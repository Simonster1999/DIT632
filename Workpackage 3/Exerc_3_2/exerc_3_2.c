//include section
#include <stdio.h>
#include <string.h>

//function declaration
int search_number(int number, int tab[], int size);
void sort(int tab[], int size);

//main program section
void main() {
    int n = 13;
    int test[] = {1,2,34,5,67,3,23,12,13,10};
    int length = (sizeof(test)/sizeof(test[0]));
    int existsInTable = search_number(n, test, length);
    printf("Search results:");
    if (existsInTable == -1) {
        printf("\nThe number n does not exist in the array.");
    }
    else {
        printf("\nThe number n first appears at the index %d in the array", existsInTable);
    }
    
    printf("\n\nSorting array...");
    sort(test, length);

    printf("\n\nSearch results after sorting array:");
    existsInTable = search_number(n, test, length);
    if (existsInTable == -1) {
        printf("\nThe number n does not exist in the array.");
    }
    else {
        printf("\nThe number n first appears at the index %d in the array\n", existsInTable);
    }
}

int search_number(int number, int tab[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            result = i;
            break;
        }
        else {
            result = -1;
        }
    }
    return result;
}

void sort(int tab[], int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

}