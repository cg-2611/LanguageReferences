#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// required as barriers are not supported in macOS
#include "pthread_barriers.h"

#define THREAD_COUNT 5

pthread_barrier_t barrier1;
pthread_barrier_t barrier2;

void *thread_function(void *thread_numebr)
{
    int n = *((int *)thread_numebr);

    printf("Thread %02d - waiting for other threads\n", n);

    pthread_barrier_wait(&barrier1);

    printf("Thread %02d - finished waiting for other threads, waiting for main thread\n", n);

    pthread_barrier_wait(&barrier2);

    printf("Thread %02d - finished waiting\n", n);

    free(thread_numebr);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[THREAD_COUNT];

    // initialize barriers of count THREAD_COUNT + 1, with default attributes
    // + 1 used to include main thread
    int barrier1_init = pthread_barrier_init(&barrier1, NULL, THREAD_COUNT + 1);
    if (barrier1_init != 0)
    {
        return 1;
    }

    int barrier2_init = pthread_barrier_init(&barrier2, NULL, THREAD_COUNT + 1);
    if (barrier2_init != 0)
    {
        return 2;
    }


    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        int * thread_number = (int *)malloc(sizeof(int));
        *thread_number = i + 1;
        int thread_creation = pthread_create(&threads[i], NULL, &thread_function, (void *)thread_number);
        if (thread_creation != 0)
        {
            return 3;
        }

    }
    pthread_barrier_wait(&barrier1);

    sleep(1);
    printf("\nMain thread finished processing\n\n");

    pthread_barrier_wait(&barrier2);

    for (i = 0; i < THREAD_COUNT; i++)
    {
        int thread_join = pthread_join(threads[i], NULL);
        if (thread_join != 0)
        {
            return 4;
        }
    }

    int barrier1_destroy = pthread_barrier_destroy(&barrier1);
    if (barrier1_destroy != 0)
    {
        return 5;
    }

    int barrier2_destroy = pthread_barrier_destroy(&barrier2);
    if (barrier2_destroy != 0)
    {
        return 6;
    }

    return 0;
}