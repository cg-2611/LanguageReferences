#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;

    // output all error message strings and their respective errno
    for (i = 1; i < 107; i++)
    {
        fprintf(stderr, "errno: %d, message: %s\n", i, strerror(i));
    }

    return 0;
}
