#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
        
    // ./code 1 1 1 1 1
    // check for exactly 5 arguments
    if (argc == 6) {
        
        unsigned char byte;
        int sum[5];
        
        //atoi(argv[1]) -> a-Z == 0
        for (int i = 0; i < 5; i++) {

            sum[i] = (int) *argv[i + 1] - 48;
            //sum[i] = atoi(argv[i + 1]);

            // check if below 0
            if (sum[i] < 0) exit(1);
        }

        // within range
        if (sum[0] != 0 && sum[0] != 1) exit(1);
        if (sum[1] >  4) exit(1);
        if (sum[2] >  2) exit(1);
        if (sum[3] != 0 && sum[3] != 1) exit(1);
        if (sum[4] != 0 && sum[4] != 1) exit(1);

        // [128] [64 32 16] [8 4] [2] [1], bit grouped together
        // moving values to proper position in binary number then converted to decimal
        byte = (sum[0] * 128 
                + sum[1] * 16
                + sum[2] * 4
                + sum[3] * 2
                + sum[4]);

        // print as uppercase hexadecimal
        printf("%X", byte);
    }
    else {
        printf("Error");
        exit(1);
    }
}
