#include <stdio.h>
#include <stdlib.h>

void read_file_with_fscanf(FILE *opened_file) {
    char line_buffer[256];

    // the string read by fscanf is stored in line_buffer
    while (fscanf(opened_file, "%s", line_buffer) != EOF) {
        printf("Line Text: %s\n", line_buffer);
    }
}

void read_file_with_getline(FILE *opened_file) {
    char *line_buffer = NULL;
    size_t buffer_size = 0; // this is ok since line_buffer is NULL
    ssize_t line_length;

    // getline returns the length of the line and also puts the line, as a string, into line_buffer
    // it also returns -1 on failure or end of file
    while ((line_length = getline(&line_buffer, &buffer_size, opened_file)) > 0) {
        printf("Line Length: %zd\n", line_length);
        printf("Line Text: %s", line_buffer);
    }

    free(line_buffer); // deallocate memory for the line_buffer
}

void read_file_with_fgets(FILE *opened_file) {
    char line_buffer[256];

    // fgets stores the line from the file in line_buffer
    while (fgets(line_buffer, 256, opened_file) != NULL) {
        printf("Line Text: %s", line_buffer);
    }
}

void read_file_with_fgetc(FILE *opened_file) {
    char line_char;

    // fgetc returns the charcater read from the file
    while ((line_char = fgetc(opened_file)) != EOF) {
        printf("Line Character: %c\n", line_char);
    }
}

int main(int argc, char *argv[]) {
    // open file.txt for reading
    FILE *file = fopen("./file.txt", "r");

    fpos_t file_position;
    fgetpos(file, &file_position); // set file_position to the beginning of the file

    if (file == NULL) {
        // exit if file couldn't be opened
        return 1;
    }

    printf("\nUsing fscanf:\n");
    read_file_with_fscanf(file);

    rewind(file); // take cursor back to beginning of file

    printf("\nUsing getline:\n");
    read_file_with_getline(file);

    fseek(file, 0, SEEK_SET); // take cursor back to 0 bytes after the start of the file

    printf("\n\nUsing fgets:\n");
    read_file_with_fgets(file);

    fsetpos(file, &file_position); // take cursor back to beginning of file

    printf("\n\nUsing fgetc:\n");
    read_file_with_fgetc(file);
    
    fclose(file);

    return 0;
}