

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../binary_tree_node_queue.h"

void test_binary_tree_node_queue(void) {
    // Initialize queue
    Queue* queue = queue_init();
    assert(queue != NULL);
    assert(queue_is_empty(queue) == true);

    // Create binary tree nodes
    BinaryTreeNode node1 = { .val = 1, .left = NULL, .right = NULL };
    BinaryTreeNode node2 = { .val = 2, .left = NULL, .right = NULL };
    BinaryTreeNode node3 = { .val = 3, .left = NULL, .right = NULL };

    // Enqueue nodes
    queue_enqueue(queue, &node1);
    assert(queue_is_empty(queue) == false);
    assert(queue_peek(queue) == &node1);

    queue_enqueue(queue, &node2);
    assert(queue_peek(queue) == &node1);

    queue_enqueue(queue, &node3);
    assert(queue_peek(queue) == &node1);

    // Dequeue nodes
    BinaryTreeNode* dequeued_node = queue_dequeue(queue);
    assert(dequeued_node == &node1);
    assert(queue_peek(queue) == &node2);

    dequeued_node = queue_dequeue(queue);
    assert(dequeued_node == &node2);
    assert(queue_peek(queue) == &node3);

    dequeued_node = queue_dequeue(queue);
    assert(dequeued_node == &node3);
    assert(queue_is_empty(queue) == true);

    // Free queue
    queue_free(queue);
}

int main(void) {
    test_binary_tree_node_queue();
    printf("Queue tests passed\n");
    return 0;
}
