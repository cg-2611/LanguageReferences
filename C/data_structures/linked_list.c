#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *link;
};

void add_front_node(struct node **head_p, int value);
void add_end_node(struct node **head_p, int value);
void add_node_index(struct node **head_p, int value, int index);
void remove_front_node(struct node **head_p);
void remove_end_node(struct node **head_p);
void remove_node_index(struct node **head_p, int index);
void free_linked_list(struct node *head);
void print_linked_list(struct node *head);

void add_front_node(struct node **head_p, int value)
{
    struct node *new_node = malloc(sizeof(*new_node));

    new_node->value = value;
    new_node->link = *head_p;

    *head_p = new_node;

    printf("Added node with value %d to front of linked list\n", value);
}

void add_end_node(struct node **head_p, int value)
{
    struct node *new_node = malloc(sizeof(*new_node));
    struct node *current_node = *head_p;

    while (current_node->link != NULL)
    {
        current_node = current_node->link;
    }

    new_node->value = value;
    new_node->link = NULL;

    current_node->link = new_node;

    printf("Added node with value %d to end of linked list\n", value);
}

void add_node_index(struct node **head_p, int value, int index)
{
    // if the index is 0 or less, insert the node at the front of the list
    if (index <= 0)
    {
        add_front_node(head_p, value);
        return;
    }

    struct node *new_node = malloc(sizeof(*new_node));
    struct node *current_node = *head_p;

    int i = 0;
    while (i++ != index - 1)
    {
        current_node = current_node->link;

        // if the index is beyond the length of the list, insert the node at the end of the list
        if (current_node->link == NULL)
        {
            add_end_node(head_p, value);
            return;
        }
    }

    new_node->value = value;
    new_node->link = current_node->link;
    current_node->link = new_node;

    printf("Added node with value %d at index %d\n", value, index);
}

void remove_front_node(struct node **head_p)
{
    struct node *temp_node = *head_p;

    *head_p = temp_node->link;

    free(temp_node);
    temp_node = NULL;

    printf("Removed front node\n");
}


void remove_end_node(struct node **head_p)
{
    struct node *temp_node;
    struct node *current_node = *head_p;

    while (current_node->link->link != NULL)
    {
        current_node = current_node->link;
    }

    temp_node = current_node->link;
    current_node->link = NULL;

    free(temp_node);
    temp_node = NULL;

    printf("Removed end node\n");
}

void remove_node_index(struct node **head_p, int index)
{
    // if the index is 0 or less, remove the node at the front of the list
    if (index <= 0)
    {
        remove_front_node(head_p);
        return;
    }

    struct node *temp_node;
    struct node *current_node = *head_p;

    int i = 0;
    while (i++ != index - 1)
    {
        current_node = current_node->link;

        // if the index is beyond the length of the list, remove the last node of the list
        if (current_node->link == NULL)
        {
            remove_end_node(head_p);
            return;
        }
    }

    temp_node = current_node->link;
    current_node->link = current_node->link->link;

    free(temp_node);
    temp_node = NULL;

    printf("Removed node at index %d\n", index);
}

void free_linked_list(struct node *head)
{
    struct node *temp_node;
    struct node *current_node = head;

    while (current_node != NULL)
    {
        temp_node = current_node;
        current_node = current_node->link;

        free(temp_node);
        temp_node = NULL;
    }
}

void print_linked_list(struct node *head)
{
    struct node *current_node = head;

    while (current_node != NULL)
    {
        printf("%d -> ", current_node->value);
        current_node = current_node->link;
    }

    printf("NULL\n");
}

int main(int argc, char *argv[])
{
    struct node *head = NULL;

    add_front_node(&head, 14);
    print_linked_list(head);
    add_front_node(&head, 11);
    print_linked_list(head);
    add_end_node(&head, 13);
    print_linked_list(head);
    add_node_index(&head, 12, 1);
    print_linked_list(head);
    remove_node_index(&head, 1);
    print_linked_list(head);
    remove_front_node(&head);
    print_linked_list(head);
    remove_end_node(&head);
    print_linked_list(head);
    add_front_node(&head, 17);
    print_linked_list(head);

    free_linked_list(head);

    return 0;
}
