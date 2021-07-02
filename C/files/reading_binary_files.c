#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen("./binary_file.bin", "rb");

    if (file == NULL)
    {
        // exit if file couldn't be opened
        return 1;
    }

    fseek (file, 0, SEEK_END); // go to end of file
    long file_size = ftell(file); // get position of the end of the file
    rewind(file); // go to start of file for reading

    // allocate memory to store data in file
    char *data_from_file = (char *)malloc(sizeof(char) * file_size);
    size_t bytes_read = fread(data_from_file, sizeof(char), file_size, file);

    // good practice to check memory allocation and file reading is successful

    printf("Bytes read: %lu\n", bytes_read);
    printf("Data from file: %s\n", data_from_file);

    fclose(file);
    free(data_from_file);

    return 0;
}
