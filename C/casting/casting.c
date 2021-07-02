#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char integer_as_string[] = "36";

    int integer = atoi(integer_as_string);
    printf("string = %s, integer = %d\n", integer_as_string, integer);

    char float_as_string[] = "124.157";
    float float_from_string = strtof(float_as_string, NULL);
    printf("string = %s, float = %f\n", float_as_string, float_from_string);

    char double_as_string[] = "476.124324";
    double double_from_string = strtod(double_as_string, NULL);
    printf("string = %s, double = %f\n", double_as_string, double_from_string);

    char string_of_numbers[] = "1231 f4a5 0101101 77 0x0b27";
    char * end_pointer;
    long decimal = strtol (string_of_numbers, &end_pointer, 10);
    long hexadecimal = strtol (end_pointer, &end_pointer, 16);
    long binary = strtol (end_pointer, &end_pointer, 2);
    long octal = strtol (end_pointer, &end_pointer, 8);
    long number_from_format = strtol(end_pointer, NULL, 0);
    printf ("Numbers as decimals: %ld, %ld, %ld, %ld, %ld\n", decimal, hexadecimal, binary, octal, number_from_format);

    return 0;
}
