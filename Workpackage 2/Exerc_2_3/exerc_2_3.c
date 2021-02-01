#include <stdio.h>
#include <string.h>

int cmp();
int nocmp();

int main()
{
	cmp();
	nocmp();
}

int cmp() {
	char a[] = "Hello";
	char b[] = "Hiya";
	int comparison = strcmp(a, b);
	if (comparison == 0) {
		printf("String a and string b are equal.\n");
	}
	else {
		printf("String a and string b are not equal.\n");
	}
}

int nocmp() {
	char a[] = "Hello";
	char b[] = "Hello";
	int isequal;
	for (int i = 0; i < (sizeof(a)); i++) {
		if (a[i] == b[i]) {
			isequal = 1;
		}
		else {
			isequal = 0;
		}
	}
	if (isequal == 1) {
		printf("String a and string b are equal.");
	}
	else {
		printf("String a and string b are not equal.");
	}
}