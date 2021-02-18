#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define engine_on 0b10000000
#define gear_pos  0b01110000
#define key_pos   0b00001100
#define brake1    0b00000010
#define brake2    0b00000001

void main(int argc, char *argv[]) {
    // ./decode ab
    if (argc == 2) {

        unsigned char num;

        for (int i = 0; i < strlen(argv[1]); i++) {

            // check if argument is not 0-9 and a-f and A-F i. e. not a valid hexadecimal value
            if ((argv[1][i] < 48 || argv[1][i] > 57) &&
                (argv[1][i] < 97 || argv[1][i] > 102) &&
                (argv[1][i] < 65 || argv[1][i] > 70)) {

                printf("Invalid hexadecimal number provided\n");
                exit(1);
            }
        }

        // turns a string into a hexadecimal integer
        num = (int) strtol(argv[1], NULL, 16);

        // 203 is max number possible
        if (num < 204) {

            // filter bits and check if values are within 
            //  gear_pos and key_pos ranges specified in Exerc_4_1
            if ((num & 0b01110000) < 65 && (num & key_pos) < 9) {

                printf("\nName\t\tValue\n");
                printf("---------------------\n");

                // filter bits for each value and shift right
                printf("engine_on\t%d\n", (num & engine_on) >> 7);
                printf("gear_pos\t%d\n",  (num & gear_pos) >> 4);
                printf("key_pos\t\t%d\n", (num & key_pos) >> 2);
                printf("brake1\t\t%d\n",  (num & brake1) >> 1);
                printf("brake2\t\t%d\n",   num & brake2);
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
