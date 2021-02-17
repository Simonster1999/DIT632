#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {

    if (argc == 2) {

        unsigned char num;

        num = (int) strtol(argv[1], NULL, 16);

        // 203 is max number possible, less than 255 aka within a byte
        if (num < 0b11001100) {

            // check if bit values are within gear_pos and key_pos specified in Exerc_4_1
            if ((num & 0b01110000) < 65 && (num & 0b00001100) < 9) {

                //printf("sum: %d\n", num);
                printf("\nName\t\tValue\n");
                printf("---------------------\n");
                printf("engine_on\t%d\n", (num & 0b10000000) >> 7);
                printf("gear_pos\t%d\n", (num & 0b01110000) >> 4);
                printf("key_pos\t\t%d\n", (num & 0b00001100) >> 2);
                printf("brake1\t\t%d\n", (num & 0b00000010) >> 1);
                printf("brake2\t\t%d\n", num & 0b00000001);
            }
            else {
                printf("Invalid number provided, number out of allowed ranges\n");
            }
        }
        else {
            printf("Invalid number provided, number too large\n");
        }
    }
    else {
        printf("Must inlcude excatly 1 argument\n");
    }
}
