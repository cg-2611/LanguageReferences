#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    unsigned int max_size;
    int front;
    int rear;
    int size;
    int *array;
};

struct queue *initialize_queue(unsigned int max_size);
void free_queue(struct queue *queue_to_free);
void enqueue(struct queue *q, int item);
int dequeue(struct queue *q);
int is_empty(struct queue *q);
int is_full(struct queue *q);

struct queue *initialize_queue(unsigned int max_size)
{
    struct queue *q = malloc(sizeof(*q));

    q->max_size = max_size;
    q->front = 0;
    q->size = 0;
    q->rear = max_size - 1;

    q->array = malloc(max_size * sizeof(*q->array));

    return q;
}

void free_queue(struct queue *queue_to_free)
{
    free(queue_to_free->array);
    queue_to_free->array = NULL;

    free(queue_to_free);
    queue_to_free = NULL;
}

void enqueue(struct queue *q, int item)
{
    if (is_full(q))
    {
        printf("Queue full, cannot enqueue item %d\n", item);
        return;
    }

    q->rear = (q->rear + 1) % q->max_size;
    q->array[q->rear] = item;
    q->size++;
    printf("Enqueued item %d to queue\n", item);
}

int dequeue(struct queue *q)
{
    if (is_empty(q))
    {
        printf("Queue empty, cannot dequeue item\n");
        return INT_MIN;
    }

    int item = q->array[q->front];
    q->front = (q->front + 1) % q->max_size;
    q->size--;
    printf("Dequeued item %d\n", item);
    return item;
}

int is_empty(struct queue *q)
{
    return q->size == 0;
}

int is_full(struct queue *q)
{
    return q->size == q->max_size;
}

int main(int argc, char *argv[])
{
    struct queue *q = initialize_queue(5);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 9);
    dequeue(q);
    enqueue(q, 13);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q, 3);
    enqueue(q, 7);
    enqueue(q, 11);

    free_queue(q);

    return 0;
}
