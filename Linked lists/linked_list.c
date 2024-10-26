
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list (node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
}

void push (node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof (node_t));
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void unshift (node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof (node_t));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop (node_t **head) {
    if (*head == NULL) {
        return -1;
    }

    int retval;

    if ((*head)->next == NULL) {
        retval = (*head)->val;
        free(*head);
        *head = NULL;
        return retval;
    }

    node_t *current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    retval = current->next->val;
    free(current->next);
    current->next = NULL;

    return retval;
}

int shift (node_t **head) {
    if (*head == NULL) {
        return -1;
    }

    int retval = (*head)->val;
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
    return retval;
}

int find_index_by_value(node_t *head, int val) {
    int index = 0;
    node_t *current = head;

    while (current != NULL) {
        if (current->val == val) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int find_value_by_index(node_t *head, int index) {
    if (head == NULL || index < 0) {
        return -1;
    }

    node_t *current = head;

    for (int i = 0; i < index; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    return current->val;
}

int remove_by_value(node_t **head, int val) {
    if (*head == NULL) {
        return -1;
    }

    int index = 0;
    node_t *current = *head;
    
    if (current->val == val) {
        *head = current->next;
        free(current);
        return index;
    }

    node_t *prev = current;
    current = current->next;
    index++;

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
            free(current);
            return index;
        }
        prev = current;
        current = current->next;
        index++;
    }

    return -1;
}

int remove_by_index(node_t **head, int index) {
    if (*head == NULL || index < 0) {
        return -1;
    }

    int retval;
    node_t *current = *head;

    if (index == 0) {
        retval = (*head)->val;
        *head = (*head)->next;
        free(current);
        return retval;
    }
    
    for (int i = 0; i < (index - 1); i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    node_t *temp = current->next;
    retval = temp->val;
    current->next = temp->next;
    free(temp);

    return retval;
}

void free_list (node_t **head) {
    node_t *current = *head;
    node_t *prev = NULL;

    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }

    *head = NULL;
}