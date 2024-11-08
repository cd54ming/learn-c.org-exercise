#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree_node_queue.h"

struct QueueNode {
    BinaryTreeNode* val;
    struct QueueNode* next;
};

struct Queue {
    int size;
    QueueNode* front;
    QueueNode* rear;
};

static QueueNode* create_node(BinaryTreeNode* val) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void queue_check(Queue* queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is not initialized\n");
        exit(EXIT_FAILURE);
    }
}

bool queue_is_empty(Queue* queue) {
    queue_check(queue);

    return (queue->front == NULL);
}

Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void queue_enqueue(Queue* queue, BinaryTreeNode* val) {
    queue_check(queue);

    QueueNode* new_node = create_node(val);
    if (queue_is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

BinaryTreeNode* queue_dequeue(Queue* queue) {
    queue_check(queue);

    if (queue_is_empty(queue)) {
        return NULL;
    }

    QueueNode* temp = queue->front;
    BinaryTreeNode* retval = temp->val;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return retval;
}

BinaryTreeNode* queue_peek(Queue* queue) {
    queue_check(queue);
    
    if(queue_is_empty(queue)) {
        return NULL;
    }

    return queue->front->val;
}

void queue_print(Queue* queue) {
    queue_check(queue);

    QueueNode* current = queue->front;
    while (current) {
        printf("%d", current->val->val);
        if (current->next) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

void queue_free(Queue* queue) {
    queue_check(queue);

    QueueNode* current = queue->front;
    QueueNode* prev;
    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }

    free(queue);
}