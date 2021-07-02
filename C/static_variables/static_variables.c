#include <stdio.h>

void function()
{
    int x = 10;
    static int static_x = 10;

    int i;
    for (i = 0; i < 5; i++)
    {
        printf("x = %d, static_x = %d\n", x++, static_x++);
    }
}

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        function();
    }

    return 0;
}
