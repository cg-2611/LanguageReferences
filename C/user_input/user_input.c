#include <stdio.h>

int main(int argc, char *argv[])
{
    char character;

    printf("Enter character: ");
    // can also use scanf("%c", &character);
    character = getchar();

    // can also use printf("Character entered: %c", character);
    printf("Character entered: ");
    putchar(character); // can also use putc(character, stdout);

    char string[256];

    printf("\n\nEnter string: ");
    fflush(stdin); // flush the standard input buffer
    // can also use scanf("%s", string);
    fgets(string, 256, stdin);

    // can also use printf("String entered: %s", string);
    printf("String entered: ");
    puts(string); // can also use fputs(string, stdout);

    int integer;

    printf("Enter integer: ");
    fflush(stdin);
    scanf("%d", &integer);
    printf("Integer entered: %d\n", integer);

    int i;
    char c;
    float f;
    char s[64];

    printf("\nEnter values: ");
    fflush(stdin);
    scanf("%d-%c %f, %s", &i, &c, &f, s);
    printf("Values entered: %d, \'%c\', %f, \"%s\"\n", i, c, f, s);

    return 0;
}
