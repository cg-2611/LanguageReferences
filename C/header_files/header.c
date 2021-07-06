#include <stdio.h>
#include "headers/header.h"

void print_struct_members(struct example struct_to_print)
{
    printf("Struct value = %d\n", struct_to_print.value);
    printf("Struct string = %s\n", struct_to_print.string);
    printf("Struct string length = %lu\n", struct_to_print.string_length);
    printf("Struct characters = \n");

    // string.h included in headers/header.h so functions and types can be used
    size_t i;
    for (i = 0; i < strlen(struct_to_print.string); i++)
    {
        printf("%c\n", struct_to_print.string[i]);
    }
}