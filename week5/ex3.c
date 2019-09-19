
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex_lock_var = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bq_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t bq_not_empty = PTHREAD_COND_INITIALIZER;
int *buffer, i = 0;


void *consumer() {
    while (1) {
        pthread_mutex_lock(&mutex_lock_var);

        if (i == -1) {
            pthread_cond_wait(&bq_not_empty, &mutex_lock_var);
        }

        printf("\nInside consumer. Id is =>:%d\n", i--);
        pthread_mutex_unlock(&mutex_lock_var);
        pthread_cond_signal(&bq_not_full);
    }
}

void *producer() {
    while (1) {
        pthread_mutex_lock(&mutex_lock_var);
        if (i == 100) pthread_cond_wait(&bq_not_full, &mutex_lock_var);

        buffer[i] = 1;
        i++;

        printf("\nInside producer. Id is =>:%d\n", i);
        pthread_mutex_unlock(&mutex_lock_var);
        pthread_cond_signal(&bq_not_empty);
    }
}

int main() {
    pthread_t p_thread_id, c_thread_id;
    buffer = (int *) malloc(sizeof(int) * 100);
    pthread_create(&p_thread_id, NULL, producer, NULL);
    pthread_create(&c_thread_id, NULL, consumer, NULL);
    pthread_join(p_thread_id, NULL);
    pthread_join(c_thread_id, NULL);
    
    return 0;
}

