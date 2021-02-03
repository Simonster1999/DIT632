#include <stdio.h>
#include <string.h>

#define MAX 20

void copyString(char* target, char* origin);

void main() {
    
    char str[MAX];
    char strCopy[MAX];

    printf("Type the string to copy: ");
    scanf("%20s", str);
    
    strcpy(strCopy, str);
    printf("\nstrcpy: %s\n", strCopy);

    strCopy[0] = '\0';  // make the two strings unequal again, only the first index though

    copyString(strCopy, str);
    printf("copyString: %s\n", strCopy);
}

void copyString(char* target, char* origin) {

    for(int i = 0; i < MAX; i++) {

        if (*origin != '\0') {

            *target = *origin;
            origin++, target++; // index pointers
        } else {
            break;
        }
    }
}
