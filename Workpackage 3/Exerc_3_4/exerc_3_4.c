/*====================================
File name : exerc_3_4.c
Date : 2021 - 02 - 12
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [QEGF-Z6Z6-5V4G-WULS]
====================================== */

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
void search_by_lastname(char *name);   //Searchs by last name and prints out people with that lastname

//global variables
FILE *file;
char *fileName = "Person_register.bin"; //declaring the the file name and type to use when reading and writing to file

//main program section

/**
 * This program lets you write person data to a binary file, 
 * and also let search and print the stored data in the file
 * to the console
 *
 *
 * Purpose: Demonstration of Exerc_3_4
 * DIT632
 *
 * Author: Simon Engström, 2021
 *
**/

int main(void)
{
  PERSON person;
  PERSON ppost;
  strcpy(ppost.firstname, "Dummy");    //creating a dummy record containing hardcoded info that is
  strcpy(ppost.famnamne, "LastName");  //inserted into the file upon creation
  strcpy(ppost.pers_number, "123456");
  int userInput;
  int ans;
  char name[20];

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
    scanf("%20s", person.firstname);
    printf("Enter last name: \n");
    scanf("%20s", person.famnamne);
    printf("Enter SSN: \n");
    scanf("%13s", person.pers_number);
    append_file(&person);    //creates a new record with the data the user entered in the last index in the file
    main();
    break;
  case 3:
    printf("Search by first name(1), or Search by last name(2)?\n");
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

//method that recieves a hardcoded dummy record, then either creates a binary file in the same location as the .exe, or overwrites a currently
//existing one and writes the dummy record to the file.

void write_new_file(PERSON *inrecord)
{

  file = fopen(fileName, "wb");    //here we specify that we want to open the file in write mode(w), as well an binary(b)

  if (file != NULL)                //to make sure that the file has been succsesfully open, else we print "error"
  {
    fwrite(inrecord, sizeof(struct PERSON), 1, file);
  }
  else
  {
    printf("ERROR could not open");
  }
  fclose(file);                   //we close the file once we are done
}

//method that creates a temporary file and writes a record to it, then reads from that file and appends it to the last line of our
//main file. and lastly deletes the newly created temporary file.
void append_file(PERSON *inrecord)
{
  FILE *file2;
  char *fileName2 = "Person_register2.bin";    //declaring the name and type of the temporary file
  PERSON temp;

  file = fopen(fileName, "ab");                //here we open our main file in appedning mode
  file2 = fopen(fileName2, "wb");              //and our temporary file in write mode

  if (file != NULL && file2 != NULL)           //check to see that both files open successfully
  {
    fwrite(inrecord, sizeof(struct PERSON), 1, file2);     //here we write the record to our temporary file
    fclose(file2);                                         //we then close it
    file2 = fopen(fileName2, "rb");                        //and open it again but in read mode
    fread(&temp, sizeof(PERSON), 1, file2);                //we then read the temporary file, and get the data to our temp variable
    fwrite(&temp, sizeof(PERSON), 1, file);                //we then write, or append the data from our temp variable to the last line
  }                                                        //in our main file
  else
  {
    printf("ERROR");
  }
  fclose(file);                                            //we then close both files
  fclose(file2);
  remove("C:\\Users\\Admin\\Desktop\\Ny mapp\\Person_register2.txt");     //and lastly remove the temporary file
}

//method that print all of the records in our file into the console
void printfile()
{
  PERSON temp;

  file = fopen(fileName, "rb");     //here we open the file in read mode

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)      //we read from the file, and as long as we find a record we print it to the console
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

//method that gets user input and checks if there is a record in the file that has the same firstname as the user input
//if we find one or more matches we print it to the console
void search_by_firstname(char *name)
{
  PERSON temp;

  file = fopen(fileName, "rb");

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)     //reads the file as long as we find a record
    {
      if (strcmp(temp.firstname, name) == 0)               //if we find a record with a firstname that matches the user input we print the record
      {                                                    //to the console
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

//method that gets user input and checks if there is a record in the file that has the same firstname as the user input
//if we find one or more matches we print it to the console
void search_by_lastname(char *name)
{
  PERSON temp;

  file = fopen(fileName, "rb");

  if (file != NULL)
  {
    while (fread(&temp, sizeof(PERSON), 1, file) != 0)           //reads the file as long as we find a record
    {
      if (strcmp(temp.famnamne, name) == 0)                      //if we find a record with a famname that matches the user input we print the record
      {                                                          //to the console
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