#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned short x;

    x = 1;

    int i;
    for (i = 1; i <= sizeof(short) * 8; i++)
    {
        printf("%hu left shift %02d: %d\n", x, i, x << i);
    }

    printf("\n\n");

    x = 32768;

    for (i = 1; i <= sizeof(short) * 8; i++)
    {
        printf("%hu right shift of %02d: %d\n", x, i, x >> i);
    }

    printf("\n\n");

    short y;

    y = 101;

    for (i = 1; i <= sizeof(short) * 8; i++)
    {
        printf("%hd left shift %02d: %d\n", y, i, y << i);
    }

    printf("\n\n");

    y = 32667;

    for (i = 1; i <= sizeof(short) * 8; i++)
    {
        printf("%hd right shift %02d: %d\n", y, i, y >> i);
    }

    return 0;
}
