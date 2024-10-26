#include <stdio.h>
#include "stack.h"

int main (void) {
    stack_type stack;
    stack_init(&stack);

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    printf("Top element is %d\n", stack_peek(stack));

    printf("Popped element is %d\n", stack_pop(&stack));
    printf("Popped element is %d\n", stack_pop(&stack));
    printf("Popped element is %d\n", stack_pop(&stack));

    if (stack_is_empty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    stack_free(&stack);

    return 0;
}