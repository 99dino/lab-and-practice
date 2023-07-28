#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N_READERS 5
#define N_WRITERS 2

int shared_resource = 0;
int readers_count = 0;

sem_t mutex, rw_mutex;

void *reader(void *arg) {
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        // Reading shared resource
        printf("Reader %d read shared resource: %d\n", *(int *)arg, shared_resource);

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);

        // Sleep for a while before reading again
        //sleep(1);
    }
}

void *writer(void *arg) {
    while (1) {
        sem_wait(&rw_mutex);

        // Writing to shared resource
        shared_resource += 10;
        printf("Writer %d wrote shared resource: %d\n", *(int *) arg, shared_resource);

        sem_post(&rw_mutex);

        // Sleep for a while before writing again
        //sleep(2);
    }
}

int main() {
    pthread_t readers[N_READERS], writers[N_WRITERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    // Create reader threads
    for (int i = 0; i < N_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, (void *) &i);
    }

    // Create writer threads
    for (int i = 0; i < N_WRITERS; i++) {
        pthread_create(&writers[i], NULL, writer, (void *) &i);
    }

    // Wait for threads to finish
    for (int i = 0; i < N_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < N_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}

