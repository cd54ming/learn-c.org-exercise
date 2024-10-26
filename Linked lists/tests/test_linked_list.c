#include <stdio.h>
#include "unity.h"
#include "../linked_list.h"

void setUp(void) {
    // Set up code if needed
}

void tearDown(void) {
    // Tear down code if needed
}

void test_push(void) {
    node_t *head = NULL;
    push(&head, 1);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NULL(head->next);

    push(&head, 2);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(2, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    free_list(&head);
}

void test_unshift(void) {
    node_t *head = NULL;
    unshift(&head, 1);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NULL(head->next);

    unshift(&head, 2);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(2, head->val);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(1, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    free_list(&head);
}

void test_pop(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int val = pop(&head);
    TEST_ASSERT_EQUAL_INT(3, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(2, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    val = pop(&head);
    TEST_ASSERT_EQUAL_INT(2, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NULL(head->next);

    val = pop(&head);
    TEST_ASSERT_EQUAL_INT(1, val);
    TEST_ASSERT_NULL(head);

    free_list(&head);
}

void test_shift(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int val = shift(&head);
    TEST_ASSERT_EQUAL_INT(1, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(2, head->val);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(3, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    val = shift(&head);
    TEST_ASSERT_EQUAL_INT(2, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(3, head->val);
    TEST_ASSERT_NULL(head->next);

    val = shift(&head);
    TEST_ASSERT_EQUAL_INT(3, val);
    TEST_ASSERT_NULL(head);

    free_list(&head);
}

void test_find_index_by_value(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int index = find_index_by_value(head, 2);
    TEST_ASSERT_EQUAL_INT(1, index);

    index = find_index_by_value(head, 3);
    TEST_ASSERT_EQUAL_INT(2, index);

    index = find_index_by_value(head, 4);
    TEST_ASSERT_EQUAL_INT(-1, index);

    free_list(&head);
}

void test_find_value_by_index(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int val = find_value_by_index(head, 1);
    TEST_ASSERT_EQUAL_INT(2, val);

    val = find_value_by_index(head, 2);
    TEST_ASSERT_EQUAL_INT(3, val);

    val = find_value_by_index(head, 3);
    TEST_ASSERT_EQUAL_INT(-1, val);

    free_list(&head);
}

void test_remove_by_value(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int index = remove_by_value(&head, 2);
    TEST_ASSERT_EQUAL_INT(1, index);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(3, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    index = remove_by_value(&head, 3);
    TEST_ASSERT_EQUAL_INT(1, index);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NULL(head->next);

    index = remove_by_value(&head, 1);
    TEST_ASSERT_EQUAL_INT(0, index);
    TEST_ASSERT_NULL(head);

    free_list(&head);
}

void test_remove_by_index(void) {
    node_t *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    int val = remove_by_index(&head, 1);
    TEST_ASSERT_EQUAL_INT(2, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_INT(3, head->next->val);
    TEST_ASSERT_NULL(head->next->next);

    val = remove_by_index(&head, 1);
    TEST_ASSERT_EQUAL_INT(3, val);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, head->val);
    TEST_ASSERT_NULL(head->next);

    val = remove_by_index(&head, 0);
    TEST_ASSERT_EQUAL_INT(1, val);
    TEST_ASSERT_NULL(head);

    free_list(&head);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_push);
    RUN_TEST(test_unshift);
    RUN_TEST(test_pop);
    RUN_TEST(test_shift);
    RUN_TEST(test_find_index_by_value);
    RUN_TEST(test_find_value_by_index);
    RUN_TEST(test_remove_by_value);
    RUN_TEST(test_remove_by_index);
    return UNITY_END();
}