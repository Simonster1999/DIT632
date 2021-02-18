#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {
        
    // ./code 1 1 1 1 1
    // check for exactly 5 arguments
    if (argc == 6) {
        
        unsigned char byte;
        int sum[5];

        for (int i = 0; i < 5; i++) {

            sum[i] = (int) *argv[i + 1] - 48;
        }

        // within range
        if ((sum[0] != 0 && sum[0] != 1) || 
            (sum[1] >  4) || 
            (sum[2] >  2) || 
            (sum[3] != 0 && sum[3] != 1) || 
            (sum[4] != 0 && sum[4] != 1)) {

            printf("Invalid number provided, number out of allowed ranges\n");
            exit(1);
        }

        // [128] [64 32 16] [8 4] [2] [1], bits grouped together
        // when summing up the different values their position in the byte has to be taken into account
        // turning value to correct binary number then convert to decimal
        byte = (sum[0] * 128 
                + sum[1] * 16
                + sum[2] * 4
                + sum[3] * 2
                + sum[4]);

        // print as uppercase hexadecimal number
        printf("%X", byte);
    }
    else {
        printf("Must inlcude excatly 5 argument\n");
        exit(1);
    }
}
