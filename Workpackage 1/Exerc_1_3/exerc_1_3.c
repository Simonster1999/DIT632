// Include section
#include <stdio.h>
#define ROT 13

// Main program section

/**
* This program accepts a string and encrypts the letters of that string using ROT13.
* If the letter is in the first half of the alphabet, it translates it into the letter
* exactly 13 places ahead of it in the order of the alphabet.
* If it's in the second half, it translates it into the letter 13 places behind.
* The program prints the translated string for the user to see, and keeps accepting 
* strings until the user enters EOF (Ctrl + z)
*  
* 
* Purpose: Demonstration of Exerc_1_3
* DIT632
* 
**/

int main(void)
{
    
    char inputString[20]; // empty string for user inputs to be stored in

    while (1) { // loops until EOF is entered
        
        printf("Enter the text you would like to encrypt or press ctrl + Z to exit\n"); // print instructions to the console to prompt the user to enter text
        scanf("%20s", inputString); // read user input and store it in inputString
        char outputString[20];  // empty string for storing encrypted version of inputString

        if (inputString[0] == EOF) { // stop program if user enters EOF
            break;
        }
        
        // algorithm for encrypting input
        for (int i = 0; i < (sizeof(inputString)); i++) { 
            int a = inputString[i]; // this variable is always equal to the current index in the for loop
            int b;  // variable for comparing the current letter's place in the alphabet
            if (a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z') { // the following logic applies only to inputs that are in the ranges 'A' to 'Z' or 'a' to 'z'
                if ((b = a + ROT) <= 'Z' || (b = a + ROT) <= 'z') // if a + 13 is less than 'Z' or 'z', assign the letter 13 places ahead of a to b.
                    outputString[i] = b;    // turn the current index into b

                else    // otherwise, assign the letter 13 places behind a to the variable b
                {
                    b = a - ROT;
                    outputString[i] = b;
                }

            }
            else    // for any index in the input that doesn't correlate to a letter in the alphabet, let it pass through as it is, without encryption
            {
                outputString[i] = a;
            }
        }
        printf("%s\n", outputString); // print result

    }
    return 0;
}
