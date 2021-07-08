#include <stdio.h>
#include <unistd.h>

struct example
{
    int int_value;
    double double_value;
    char string[32];
};

int main(int argc, char *argv[])
{
    int file_descriptors[2]; // [0] - read, [1] - write

    // open a pipe for communication
    // pipe() returns -1 on failure
    int pipe_status = pipe(file_descriptors);

    if(pipe_status == -1)
    {
        printf("Error opening pipe\n");
        return 1;
    }

    int fork_return = fork();

    // good practice to check if fork successful

    if (fork_return == 0)
    {
        close(file_descriptors[0]); // close read as not being used

        int number_from_user;
        printf("Child Process - Enter number: ");
        scanf("%d", &number_from_user);

        // write the integer to the pipe
        // write() returns -1 on failure
        int write_status = write(file_descriptors[1], &number_from_user, sizeof(number_from_user));
        if (write_status == -1)
        {
            printf("Error writing to pipe\n");
            return 2;
        }

        printf("Child Process - Passing struct thorough pipe\n");

        struct example struct_to_pipe = {13, 0.0223, "String passed through pipe"};
        write_status = write(file_descriptors[1], &struct_to_pipe, sizeof(struct_to_pipe));

        close(file_descriptors[1]); // close write as writing finished
    }
    else
    {
        close(file_descriptors[1]); // close write as not being used

        int number_from_child_process;

        // read integer from pipe
        // read() returns -1 on failure
        int read_status = read(file_descriptors[0], &number_from_child_process, sizeof(number_from_child_process));
        if (read_status == -1)
        {
            printf("Error reading from pipe\n");
            return 3;
        }

        printf("\nMain Process - Integer received from child process: %d\n", number_from_child_process);

        printf("Main Process - Reading struct from pipe\n");

        struct example struct_from_pipe;
        read_status = read(file_descriptors[0], &struct_from_pipe, sizeof(struct_from_pipe));

        printf("Main Process - Struct int value: %d\n", struct_from_pipe.int_value);
        printf("Main Process - Struct double value: %lf\n", struct_from_pipe.double_value);
        printf("Main Process - Struct string: %s\n", struct_from_pipe.string);

        close(file_descriptors[0]); // close read as finished reading
    }



    return 0;
}
