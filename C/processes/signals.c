#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fork_pid = fork();

    if (fork_pid == -1)
    {
        return 1;
    }


    if (fork_pid == 0)
    {
        while (1)
        {
            printf("Child Process output\n");
            usleep(250000); // sleep for 250000 microseconds (250 milliseconds)
        }
    }
    else
    {
        // pauses child process
        kill(fork_pid, SIGSTOP);

        int time;

        do
        {
            printf("Enter time for execution: ");
            scanf("%d", &time);

            if (time > 0)
            {
                // resumes child process
                kill(fork_pid, SIGCONT);
                sleep(time);
                kill(fork_pid, SIGSTOP);
            }
            else
            {
                printf("Execution stopped\n");
            }
        } while (time > 0);

        // terminates child process
        kill(fork_pid, SIGKILL);
        wait(NULL);
    }

    return 0;
}