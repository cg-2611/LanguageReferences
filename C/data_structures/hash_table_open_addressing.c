#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_ENTRY "--"

struct hash_table_entry
{
    char  *key;
    char  *value;
};

struct hash_table
{
    unsigned int max_size;
    int current_size;
    struct hash_table_entry **entries;
};

unsigned int hash_function(const char *key);
struct hash_table *initialize_hash_table(unsigned int max_size);
struct hash_table_entry *create_hash_table_entry(const char *key, const char *value);
void insert_entry(struct hash_table *ht, const char *key, const char *value);
void remove_entry(struct hash_table *ht, const char *key);
char *get_entry(struct hash_table *ht, const char  *key);
void print_hash_table(struct hash_table *ht);
void free_hash_table(struct hash_table *ht);

unsigned int hash_function(const char *key)
{
    unsigned int sum = 0;

    int i;
    for (i = 0; i < strlen(key); i++)
    {
        sum += (unsigned int)key[i];
    }

    return sum;
}

struct hash_table *initialize_hash_table(unsigned int max_size)
{
    struct hash_table *ht = malloc(sizeof(*ht));

    ht->max_size = max_size;
    ht->current_size = 0;

    ht->entries = calloc(max_size, sizeof(*ht->entries));

    return ht;
}

struct hash_table_entry *create_hash_table_entry(const char *key, const char *value)
{
    struct hash_table_entry *new_entry = malloc(sizeof(*new_entry));

    new_entry->key = malloc(strlen(key) + 1);
    new_entry->value = malloc(strlen(value) + 1);

    strcpy(new_entry->key, key);
    strcpy(new_entry->value, value);

    return new_entry;
}

void insert_entry(struct hash_table *ht, const char *key, const char *value)
{
    // return if hash table is full
    if (ht->current_size >= ht->max_size)
    {
        printf("Hash table full, cannot insert entry\n");
        return;
    }

    if (get_entry(ht, key) != NULL)
    {
        printf("Key already exists in hash table, cannot insert entry\n");
        return;
    }

    unsigned int index = hash_function(key) % ht->max_size;

    while (ht->entries[index] != NULL && strcmp(ht->entries[index]->key, EMPTY_ENTRY) != 0)
    {
        index++;
        index %= ht->max_size;
    }

    ht->entries[index] = create_hash_table_entry(key, value);
    ht->current_size++;
}

void remove_entry(struct hash_table *ht, const char *key)
{
    unsigned int index = hash_function(key) % ht->max_size;

    // perform linear probing with an interval of 1 until target key is found
    while (ht->entries[index] != NULL && strcmp(ht->entries[index]->key, EMPTY_ENTRY) != 0)
    {
        if (strcmp(ht->entries[index]->key, key) == 0)
        {
            strcpy(ht->entries[index]->key, EMPTY_ENTRY);
            ht->current_size--;
            return;
        }

        index++;
        index %= ht->max_size;
    }
}

char *get_entry(struct hash_table *ht, const char  *key)
{
    unsigned int index = hash_function(key) % ht->max_size;

    // perform linear probing with an interval of 1 until target key is found
    while (ht->entries[index] != NULL)
    {
        // return value of key if key found
        if (strcmp(ht->entries[index]->key, key) == 0)
        {
            return ht->entries[index]->value;
        }

        index++;
        index %= ht->max_size;
    }

    return NULL;
}

void print_hash_table(struct hash_table *ht)
{
    int i;
    for (i = 0; i < ht->max_size - 1; i++)
    {
        if (ht->entries[i] != NULL && strcmp(ht->entries[i]->key, EMPTY_ENTRY) != 0)
        {
            printf("[\"%s\", \"%s\"], ", ht->entries[i]->key, ht->entries[i]->value);
        }
        else
        {
            printf("[" EMPTY_ENTRY "], ");
        }
    }

    if (ht->entries[ht->max_size - 1] != NULL && strcmp(ht->entries[ht->max_size - 1]->key, EMPTY_ENTRY) != 0)
    {
        printf("[\"%s\", \"%s\"]\n", ht->entries[ht->max_size - 1]->key, ht->entries[ht->max_size - 1]->value);
    }
    else
    {
        printf("[" EMPTY_ENTRY "]\n");
    }
}

void free_hash_table(struct hash_table *ht)
{
    int i;
    for (i = 0; i < ht->max_size; i++)
    {
        if (ht->entries[i] != NULL)
        {
            free(ht->entries[i]->key);
            ht->entries[i]->key = NULL;

            free(ht->entries[i]->value);
            ht->entries[i]->value = NULL;
        }

        free(ht->entries[i]);
        ht->entries[i] = NULL;
    }

    free(ht->entries);
    ht->entries = NULL;

    free(ht);
    ht = NULL;
}

int main(int argc, char *argv[])
{
    struct hash_table *ht = initialize_hash_table(10);

    insert_entry(ht, "key 1", "value 1");
    insert_entry(ht, "key 2", "value 2");
    print_hash_table(ht);
    insert_entry(ht, "yek 1", "value 3");
    print_hash_table(ht);
    insert_entry(ht, "key 4", "value 4");
    insert_entry(ht, "key 7", "value 5");
    print_hash_table(ht);
    insert_entry(ht, "yek 4", "value 6");
    print_hash_table(ht);
    insert_entry(ht, "key 3", "value 8");
    insert_entry(ht, "eyk 4", "value 9");
    print_hash_table(ht);
    insert_entry(ht, "key 11", "value 10");
    print_hash_table(ht);
    remove_entry(ht, "key 1");
    remove_entry(ht, "yek 4");
    remove_entry(ht, "yek 7");
    print_hash_table(ht);

    printf("Value of key \"%s\": \"%s\"\n", "key 3", get_entry(ht, "key 3"));
    printf("Value of key \"%s\": \"%s\"\n", "eyk 4", get_entry(ht, "eyk 4"));

    free_hash_table(ht);

    return 0;
}