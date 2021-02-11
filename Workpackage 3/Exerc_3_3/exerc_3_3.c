#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5           // the initial number of recors in the list upon creation

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
void print_list(REGTYPE* cur_post);

//###### Main program #######
int main(int argc, char *argv[])
{
    REGTYPE *cur_post, *head = NULL;
    srand(time(0)); //   Random seed
    head = random_list();
    // prints each record in the list, tests that the list was created
    print_list(head);

    // add record first
    head = add_first(head, rand() % 101);

    // prints each record in the list, tests that the list was updated
    print_list(head);

    // --- Free of allocated memory  ---
    while ((cur_post = head) != NULL)
    {
        head = cur_post->next;
        free(cur_post);
    } 
    
    //------------------                   
    return 0;
}
// ====     End of main   ======================================

REGTYPE* random_list(void){
    
    REGTYPE *top, *old, *item;
    
    // creates MAX records and links them together in a doubly linked list
    //      
    for(int i = 0; i < MAX; i++) {

        // allocating memory for the new record
        item = malloc(sizeof(REGTYPE));
        // gives number a random value between 0 and 100
        item->number = rand() % 101; 

        // special case for first record
        if (i == 0) {

            // keep track of the first record
            top = item;
            // first record should not have a previous record
            old = NULL;
        }
        
        // set prev of the current record to old, which is either the previous record or NULL
        item->prev = old;
        
        if (old != NULL) {

            // set next pointer for the previous record to the current one
            old->next = item;
        }

        // point old to current record
        old = item;
    }
    // last record should not have a next record
    item->next = NULL;
    // returns 
    return(top);
}

REGTYPE* add_first(REGTYPE* temp, int data){
    
    REGTYPE *rec = malloc(sizeof(REGTYPE));

    rec->number = data;
    rec->prev = NULL;
    rec->next = temp;

    temp->prev = rec;

    return rec;
}

void print_list(REGTYPE* cur_post) {
    int nr = 0;
    while (cur_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, cur_post->number);
        cur_post = cur_post->next;
    }
    printf("\n");
}