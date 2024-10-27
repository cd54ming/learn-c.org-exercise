#ifndef QUEUE_T
#define QUEUE_T
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

typedef struct queue {
    int size;
    node_t *front;
    node_t *rear;
} queue_t;

void queue_init(queue_t *queue);

void queue_enqueue(queue_t *queue, int val);

int queue_dequeue(queue_t *queue);

int queue_peek(queue_t *queue);

void queue_print(queue_t *queue);

bool queue_is_empty(queue_t *queue);

int queue_size(queue_t *queue);

void queue_free(queue_t *queue);

#endif // QUEUE_T