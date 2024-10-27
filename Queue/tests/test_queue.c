#include "assert.h"
#include "test_queue.h"

void test_queue_init () {
    queue_t queue;
    queue_init(&queue);
    assert(queue.front == NULL);
    assert(queue.rear == NULL);
    assert(queue.size == 0);
}

void test_queue_enqueue() {
    queue_t queue;
    queue_init(&queue);
    queue_enqueue(&queue, 0);
    assert(queue.size == 1);
    assert(queue.front->val == 0);
    assert(queue.rear->val == 0);
    queue_enqueue(&queue, 1);
    assert(queue.size == 2);
    assert(queue.front->val == 0);
    assert(queue.rear->val == 1);
}

void test_queue_dequeue() {
    queue_t queue;
    queue_init(&queue);
    assert(queue_dequeue(&queue) == -1);
    queue_enqueue(&queue, 0);
    queue_enqueue(&queue, 1);
    assert(queue_dequeue(&queue) == 0);
    assert(queue_dequeue(&queue) == 1);
    assert(queue_dequeue(&queue) == -1);
}

void test_queue_peek() {
    queue_t queue;
    queue_init(&queue);
    assert(queue_peek(&queue) == -1);
    queue_enqueue(&queue, 0);
    assert(queue_peek(&queue) == 0);
    queue_enqueue(&queue, 1);
    assert(queue_peek(&queue) == 0);
    queue_dequeue(&queue);
    assert(queue_peek(&queue) == 1);
    queue_dequeue(&queue);
    assert(queue_peek(&queue) == -1);
}

void test_queue_is_empty() {
    queue_t queue;
    queue_init(&queue);
    assert(queue_is_empty(&queue));
    queue_enqueue(&queue, 0);
    assert(!queue_is_empty(&queue));
    queue_dequeue(&queue);
    assert(queue_is_empty(&queue));
}

void test_queue_size() {
    queue_t queue;
    queue_init(&queue);
    assert(queue_size(&queue) == 0);
    queue_enqueue(&queue, 0);
    assert(queue_size(&queue) == 1);
    queue_enqueue(&queue, 1);
    assert(queue_size(&queue) == 2);
    queue_dequeue(&queue);
    assert(queue_size(&queue) == 1);
    queue_dequeue(&queue);
    assert(queue_size(&queue) == 0);
}

void test_queue_free() {
    queue_t queue;
    queue_init(&queue);
    queue_enqueue(&queue, 0);
    queue_enqueue(&queue, 1);
    queue_free(&queue);
    assert(queue.front == NULL);
    assert(queue.rear == NULL);
    assert(queue.size == 0);
}

void run_all_tests () {
    test_queue_init();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_peek();
    test_queue_is_empty();
    test_queue_size();
    test_queue_free();
}