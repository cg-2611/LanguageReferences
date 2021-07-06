#include <stdio.h>
#include <string.h>

void print_string_chars(char *string)
{
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        printf("%c\n", string[i]);
    }
}

int multiply_by_value(int x)
{
    extern int value;
    return value * x;
}
