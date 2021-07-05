#include <stdio.h>

int main(int argc, char *argv[])
{
    int result;

    // 12 = 0001100
    // 7  = 0000111
    // &  = 0000100 = 4
    result = 12 & 7;
    printf("12 & 7 = %d\n", result);

    // 17 = 00010001
    // 11 = 00001011
    // |  = 00011011 = 27
    result = 17 | 11;
    printf("17 | 11 = %d\n", result);

    // 22 = 00010110
    // 15 = 00001111
    // ^  = 00011001 = 25
    result = 22 ^ 15;
    printf("22 ^ 15 = %d\n", result);

    // 37 = 00100101
    // ~  = 11011010 = -38
    result = ~37;
    printf("~37 = %d\n", result);

    return 0;
}
