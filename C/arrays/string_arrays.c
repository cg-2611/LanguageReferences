#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int number_of_strings;

    printf("Enter number of strings: ");
    fflush(stdin);
    scanf("%d", &number_of_strings);

    // allocate memory to store pointers to the specified number of strings
    char **array_of_strings = (char **)malloc(sizeof(char *) * number_of_strings);

    int i, j;
    for(i = 0; i < number_of_strings; i++)
    {
        char string[BUFSIZ];

        printf("Enter string %d: ", i + 1);
        fflush(stdin);
        scanf("%s", string);

        // allocate memory to store the string and + 1 for the null terminator
        array_of_strings[i] = (char *)malloc(sizeof(char) * (strlen(string) + 1));

        // store the characters of the string in the array
        for (j = 0; j < strlen(string); j++)
        {
            array_of_strings[i][j] = string[j];
        }

        array_of_strings[i][strlen(string)] = '\0'; // add the null terminator to the end of the string
    }

    printf("\nStrings entered:\n");
    for (i = 0; i < number_of_strings; i++)
    {
        printf("String %s\n", array_of_strings[i]);

        // deallocate the memory for the string
        free(array_of_strings[i]);
        array_of_strings[i] = NULL;
    }

    // deallocate the memory for the array
    free(array_of_strings);
    array_of_strings = NULL;

    return 0;
}
