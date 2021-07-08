#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_signal(int signum)
{
    printf("Signal received, signum: %d\n", signum);
    printf("Handling signal...\n");
    sleep(3);
    printf("Signal handled\n");
}

int main(int argc, char *argv[])
{
    int fork_pid = fork();

    if (fork_pid == -1)
    {
        return -1;
    }

    if (fork_pid == 0)
    {
        printf("Child process output, terminating parent process with signal...\n");

        // send SIGSUR1 signal to parent process
        kill(getppid(), SIGUSR1);

        return 0;
    }

    // SA_RESTART restarts function if interrupted by handler
    struct sigaction sa = {.sa_flags = SA_RESTART, .sa_handler = &handle_signal};

    // specify signal SIGUSR1 to perform action sa
    // returns -1 on error, good practice to handle this error
    sigaction(SIGUSR1, &sa, NULL);

    wait(NULL);

    printf("Main process terminated\n");

    return 0;
}
