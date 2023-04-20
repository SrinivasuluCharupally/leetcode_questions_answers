#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 3

int counter = 0; // shared resource

sem_t mutex; // semaphore to control access to counter

void *thread_func(void *thread_id)
{
    int tid = *(int *)thread_id;
    for (int i = 0; i < 10; i++) {
        sem_wait(&mutex); // acquire semaphore
        counter++; // critical section
        printf("Thread %d: counter = %d\n", tid, counter);
        sem_post(&mutex); // release semaphore
    }
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2};

    sem_init(&mutex, 0, 1); // initialize semaphore

    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_func, (void *)&thread_ids[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex); // destroy semaphore

    printf("Final counter value: %d\n", counter);

    pthread_exit(NULL);
}
