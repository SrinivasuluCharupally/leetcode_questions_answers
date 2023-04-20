#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *worker(void *arg) {
    int id = *(int *)arg;
    sem_wait(&sem);
    printf("Worker %d acquired a resource.\n", id);
    // Do work with the resource here
    sem_post(&sem);
    printf("Worker %d released the resource.\n", id);
    return NULL;
}

int main() {
    sem_init(&sem, 0, 6);
    pthread_t threads[6];
    int ids[5];
    for (int i = 0; i < 6; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }
    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&sem);
    return 0;
}
