#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char fifo_path[] = "./fifo_file.out"; // .out added due to gitignore

    // create a fifo file for given modes (reading, writing and executing)
    int fifo_status = mkfifo(fifo_path, S_IRWXU | S_IRWXG | S_IRWXO);

    // mkfifo returns -1 on failure, it fails if the fifo file already exists
    // so it is better to check for errors other than the file already existing
    if (fifo_status == -1 && errno != EEXIST)
    {
        printf("Error creating fifo");
        return 1;
    }

    int fork_return = fork();

    // good practice to check fork successful

    if (fork_return == 0)
    {
        // open for writing blocks until the fifo is also opened for reading
        int write_file_descriptor = open(fifo_path, O_WRONLY);

        // open returns -1 on failure
        if (write_file_descriptor == -1)
        {
            printf("Error opening fifo for writing");
            return 2;
        }

        char string_to_write[] = "This string was written to the fifo";
        int string_length_to_write = strlen(string_to_write);

        int write_status = write(write_file_descriptor, &string_length_to_write, sizeof(string_length_to_write));
        if (write_status == -1)
        {
            printf("Error writing to fifo");
            return 2;
        }

        printf("Child Process - Written string length\n");

        write_status = write(write_file_descriptor, string_to_write, sizeof(string_to_write));
        if (write_status == -1)
        {
            printf("Error writing to fifo");
            return 3;
        }

        printf("Child Process - Written string\n");

        close(write_file_descriptor);
    }
    else
    {
        // open fifo for read only
        int read_file_descriptor = open(fifo_path, O_RDONLY);
        if (read_file_descriptor == -1)
        {
            printf("Error opening fifo for reading");
        }

        int string_length_from_fifo;
        int read_status = read(read_file_descriptor, &string_length_from_fifo, sizeof(string_length_from_fifo));
        if (read_status == -1)
        {
            printf("Error reading from fifo");
            return 4;
        }

        char string_from_fifo[string_length_from_fifo + 1];
        read_status = read(read_file_descriptor, string_from_fifo, sizeof(string_from_fifo));
        if (read_status == -1)
        {
            printf("Error reading from fifo");
            return 5;
        }

        close(read_file_descriptor);

        printf("Main Process - String: %s\n", string_from_fifo);
        printf("Main Process - String length: %d\n", string_length_from_fifo);
    }

    return 0;
}
