#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----Typedefs -------
typedef struct PERSON
{
  char firstname[20];
  char famnamne[20];
  char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void);             // Reads in a person record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(void);                  // print out all persons in the file
void search_by_firstname(char *name);  // print out person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file
void search_by_lastname(char *name);

int main(void)
{
  int ans;
  char name[20];
  PERSON input;
  PERSON ppost;
  strcpy(ppost.firstname, "Dummy");
  strcpy(ppost.famnamne, "LastName");
  strcpy(ppost.pers_number, "123456");
  int userInput;

  printf("\n***Person Register***\n1. Write new File \n2. Register person \n3. Search Person \n4. List all registered persons\n5. Exit\n");

  scanf("%d", &userInput);

  switch (userInput)
  {
  case 1:
    write_new_file(&ppost);
    main();
    break;
  case 2:
    printf("Enter first name: \n");
    scanf("%20s", input.firstname);
    printf("Enter last name: \n");
    scanf("%20s", input.famnamne);
    printf("Enter SSN: \n");
    scanf("%13s", input.pers_number);
    append_file(&input);
    main();
    break;
  case 3:
    printf("Search by first name(1), or Search by last name(2)?");
    scanf("%d", &ans);
    if (ans == 1)
    {
      printf("Type in the name to search for: \n");
      scanf("%20s", name);
      strtok(name, "\n");
      search_by_firstname(name);
    }
    else if (ans == 2)
    {
      printf("Type in the name to search for: \n");
      scanf("%20s", name);
      strtok(name, "\n");
      search_by_lastname(name);
    }
    else
    {
      printf("Invalid input");
    }
    main();
    break;
  case 4:
    printfile();
    main();
    break;
  case 5:
    break;
  default:
    main();
  }
}

void write_new_file(PERSON *inrecord)
{
  FILE *file;
  char *fileName = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register.txt";

  file = fopen(fileName, "wb");

  if (file != NULL)
  {
    fwrite(inrecord, sizeof(struct PERSON), 1, file);
  }
  else
  {
    printf("ERROR");
  }
  fclose(file);
}

void append_file(PERSON *inrecord)
{
  FILE *file1;
  char *fileName1 = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register.txt";
  FILE *file2;
  char *fileName2 = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register2.txt";
  PERSON temp;

  file1 = fopen(fileName1, "ab");
  file2 = fopen(fileName2, "wb");

  if (file1 != NULL && file2 != NULL)
  {
    fwrite(inrecord, sizeof(struct PERSON), 1, file2);
    fclose(file2);
    file2 = fopen(fileName2, "rb");
    fread(&temp, sizeof(PERSON), 1, file2);
    fwrite(&temp, sizeof(PERSON), 1, file1);
  }
  else
  {
    printf("ERROR");
  }
  fclose(file1);
  fclose(file2);
  remove("C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register2.txt");
}

void printfile()
{
  FILE *file;
  char *fileName = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register.txt";
  PERSON temp;

  file = fopen(fileName, "rb");

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)
    {
      printf("%20s %20s %20s \n", temp.firstname, temp.famnamne, temp.pers_number);
    }
  }
  else
  {
    printf("ERROR");
  }
  fclose(file);
}

void search_by_firstname(char *name)
{
  PERSON temp;
  FILE *file;
  char *fileName = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register.txt";

  file = fopen(fileName, "rb");

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)
    {
      if (strcmp(temp.firstname, name) == 0)
      {
        printf("%20s %20s %20s \n", temp.firstname, temp.famnamne, temp.pers_number);
      }
    }
  }
  else
  {
    printf("ERROR");
  }
  fclose(file);
}

void search_by_lastname(char *name)
{
  PERSON temp;
  FILE *file;
  char *fileName = "C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register.txt";

  file = fopen(fileName, "rb");

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)
    {
      if (strcmp(temp.famnamne, name) == 0)
      {
        printf("%20s %20s %20s \n", temp.firstname, temp.famnamne, temp.pers_number);
      }
    }
  }
  else
  {
    printf("ERROR");
  }
  fclose(file);
}