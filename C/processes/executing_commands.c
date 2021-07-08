#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fork_return = fork();
    if (fork_return == -1)
    {
        return 1;
    }

    if (fork_return == 0)
    {
        // l - list
        // v - vector
        // p - use PATH
        // e - environment variables
        // exec completeley replaces the process it is called on
        int exec_status = execlp("echo", "echo", "example execution", NULL);
        if (exec_status == -1)
        {
            printf("Error executing program");
            return 2;
        }
    }
    else
    {
        int wait_status;
        wait(&wait_status);

        if (WIFEXITED(wait_status))
        {
            int exit_status_code = WEXITSTATUS(wait_status);
            if (exit_status_code == 0)
            {
                printf("Process exited successfully\n");
            }
            else
            {
                printf("Process failed with code %d\n", exit_status_code);
            }

        }
    }

    return 0;
}
