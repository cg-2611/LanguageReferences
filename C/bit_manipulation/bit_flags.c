#include <stdio.h>

#define FLAG_1 0b00000001
#define FLAG_2 0b00000010
#define FLAG_3 0b00000100

void printf_flags(unsigned char flags)
{
    if (flags & FLAG_1)
    {
        printf("Flag 1 set to 1\n");
    }
    else
    {
        printf("Flag 1 set to 0\n");
    }

    if (flags & FLAG_2)
    {
        printf("Flag 2 set to 1\n");
    }
    else
    {
        printf("Flag 2 set to 0\n");
    }

    if (flags & FLAG_3)
    {
        printf("Flag 3 set to 1\n");
    }
    else
    {
        printf("Flag 3 set to 0\n");
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    unsigned char bit_flags;
    // set all flags,  flags = 00000111
    bit_flags = FLAG_1 | FLAG_2 | FLAG_3;
    printf_flags(bit_flags);

    // unset flag 2, flags = 00000101
    bit_flags = bit_flags & ~FLAG_2;
    printf_flags(bit_flags);

    // reset flag 2, unset flags 1 and 3, flags = 00000010
    bit_flags = bit_flags & ~FLAG_1;
    bit_flags = bit_flags & ~FLAG_3;
    bit_flags = bit_flags | FLAG_2;
    printf_flags(bit_flags);

    // reset all flags
    bit_flags = FLAG_1 | FLAG_2 | FLAG_3;
    printf_flags(bit_flags);

    return 0;
}
