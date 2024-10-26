#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <assert.h>
#include "../stack.h"

void test_stack_init() {
    stack_type stack;
    stack_init(&stack);
    assert(stack_is_empty(stack));
}

void test_stack_push() {
    stack_type stack;
    stack_init(&stack);
    stack_push(&stack, 10);
    assert(!stack_is_empty(stack));
    assert(stack_peek(stack) == 10);
}

void test_stack_pop() {
    stack_type stack;
    stack_init(&stack);
    stack_push(&stack, 20);
    int val = stack_pop(&stack);
    assert(val == 20);
    assert(stack_is_empty(stack));
}

void test_stack_peek() {
    stack_type stack;
    stack_init(&stack);
    stack_push(&stack, 30);
    int val = stack_peek(stack);
    assert(val == 30);
    assert(!stack_is_empty(stack));
}

void test_stack_is_empty() {
    stack_type stack;
    stack_init(&stack);
    assert(stack_is_empty(stack));
    stack_push(&stack, 40);
    assert(!stack_is_empty(stack));
    stack_pop(&stack);
    assert(stack_is_empty(stack));
}

void test_stack_free() {
    stack_type stack;
    stack_init(&stack);
    stack_push(&stack, 50);
    stack_free(&stack);
    assert(stack_is_empty(stack));
}

void run_all_tests() {
    test_stack_init();
    test_stack_push();
    test_stack_pop();
    test_stack_peek();
    test_stack_is_empty();
    test_stack_free();
}

#endif // TEST_STACK_H