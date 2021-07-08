#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // fork will result in 2^number_of_forks processes being created
    int fork1_return = fork(); // forks the main process
    int fork2_return = fork(); // forks the main process and the child of the main process

    // good practice to check if fork successful

    // to only fork the main process on the second fork, call fork on the non child process only:

    // if (fork1_return != 0)
    // {
    //     int fork2_return = fork();
    // }

    // this results in the main process having two child processes

    if (fork1_return == 0)
    {

        if (fork2_return == 0)
        {
            printf("\nChild of child process of main from fork1 (x), from fork2 (z) -\n");
            printf("fork2_return: %d, pid: %d, ppid: %d\n", fork2_return, getpid(), getppid());
        }
        else
        {
            printf("\nChild of main process from fork1 (x) -\n");
            printf("fork1_return: %d, pid: %d, ppid: %d\n", fork1_return, getpid(), getppid());
            printf("fork2_return: %d, pid: %d, ppid: %d\n", fork2_return, getpid(), getppid());

            int x_wait_return = wait(NULL);
            if (x_wait_return == -1)
            {
                printf("Process x has no children to wait for\n");
            }
            else
            {
                printf("Process x finished waiting for process: %d\n", x_wait_return);
            }
        }
    }
    else
    {

        if (fork2_return == 0)
        {
            printf("\nChild of main process from fork2 (y) -\n");
            printf("fork2_return: %d, pid: %d, ppid: %d\n", fork2_return, getpid(), getppid());
        }
        else
        {
            printf("\nMain process -\n");
            printf("fork1_return: %d, pid: %d, ppid: %d\n", fork1_return, getpid(), getppid());
            printf("fork2_return: %d, pid: %d, ppid: %d\n", fork2_return, getpid(), getppid());

            int main_wait_return = wait(NULL);
            if (main_wait_return == -1)
            {
                printf("Main process has no children to wait for\n");
            }
            else
            {
                printf("Main process finished waiting for process: %d\n", main_wait_return);
            }
        }
    }

    return 0;
}
