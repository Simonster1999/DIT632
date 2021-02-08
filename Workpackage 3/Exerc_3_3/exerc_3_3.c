#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Funcion declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *akt_post, *head = NULL;
    srand(time(0)); //   Random seed
    //head = malloc(MAX * sizeof(struct q));
    head = random_list();
    akt_post = head;
    while (akt_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }
    // --- Free of allocated memory  ---
    while ((akt_post = head) != NULL)
    {
        head = akt_post->next;
        free(akt_post);
    } 
    
    //------------------                   
    return 0;
}
// ====     End of main   ======================================

REGTYPE* random_list(void){

    REGTYPE records[MAX];
    int nr,i=0;    
    REGTYPE *top, *old, *item;

    old = &records[0];
    top = &records[0];
    for(i; i < MAX; i++) {
        records[i].number = rand() % 101; // possible numbers: 0-100

        item = &records[i];
        old->next = item;

        item->prev = old;
        old = item;
    }
    item->next = NULL;
    top->prev = NULL;
    //item->next = top;
    //top->prev = old;
    return(top);
}

REGTYPE* add_first(REGTYPE* temp, int data){
    // Adds a record first i list and set the field tal to data
}
