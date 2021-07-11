#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *thread_function(void *thread_number)
{
    int x = *((int *)thread_number);
    printf("Printed by thread %d\n", x);
    free(thread_number); // deallocate memory for argument

    char thread_string[64];
    if (x == 1)
    {
        strcpy(thread_string, "Thread 1 executed");
    }
    else
    {
        strcpy(thread_string, "Thread 2 executed");
    }

    // allocate memory to store the returned string
    char *return_string = malloc((strlen(thread_string) + 1) * sizeof(*return_string));
    strcpy(return_string, thread_string); // copy the string to the returned string

    // can also ue pthread_exit((void *)return_string) to return from the thread as well
    return (void *)return_string;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    // allocate memory for arguments
    int *thread1_number = malloc(sizeof(*thread1_number));
    int *thread2_number = malloc(sizeof(*thread2_number));

    // give arguments values
    *thread1_number = 1;
    *thread2_number = 2;

    // pthread_create creates and starts the thread at the provided address
    // passing NULL results in the default attributes being used
    // the final argument is only required for passing arguments, if no arguments to
    // pass, make argument NULL
    int thread1_creation = pthread_create(&thread1, NULL, &thread_function, (void *)thread1_number);
    if (thread1_creation != 0)
    {
        printf("Failed to create thread\n");
        return 1;
    }

    int thread2_creation = pthread_create(&thread2, NULL, &thread_function, (void *)thread2_number);
    if (thread2_creation != 0)
    {
        printf("Failed to create thread\n");
        return 2;
    }

    char *thread1_string;
    char *thread2_string;

    // pthread_join terminates the thread after its execution has finished
    // the return value from the thread is stored in the second argument
    // if no return value, make argument NULL
    int thread1_join = pthread_join(thread1, (void **)&thread1_string);
    if (thread1_join != 0)
    {
        printf("Failed to join thread\n");
        return 3;
    }

    printf("%s\n", thread1_string);

    int thread2_join = pthread_join(thread2, (void **)&thread2_string);
    if (thread2_join != 0)
    {
        printf("Failed to join thread\n");
        return 4;
    }

    printf("%s\n", thread2_string);

    // deallocate memory for the strings returned by the threads
    free(thread1_string);
    free(thread2_string);

    printf("All threads terminated\n");

    return 0;
}
