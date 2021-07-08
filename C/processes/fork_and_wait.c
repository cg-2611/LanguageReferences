#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // creates a child process from current parent process, fork_return == 0 for child process
    // fork() returns -1 if there was an error creating a child process
    pid_t fork_return = fork();

    if (fork_return == -1)
    {
        printf("Error creating child process");
        return 1;
    }

    // can also check for fork_return == 0 and return after process completes inside if, rather than having an else

    if (fork_return == 0)
    {
        printf("Child process fork_return: %d, pid: %d, ppid: %d\n", fork_return, getpid(), getppid());
    }
    else
    {
        printf("Main process fork_return: %d, pid: %d, ppid: %d\n", fork_return, getpid(), getppid());

        // will wait for child process to complete before executing parent process and returns the
        // pid of the child process being waited for or -1 if there are no child processes
        // wait(NULL) == waitpid(-1, NULL, 0)
        // waitpid() can be used to wait for a specific child process and also control how the parent
        // behaves while waiting
        int wait_return = wait(NULL);
        if(wait_return == -1)
        {
            printf("No children to wait for\n");
        }
        else
        {
            printf("Finished waiting for process: %d\n", wait_return);
        }
    }

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }

    if (fork_return == 0)
    {
        printf("Child process completed\n");
    }
    else
    {
        printf("Main process completed\n");
    }

    return 0;
}