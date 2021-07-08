#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // pipe 1 - Main => Child, pipe 2 - Child => Main
    // [0][0] - read pipe 1, [0][1]- write pipe 1, [1][0] - read pipe 2, [1][1] - write pipe 2
    int file_descriptors[2][2];

    pipe(file_descriptors[0]);
    pipe(file_descriptors[1]);

    int fork_return = fork();

    // good practice to check pipe creation and fork successful

    if (fork_return == 0)
    {
        // close unused pipes
        close(file_descriptors[0][1]);
        close(file_descriptors[1][0]);

        int number_from_pipe;

        read(file_descriptors[0][0], &number_from_pipe, sizeof(number_from_pipe));

        number_from_pipe *= number_from_pipe;

        printf("Child Process - Squared number\n");

        write(file_descriptors[1][1], &number_from_pipe, sizeof(number_from_pipe));

        // good practice to check if reading and writing successful

        // close pipes after use
        close(file_descriptors[0][0]);
        close(file_descriptors[1][1]);
    }
    else
    {
        // close unused pipes
        close(file_descriptors[0][0]);
        close(file_descriptors[1][1]);

        int x;
        printf("Main Process - Enter number: ");
        scanf("%d", &x);

        write(file_descriptors[0][1], &x, sizeof(x));

        read(file_descriptors[1][0], &x, sizeof(x));

        // good practice to check if reading and writing successful

        printf("Main process - Number squared = %d\n", x);

        // close pipes after use
        close(file_descriptors[0][1]);
        close(file_descriptors[1][0]);

        wait(NULL);
    }



    return 0;
}
