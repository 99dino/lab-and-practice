#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 5
int state[N];
#define Thinking 2
#define Hungry 1
#define Eating 0
int times = 10;
sem_t mutex;
sem_t s[N];
int x = 5;
int left(int i) { return (i + N - 1) % N; }
int right(int i) { return (i + 1) % N; }

void test(int i)
{
    if (state[i] == Hungry && state[left(i)] != Eating && state[right(i)] != Eating)
    {
        state[i] = Eating;
        sem_post(&s[i]);
    }
}

void take(int i)
{
    // Acquireing the Mutex semaphore so that no other Philosphers can change it !
    sem_wait(&mutex);
    state[i] = Hungry;
    // checking if neibhours are eating or not.
    test(i);
    // Releasing the Mutex semaphore so that other Philosphers can can it !
    sem_post(&mutex);
    // Semaphore Wait for the s[i] Philosphers
    sem_wait(&s[i]);
}

void put(int i)
{
    // Acquireing the Mutex semaphore so that no other Philosphers can change it !
    sem_wait(&mutex);
    state[i] = Thinking;
    test(left(i));
    test(right(i));
    // Releasing the Mutex semaphore so that other Philosphers can can it !
    sem_post(&mutex);
}

void *philosopher(int *arg)
{
    int i = *arg;

    while (times--)
    {
        printf("Philosopher %d is Thinking.\n", i);
        sleep(2);
        printf("Philosopher %d is Hungry.\n", i);
        take(i);
        printf("Philosopher %d is Eating. with %d and %d \n", i, left(i), right(i));
        sleep(2);
        put(i);
        x--;
    }
}

int main()
{
    pthread_t threads[N];
    int i, ids[N];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
    {
        // Intialisng semaphore !
        sem_init(&s[i], 0, 0);
        // Intialising all states to Thinking !!
        state[i] = Thinking;
    }

    for (i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, (void *)philosopher, &ids[i]);
    }

    for (i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

