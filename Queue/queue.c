#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

void queue_init (queue_t *queue) {
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

void check_queue(queue_t *queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is not initialized\n");
        exit(EXIT_FAILURE);
    }
}

void queue_enqueue(queue_t *queue, int val) {
    check_queue(queue);

    node_t *new_node = (node_t *) malloc(sizeof (node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->val = val;
    new_node->next = NULL;
    if (queue->front == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

int queue_dequeue(queue_t *queue) {
    check_queue(queue);
    if (queue_is_empty(queue)) {
        return -1;
    }

    node_t *temp = queue->front;
    int retval = temp->val;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return retval;
}

int queue_peek(queue_t *queue) {
    check_queue(queue);
    if (queue_is_empty(queue)) {
        return -1;
    }

    return queue->front->val;
}

void queue_print(queue_t *queue) {
    check_queue(queue);

    node_t *current = queue->front;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

bool queue_is_empty(queue_t *queue) {
    check_queue(queue);
    return (queue->front == NULL);
}

int queue_size(queue_t *queue) {
    check_queue(queue);
    return queue->size;
}

void queue_free(queue_t *queue) {
    check_queue(queue);

    node_t *current = queue->front;
    node_t *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}
