#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen("./binary_file.bin", "wb");

    if (file == NULL) {
        // exit if file couldn't be opened
        return 1;
    }

    size_t bytes_written;

    char chars_to_write[] = {'a', 'c', 'x', 'z'};
    bytes_written = fwrite(chars_to_write, sizeof(char), sizeof(chars_to_write), file);

    char int_chars_to_write[] = {97, 65, 76, 101, 99, 67, 88, 113};
    bytes_written += fwrite(int_chars_to_write, sizeof(char), sizeof(int_chars_to_write), file);

    printf("Characters written: %lu\n", (bytes_written / sizeof(char)));

    fclose(file);

    return 0;
}