// can also use #ifndef:
// #ifndef HEADER_H
// #define HEADER_H

// #endif // HEADER_H
// include guard ensures a header file is only included once
#pragma once
#include <string.h>

#define MAX_SIZE 32

typedef struct example
{
    int value;
    char string[MAX_SIZE];
    size_t string_length;
} example_struct;

// prints the members of the struct passed as an argument
void print_struct_members(struct example struct_to_print);