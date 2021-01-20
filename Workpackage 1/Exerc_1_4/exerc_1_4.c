#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 
const int MAX_NUMBER = 10;

// 
const int RAND_NUM_UPPER = 100;
const int RAND_NUM_LOWER = 1;

void main() {

    // 
    srand(time(0));

    int play = 1;
    int rand_num;
    int guess = RAND_NUM_LOWER - 1; // 
    int guess_counter;

    printf("\nWelcome to Guess the number\n");

    while (play == 1) {

        // 
        rand_num = rand() % RAND_NUM_UPPER + RAND_NUM_LOWER;
        guess_counter = 0; // 

        while (guess != rand_num && guess_counter <= MAX_NUMBER) {
            
            printf("Guess the number: ");
            scanf("%d", &guess); // 
            printf("\n");

            // 
            if (guess < RAND_NUM_LOWER || guess > RAND_NUM_UPPER) {
                printf("Your guess must be within the range %d ...%d\n", RAND_NUM_LOWER, RAND_NUM_UPPER);
            } else if (guess > rand_num) {
                printf("Your guess is to high\n");
            } else if (guess < rand_num) {
                printf("Your guess is to low\n");
            }
            guess_counter++;
        }
        if (guess_counter > MAX_NUMBER) {
            printf("The max number of guesses has been reached. The number was: %d\n", rand_num);
        } else {
            printf("You have guessed %d times and your guess is correct\n", guess_counter);
        }
        printf("Would you like to play again? Yes (1), no (0)\n");
        scanf("%d", &play);
    }
}
