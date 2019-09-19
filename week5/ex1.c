#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS 50

int threads[THREADS];

void *print_something(int i) {
    printf("Something printed by thread %d \t in iteration %d \n", (int) pthread_self(), i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int res, i;
    for (i = 0; i < THREADS; i++) {
        res = pthread_create(&threads[i], NULL, print_something, (void*)i);
        if (res) {
            printf("\n ERROR - Exiting with code -> %d \n", res);
            exit(1);
        }
    }

    for (i = 0; i < THREADS; i++) {
        res = pthread_join(threads[i], NULL);
        printf("\n Completed Thread = %d. Next Thread = (%d) iteration =  %d.\n", (int) pthread_self(), threads[i], i);
    }
    return  0;
}

