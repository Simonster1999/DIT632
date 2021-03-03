// Skeleton for exercise nr 5 in WP 6 course DIT632.
// File skeleton_exerc_6_5.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 5      //buffer size
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0;    // index for next character to be put in buffer (put)
int outpos = 0;   // index for next character to be read ( fetch )

void *put();
void *fetch();

int main() {

    pthread_t threadP, threadF;
    int i;

    pthread_create(&threadP, NULL, &put, NULL);
    pthread_create(&threadF, NULL, &fetch, NULL);

    while (1) {
        printf("Main is executing\n");
        if(pthread_join(threadF, NULL) && pthread_join(threadP, NULL)) break;
    }
    //pthread_join(threadP, NULL);
    //pthread_join(threadF, NULL);
    //printf("\nDone");
    //exit(1);
}

void *put() {

    while (1) {

        pthread_mutex_lock(&count_mutex);

        if (count == MAX) {
            pthread_cond_wait(&not_full, &count_mutex);
        }

        buffer[inpos] = letter;

        printf("Buffer store\n");

        inpos++;
        count++;
        letter++;

        pthread_cond_signal(&not_empty);

        if (inpos == MAX) {
            inpos = 0;
        }

        pthread_mutex_unlock(&count_mutex);

        if (letter > 122) {
            return NULL;
        }
    }
}

void *fetch() {

    while (1) {

        pthread_mutex_lock(&count_mutex);

        if (count == 0) {
            pthread_cond_wait(&not_empty, &count_mutex);
        }

        printf("Buffer output: %c\n", buffer[outpos]);

        count--;
        outpos++;

        if (outpos == MAX) {
            outpos = 0;
        }

        pthread_cond_signal(&not_full);

        pthread_mutex_unlock(&count_mutex);

        if (letter > 122) {
            return NULL;
        }
    }
}
