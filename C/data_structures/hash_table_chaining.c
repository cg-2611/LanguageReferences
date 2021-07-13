#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash_table_entry
{
    char  *key;
    char  *value;
    struct hash_table_entry *link;
};

struct hash_table
{
    unsigned int max_size;
    struct hash_table_entry **buckets;
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

    ht->buckets = calloc(max_size, sizeof(*ht->buckets));

    return ht;
}

struct hash_table_entry *create_hash_table_entry(const char *key, const char *value)
{
    struct hash_table_entry *new_entry = malloc(sizeof(*new_entry));

    new_entry->key = malloc(strlen(key) + 1);
    new_entry->value = malloc(strlen(value) + 1);

    strcpy(new_entry->key, key);
    strcpy(new_entry->value, value);
    new_entry->link = NULL;

    return new_entry;
}

void insert_entry(struct hash_table *ht, const char *key, const char *value)
{
    unsigned int bucket = hash_function(key) % ht->max_size;

    struct hash_table_entry *current_entry = ht->buckets[bucket];

    // insert new entry and return as no collision
    if (current_entry == NULL)
    {
        ht->buckets[bucket] = create_hash_table_entry(key, value);
        return;
    }

    struct hash_table_entry *previous_entry;

    while (current_entry != NULL)
    {
        // if the key is already in the hash table, replace the value
        if (strcmp(current_entry->key, key) == 0)
        {
            current_entry->value = realloc(current_entry->value, strlen(value) + 1);
            strcpy(current_entry->value, value);
            return;
        }

        previous_entry = current_entry;
        current_entry = previous_entry->link;
    }

    // insert new entry at the end of the chain if no matches
    previous_entry->link = create_hash_table_entry(key, value);
}

void remove_entry(struct hash_table *ht, const char *key)
{
    unsigned int bucket = hash_function(key) % ht->max_size;

    struct hash_table_entry *current_entry = ht->buckets[bucket];

    // return if bucket empty
    if (current_entry == NULL)
    {
        return;
    }

    struct hash_table_entry *previous_entry;
    int bucket_index = 0;

    while (current_entry != NULL)
    {
        // if the key is found remove the entry and change entry pointers where necessary
        if (strcmp(current_entry->key, key) == 0)
        {
            // only entry in bucket
            if (current_entry->link == NULL && bucket_index == 0)
            {
                ht->buckets[bucket] = NULL;
            }

            // first, but not only entry in bucket
            if (current_entry->link != NULL && bucket_index == 0)
            {
                ht->buckets[bucket] = current_entry->link;
            }

            // last entry in bucket
            if (current_entry->link == NULL && bucket_index != 0)
            {
                previous_entry->link = NULL;
            }

            // not first, not last entry in bucket
            if (current_entry->link != NULL && bucket_index != 0)
            {
                previous_entry->link = current_entry->link;
            }

            free(current_entry->key);
            current_entry->key = NULL;

            free(current_entry->value);
            current_entry->value = NULL;

            free(current_entry);
            current_entry = NULL;

            return;
        }

        previous_entry = current_entry;
        current_entry = previous_entry->link;

        bucket_index++;
    }
}

char *get_entry(struct hash_table *ht, const char  *key)
{
    unsigned int bucket = hash_function(key) % ht->max_size;

    struct hash_table_entry *current_entry = ht->buckets[bucket];

    // return NULL if bucket empty
    if (current_entry == NULL)
    {
        return NULL;
    }

    while (current_entry != NULL)
    {
        // return value of key if key found
        if (strcmp(current_entry->key, key) == 0)
        {
            return current_entry->value;
        }

        current_entry = current_entry->link;
    }

    // return NULL if bucket had entries, but no ket matched
    return NULL;
}

void print_hash_table(struct hash_table *ht)
{
    struct hash_table_entry *current_entry;

    int i;
    for (i = 0; i < ht->max_size; i++)
    {
       current_entry = ht->buckets[i];

        printf("bucket[%d]: ", i);

        if (current_entry != NULL)
        {
            while (current_entry->link != NULL)
            {
                printf("[\"%s\", \"%s\"], ", current_entry->key, current_entry->value);
                current_entry = current_entry->link;
            }

            printf("[\"%s\", \"%s\"]", current_entry->key, current_entry->value);
        }

        printf("\n");
    }

    printf("\n");
}

void free_hash_table(struct hash_table *ht)
{
    struct hash_table_entry *temp;
    struct hash_table_entry *current_entry;

    int i;
    for (i = 0; i < ht->max_size; i++)
    {
        current_entry = ht->buckets[i];

        while (current_entry != NULL)
        {
            temp = current_entry;

            current_entry = temp->link;

            free(temp->key);
            temp->key = NULL;

            free(temp->value);
            temp->value = NULL;

            free(temp);
            temp = NULL;
        }
    }

    free(ht->buckets);
    ht->buckets = NULL;

    free(ht);
    ht = NULL;
}

int main(int argc, char *argv[])
{
    struct hash_table *ht = initialize_hash_table(10);

    insert_entry(ht, "key 1", "value 1");
    insert_entry(ht, "key 2", "value 2");
    insert_entry(ht, "yek 1", "value 3");
    insert_entry(ht, "key 4", "value 4");
    insert_entry(ht, "key 7", "value 5");
    insert_entry(ht, "yek 4", "value 6");
    insert_entry(ht, "key 8", "value 7");
    insert_entry(ht, "key 3", "value 8");
    insert_entry(ht, "eyk 4", "value 9");
    insert_entry(ht, "key 11", "value 10");
    insert_entry(ht, "yek 7", "value 12");
    print_hash_table(ht);
    remove_entry(ht, "key 1");
    remove_entry(ht, "yek 4");
    remove_entry(ht, "yek 7");
    print_hash_table(ht);

    printf("Value of key \"%s\": \"%s\"\n", "key 3", get_entry(ht, "key 3"));
    printf("Value of key \"%s\": \"%s\"\n", "eyk 4", get_entry(ht, "eyk 4"));
    printf("Value of key \"%s\": \"%s\"\n", "key 10", get_entry(ht, "key 10"));

    free_hash_table(ht);

    return 0;
}
