#include <stdio.h>

int MAX = 100;
int countWords(char[]);
char *userInput();

void main()
{
    printf("%d", countWords(userInput()));
}

char *userInput()
{
    char *words;
    char inputValue[MAX];
    
    printf("%s", "Write something: \n");
    fgets(inputValue, sizeof inputValue, stdin);
    words = inputValue;

    return words;
}

int countWords(char value[])
{
    int nr_of_words = 0;
    int i = 0;
    
    while (value[i] != '\0')
    {
        if (value[i] == ' ')
        {
            nr_of_words++;
        }
        i++;
    }
    return nr_of_words + 1;
}

