#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // print error message ad usage advice to stderr stream
        fprintf(stderr, "Invalid arguments passed\n");
        fprintf(stderr, "Usage: ./error_handling.out <filename>\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r"); // on open failure, errno set to non zero value

    if (file == NULL)
    {
        // perror prints the argument string followed by the error message
        perror("Error opening file");

        // strerror takes errno as argument and prints the corresponding error message to the stderr stream
        fprintf(stderr, "on line: %d, errno: %d, message: %s\n", __LINE__, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    int i = 1;
    char line_buffer[256];

    while (fgets(line_buffer, 256, file) != NULL)
    {
        printf("File line %d: %s", i, line_buffer);
        i++;
    }

    printf("\n");

    if (fclose(file) != 0)
    {
        perror("Error closing file");
        fprintf(stderr, "on line: %d, errno: %d, message: %s\n", __LINE__, errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
