#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} node_type;

typedef struct stack {
    node_type *top;
    int size;
} stack_type;

void stack_init(stack_type *stack);

void stack_push(stack_type *stack, int val);

int stack_pop(stack_type *stack);

int stack_peek(stack_type *stack);

void stack_print(stack_type *stack);

bool stack_is_empty(stack_type *stack);

void stack_free(stack_type *stac);

#endif // STACK_H