
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(stack_type *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void stack_push(stack_type *stack, int val) {
    node_type *new_node = (node_type *) malloc(sizeof (node_type));
    new_node->val = val;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int stack_pop(stack_type *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    node_type *temp = stack->top;
    int retval = temp->val;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return retval;
}

int stack_peek(stack_type *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    return stack->top->val;
}

void stack_print(stack_type *stack) {
    node_type *current = stack->top;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

bool stack_is_empty(stack_type *stack) {
    return (stack->top == NULL);
}

void stack_free(stack_type *stack) {
    node_type *current = stack->top;

    while (current != NULL) {
        stack->top = current->next;
        free(current);
        current = stack->top;
    }

    stack->top = NULL;
    stack->size = 0;
}