#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // strings in c must be defined as arrays of chars with a
    // null terminator at the end to indicate the end of the string

    // fixed size strings:
    // can be initialized in multiple ways:
    // char string[] = "string";
    // char string[7] = "string";
    // char string[] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
    // char string[7] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};

    // example:
    char string[] = "This is a string";

    printf("String value: %s\n", string);
    printf("String length: %lu\n", strlen(string));

    char *first_i_character_pointer = strchr(string, 'i'); // strchr returns a character pointer or NULL if not found
    int i_first_index = first_i_character_pointer - string;
    printf("String first index of \'i\': %d\n", i_first_index);

    char *last_i_character_pointer = strrchr(string, 'i');
    int i_last_index = last_i_character_pointer - string;
    printf("String last index of \'i\': %d\n", i_last_index);

    char * s_index_pointer = strchr(string, 's');
    while (s_index_pointer != NULL)
    {
        printf("\'s\' found at index: %ld\n", (s_index_pointer - string));
        s_index_pointer = strchr((s_index_pointer + 1), 's');
    }

    char *substring_pointer = strstr(string, "string"); // returns a character pointer or null if not found
    if (substring_pointer != NULL)
    {
        printf("String index of substring \"string\": %ld\n", (substring_pointer - string));
    }

    char string_to_split[] = "This, is.a-string";
    char *split_string_pointer = strtok(string_to_split, " ,.-");
    printf("Split string into tokens at every \' \', \',\', \'.\' and \'-\':\n");
    while (split_string_pointer != NULL)
    {
        printf("String token: %s\n", split_string_pointer);
        split_string_pointer = strtok(NULL, " ,.-");
    }

    char another_string[] = "This is another string";
    printf("Lexicographical difference with \"%s\": %d\n", another_string, strcmp(string, another_string));

    char new_string[32];
    strcpy(new_string, string);
    printf("New string value: %s\n", new_string);

    // the destination string must be large enough to store itself and the source string
    char concatenadted_string[128];
    strcpy(concatenadted_string, string);

    strcat(concatenadted_string, another_string);
    printf("String concatenated with \"%s\": %s\n", another_string, concatenadted_string);

    return 0;
}
