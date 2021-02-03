#include <stdio.h>

int main()
{
	char inputString[] = "";
	int isPalindrome;

	printf("Enter a string to find out whether or not it's a palindrome:\n");
	gets(inputString);
	
	int start = 0;
	int end = strlen(inputString) - 1;

	for (int i = 0; i < (sizeof(inputString)); i++) {
		if (inputString[start++] != inputString[end--]) {
			isPalindrome = 0;
		}
		else {
			isPalindrome = 1;
		}
	}
	if (isPalindrome == 0) {
		printf("This string is not a palindrome.\n");
	}
	else {
		printf("This string is a palindrome.\n");
	}
	return 0;
}