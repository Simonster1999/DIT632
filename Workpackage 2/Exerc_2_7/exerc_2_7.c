#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void readPersnr(char* person);
int controlDigit(const char* persnr);

void main() {
    
    char spn[MAX];

    while (1) {

        readPersnr(spn);

        if (spn[0] == 'q') {
            exit(1);
        }

        if (controlDigit(spn) == (int) spn[9] - 48) {
            printf("%s is a valid swedish person number", spn);
        }
        else {
            printf("%s is an invalid swedish person number", spn);
        }
        printf("\n");
    }
}

void readPersnr(char* person) {

    printf("\nEnter a person number: ");
    scanf("%10s", person);
}

int controlDigit(const char* persnr) {

    int spn[MAX], 
        mon,  
        day,
        sum = 0;

    for (int i = 0; i < MAX; i++) {

        if ((int) *persnr - 48 < 0 || (int) *persnr - 48 > 9) {
            exit(1);
        }
        spn[i] = (int) *persnr - 48;
        persnr++;
    }
    
    mon = spn[2] * 10 + spn[3];
    day = spn[4] * 10 + spn[5];

    if (mon > 0 && mon < 13) {
        if (mon == 2) {
            if (day < 1 || day > 29) {
                printf("Invalid day");
                exit(1);
            }
        } 
        else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
            if (day < 1 || day > 30) {
                printf("Invalid day");
                exit(1);
            }
        }
        else {
            if (day < 1 || day > 31) {
                printf("Invalid day");
                exit(1);
            }
        }
    }
    else {
        printf("Invalid month");
        exit(1);
    }

    for (int i = 0; i < MAX - 1; i++) {

        if (i % 2 == 0){
            
            if (spn[i] * 2 > 9) {
                sum += spn[i] * 2 - 9;
            }
            else {
                sum += spn[i] * 2;
            }
        }
        else {
            sum += spn[i];
        }
    }
    
    if (sum % 10 == 0) {
        return 0;
    }
    else {
        return 10 - sum % 10;
    }
}