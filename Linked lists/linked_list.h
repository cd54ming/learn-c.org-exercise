#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list (node_t *head);

void push (node_t **head, int val);

void unshift (node_t **head, int val);

int pop (node_t **head);

int shift (node_t **head);

int find_index_by_value(node_t *head, int val);

int find_value_by_index(node_t *head, int index);

int remove_by_value(node_t **head, int val);

int remove_by_index(node_t **head, int index);

void free_list(node_t **head);

#endif