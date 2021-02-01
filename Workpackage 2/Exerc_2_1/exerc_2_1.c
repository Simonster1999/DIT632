#include <stdio.h>
#include <string.h>
//#include <unistd.h>

#define MAX 20

void copyString(char* target, char* origin);

void main() {

    /*int a = 1;

    int* b = &a; // pointer b points to a's address

    *b = 2;     // assign value 2 to the part of memory b points to (a)

    printf("%d\n", a); // value
    printf("%d\n", b); // address
    printf("%d", *b);  // value*/
    char mode;
    char str[MAX];
    char strCopy[MAX];
    char cwd[1024];
    //getcwd(cwd, sizeof(cwd));
    //printf("%s", cwd);
    printf("\nDo you wish to read from a file? yes (y), no (n)\n");
    scanf("%s", &mode);

    if (mode == 'y') {  // read from file
        
        FILE* fileP;

        char* fileN = "C:\\Users\\Mattias\\dit632\\Workpackage 2\\Exerc_2_1\\myfile.txt";

        fileP = fopen(fileN, "r");

        if (fileP != NULL) {

            fgets(str, MAX + 1, fileP); // includes EOF, only 19 read
            
        } else {
            printf("Could not open file\n");
        }
        fclose(fileP);
    }
    else {              // read from console
        printf("Type the string to copy: ");
        scanf("%20s", str);
    }

    strcpy(strCopy, str);
    printf("strcpy: %s\n", strCopy);

    strCopy[0] = '\0';  // make the two strings unequal again, only the first index though

    copyString(strCopy, str);
    printf("copyString: %s\n", strCopy);
}

void copyString(char* target, char* origin) {

    for(int i = 0; i < MAX; i++) {

        if (*origin != '\0') {

            //target[i] = origin[i];    // loop through both arrays
            *target = *origin;
            origin++, target++; // index pointers

        } else {
            break;
        }
    }
}
