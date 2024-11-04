#ifndef BINARY_TREE_NODE_QUEUE_H
#define BINARY_TREE_NODE_QUEUE_H
#include <stdbool.h>
#include "../binary_tree_node.h"

typedef struct QueueNode QueueNode;
typedef struct Queue Queue;

Queue* queue_init();
bool queue_is_empty(Queue* queue);
void queue_enqueue(Queue* queue, BinaryTreeNode* node);
BinaryTreeNode* queue_dequeue(Queue* queue);
BinaryTreeNode* queue_peek(Queue* queue);
void queue_print(Queue* queue);
void queue_free(Queue* queue);

#endif // BINARY_TREE_NODE_QUEUE_H