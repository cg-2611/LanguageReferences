#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // fopen in "w" mode will create a file if it doesn't exist
    FILE *file = fopen("./written_file.txt", "w");

    // to delete a file use remove(FILE *file_to_remove)
    // to rename a file use rename(FILE &file_to_rename)

    if (file == NULL) {
        // exit if file couldn't be opened
        return 1;
    }

    char *text_to_write = "This is 123.4\n\n\tA\nTest string";

    // using fputc:
    // int i;
    // for (i = 0; i < strlen(text_to_write); i++) {
    //     fputc(text_to_write[i], file);
    // }

    // using fputs:
    // fputs(text_to_write, file);

    // using fprintf:
    fprintf(file, "%s", text_to_write);

    fclose(file);

    return 0;
}