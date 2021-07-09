#include <pthread.h>
#include <stdio.h>

#define THREAD_COUNT 3

int count;
pthread_mutex_t count_mutex;

void *increment_counter()
{
    int i;
    for (i = 0; i < 1500000; i++)
    {
        // lock allows only one thread to increment count at a time
        // if the mutex is locked, then lock will wait until it is unlocked
        pthread_mutex_lock(&count_mutex);
        count++;
        pthread_mutex_unlock(&count_mutex);

        // alternatively to lock, trylock can be used, however, the return value
        // of the trylock function can be checked for failure (!= 0) when the lock
        // cannot be obtained and this can be handled
        // trylock will not wait until an unlock, it will return either after trying to
        // get the lock, or after getting the lock, executing, and then unlocking
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[THREAD_COUNT];

    // create a mutex with default attributes
    int mutex_init = pthread_mutex_init(&count_mutex, NULL);
    if (mutex_init != 0)
    {
        printf("Failed to initialize mutex\n");
        return 1;
    }

    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        int thread_creation = pthread_create(&threads[i], NULL, &increment_counter, NULL);
        if (thread_creation != 0)
        {
            printf("Fialed to create thread %d\n", i);
            return 2;
        }

        printf("Started thread %d\n", i);
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        int thread_join = pthread_join(threads[i], NULL);
        if (thread_join != 0)
        {
            printf("Fialed to join thread %d\n", i);
            return 3;
        }

        printf("Joined thread %d\n", i);
    }

    int count_mutex_destroy = pthread_mutex_destroy(&count_mutex);
    if (count_mutex_destroy != 0)
    {
        printf("Failed to destroy mutex\n");
        return 4;
    }

    printf("Count = %d\n", count);

    return 0;
}
