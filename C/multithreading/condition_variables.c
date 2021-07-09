#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_COUNT 3

int count = 25;
pthread_mutex_t count_mutex;
pthread_cond_t count_condition;

struct thread_arguments
{
    int arg1;
    int arg2;
};

void *increment_counter(void *args)
{
    struct thread_arguments *arguments = (struct thread_arguments *)args;
    int v = arguments->arg1; // increment value
    int n = arguments->arg2; // thread number

    while (count < 50)
    {
        pthread_mutex_lock(&count_mutex);
        count += v;
        printf("Thread %d - Increased count by %d\n", n, v);
        printf("Count = %d\n", count);
        pthread_mutex_unlock(&count_mutex);

        // signals on count_condition and unblocks at least one blocking thread on the condition variable
        // pthread_cond_signal(&count_condition);

        // signals on count_condition and unblocks any blocking thread on the condition variable
        pthread_cond_broadcast(&count_condition);

        usleep(500000); // sleep for 500ms
    }

    free(args);

    return NULL;
}

void *decrement_counter()
{
    int decrement_value = 25;
    pthread_mutex_lock(&count_mutex);
    while (count < 50)
    {
        printf("Decrement Thread - Count not at 50, no decrement\n");

        // blocks on count_condition until there is a signal on the condition variable
        // alternative is to use pthread_cond_timed_wait ot block for a given amount of time
        pthread_cond_wait(&count_condition, &count_mutex);
    }

    while (count > 0)
    {
        count -= decrement_value;
        printf("Decrement Thread - Decremented count by %d\n", decrement_value);
        printf("Count = %d\n", count);
        pthread_mutex_unlock(&count_mutex);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[THREAD_COUNT];

    int count_mutex_init = pthread_mutex_init(&count_mutex, NULL);
    if (count_mutex_init != 0)
    {
        return 1;
    }

    // initialize condition variable
    int count_condition_init = pthread_cond_init(&count_condition, NULL);
    if (count_condition_init != 0)
    {
        return 2;
    }

    int i;
    for (i = 0; i < THREAD_COUNT; i++)
    {
        if (i == THREAD_COUNT - 1)
        {
            int thread_creation = pthread_create(&threads[i], NULL, &decrement_counter, NULL);
            if (thread_creation != 0)
            {
                return 3;
            }
        }
        else
        {
            struct thread_arguments *args = (struct thread_arguments *)malloc(sizeof(struct thread_arguments));
            args->arg1 = (THREAD_COUNT * i) + 1; // thread 1 - value = 1, thread 2 - value = 4
            args->arg2 = i + 1; // thread number

            int thread_creation = pthread_create(&threads[i], NULL, &increment_counter, (void *)args);
            if (thread_creation != 0)
            {
                return 4;
            }
        }
    }

    for (i = 0; i < THREAD_COUNT; i++)
    {
        int thread_join = pthread_join(threads[i], NULL);
        if (thread_join != 0)
        {
            return 5;
        }
    }

    int count_mutex_destroy = pthread_mutex_destroy(&count_mutex);
    if (count_mutex_destroy != 0)
    {
        return 6;
    }

    int count_condition_destory = pthread_cond_destroy(&count_condition);
    if (count_condition_destory != 0)
    {
        return 7;
    }

    return 0;
}
