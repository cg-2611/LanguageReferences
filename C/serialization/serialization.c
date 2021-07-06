#include <stdio.h>
#include <stdlib.h>

struct example
{
    int int_value;
    double double_value;
    char string[32];
};

int main(int argc, char *argv[])
{
    struct example struct1 = {432, 0.001268, "struct1 string"};
    struct example struct2 = {277, 0.033984, "struct2 string"};

    printf("struct1 int value = %d\n", struct1.int_value);
    printf("struct1 double value = %lf\n", struct1.double_value);
    printf("struct1 string = %s\n\n", struct1.string);

    printf("struct2 int value = %d\n", struct2.int_value);
    printf("struct2 double value = %lf\n", struct2.double_value);
    printf("struct2 string = %s\n\n", struct2.string);

    FILE *file;
    file = fopen("serialized_structs.bin", "wb+");

    if (file == NULL)
    {
        return 1;
    }

    size_t items_written;

    // write 1 item consiting of size of struct number of bytes from each struct to file
    items_written =  fwrite(&struct1, sizeof(struct example), 1, file);
    items_written += fwrite(&struct2, sizeof(struct example), 1, file);

    printf("Written %lu items\n\n", items_written);

    rewind(file);

    struct example *struct1_read = (struct example *)malloc(sizeof(struct example));
    struct example *struct2_read = (struct example *)malloc(sizeof(struct example));

    // good practice to check if memory allocation successful

    size_t items_read;

    // read 1 item consiting of size of struct number of bytes from file and store in each new struct
    items_read =  fread(struct1_read, sizeof(struct example), 1, file);
    items_read += fread(struct2_read, sizeof(struct example), 1, file);

    printf("Read %lu items\n\n", items_read);

    fclose(file);

    printf("struct1_read int value = %d\n", struct1_read->int_value);
    printf("struct1_read double value = %lf\n", struct1_read->double_value);
    printf("struct1_read string = %s\n\n", struct1_read->string);

    printf("struct2_read int value = %d\n", struct2_read->int_value);
    printf("struct2_read double value = %lf\n", struct2_read->double_value);
    printf("struct2_read string = %s\n\n", struct2_read->string);

    free(struct1_read);
    struct1_read = NULL;

    free(struct2_read);
    struct2_read = NULL;

    return 0;
}
