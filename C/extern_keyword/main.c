#include <stdio.h>

extern void print_string_chars(char *string);
extern int multiply_by_value(int x);

int value = 7;

int main(int argc, char *argv[])
{
    printf("%d x %d = %d\n", value, 6, multiply_by_value(6));

    print_string_chars("These are the characters of a string");

    return 0;
}
