#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_COUNT 3

// THIS WILL NOT COMPILE CORRECTLY OR RUN ON macOS
// unnamed semaphores are not supported on macOS, so either named semaphores must
// be used or another semaphore API

int count;
sem_t count_semaphore;

void *increment_counter(void *thread_number)
{
    int n, count_semaphore_value;

    n = *((int *)thread_number);

    int i;
    for (i = 0; i < 1500000; i++)
    {
        // wait locks the semaphore, allowing only a single to increment the counter at a time
        // alternatively, trywait can be used, which will produce different behaviour
        sem_wait(&count_semaphore);

        // only output semaphore value for the final three iterations of each thread
        if (i > 1499997)
        {
            sem_getvalue(&count_semaphore, &count_semaphore_value);
            printf("Thread %d - Semaphore value after wait: %d\n", n, count_semaphore_value);
        }

        count++;
        sem_post(&count_semaphore);

        // only output semaphore value for the final three iterations of each thread
        if (i > 1499997)
        {
            sem_getvalue(&count_semaphore, &count_semaphore_value);
            printf("Thread %d - Semaphore value after post: %d\n", n, count_semaphore_value);
        }
    }

    free(thread_number);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[THREAD_COUNT];

    // initialize a semaphore with initial value 1
    // different initial values can be used to control how many threads can
    // execute a given section at once
    int count_semaphore_init = sem_init(&count_semaphore, 0, 1);
    if (count_semaphore_init != 0)
    {
        printf("Failed to initialize semaphore\n");
        return 1;
    }

    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        int *thread_number = (int *)malloc(sizeof(int));
        *thread_number = i + 1;

        int thread_creation = pthread_create(&threads[i], NULL, &increment_counter, (void *)thread_number);
        if (thread_creation != 0)
        {
            printf("Fialed to create thread %d\n", i);
            return 2;
        }

        printf("Started thread %d\n", i + 1);
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        int thread_join = pthread_join(threads[i], NULL);
        if (thread_join != 0)
        {
            printf("Fialed to join thread %d\n", i);
            return 2;
        }

        printf("Joined thread %d\n", i + 1);
    }

    int count_semaphore_destroy = sem_destroy(&count_semaphore);
    if (count_semaphore_destroy != 0)
    {
        printf("Failed to destroy mutex\n");
        return 3;
    }

    printf("Count = %d\n", count);

    return 0;
}
