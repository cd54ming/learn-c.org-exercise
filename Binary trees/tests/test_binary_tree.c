#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../binary_tree.h"

void test_insert_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    assert(tree->root != NULL && tree->root->val == 10);

    binary_tree_insert_node_bfs(tree, 20);
    assert(tree->root->left != NULL && tree->root->left->val == 20);

    binary_tree_insert_node_bfs(tree, 30);
    assert(tree->root->right != NULL && tree->root->right->val == 30);

    binary_tree_insert_node_bfs(tree, 40);
    assert(tree->root->left->left != NULL && tree->root->left->left->val == 40);

    binary_tree_insert_node_bfs(tree, 50);
    assert(tree->root->left->right != NULL && tree->root->left->right->val == 50);

    binary_tree_insert_node_bfs(tree, 60);
    assert(tree->root->right->left != NULL && tree->root->right->left->val == 60);

    binary_tree_insert_node_bfs(tree, 70);
    assert(tree->root->right->right != NULL && tree->root->right->right->val == 70);

    free_tree_bfs(tree);
}

void test_find_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* node = find_node_bfs(tree, 7);
    assert(node != NULL && node->val == 7);

    node = find_node_bfs(tree, 20);
    assert(node == NULL);

    free_tree_bfs(tree);
}

void test_find_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* node = find_node_dfs(tree, 7);
    assert(node != NULL && node->val == 7);

    node = find_node_dfs(tree, 20);
    assert(node == NULL);

    free_tree_dfs(tree);
}

void test_find_last_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* node = find_last_node_bfs(tree);
    assert(node != NULL && node->val == 18);

    free_tree_bfs(tree);
}

void test_find_last_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);


    BinaryTreeNode* node = find_last_node_dfs(tree);
    assert(node != NULL && node->val == 18);

    free_tree_dfs(tree);
}

void test_find_parent_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* parent = find_parent_node_bfs(tree, 7);
    assert(parent != NULL && parent->val == 5);
    assert(parent->val == 5);

    parent = find_parent_node_bfs(tree, 10);
    assert(parent == NULL);

    parent = find_parent_node_bfs(tree, 100);
    assert(parent == NULL);

    free_tree_bfs(tree);
}

void test_find_parent_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* parent = find_parent_node_dfs(tree, 7);
    assert(parent != NULL && parent->val == 5);
    assert(parent->val == 5);

    parent = find_parent_node_dfs(tree, 10);
    assert(parent == NULL);

    parent = find_parent_node_bfs(tree, 100);
    assert(parent == NULL);

    free_tree_dfs(tree);
}

void test_delete_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    delete_node_bfs(tree, 7);
    BinaryTreeNode* node = find_node_bfs(tree, 7);
    assert(node == NULL);

    delete_node_bfs(tree, 10);
    node = find_node_bfs(tree, 10);
    assert(node == NULL);

    free_tree_bfs(tree);
}

void test_delete_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    delete_node_dfs(tree, 7);
    BinaryTreeNode* node = find_node_dfs(tree, 7);
    assert(node == NULL);

    delete_node_dfs(tree, 10);
    node = find_node_dfs(tree, 10);
    assert(node == NULL);

    free_tree_dfs(tree);
}

void test_generate_tree_bfs() {
    int values[] = { 10, 5, 15, 3, 7, 12, 18 };
    BinaryTree* tree = generate_tree_bfs(values, 7);

    BinaryTreeNode* node = find_node_bfs(tree, 10);
    assert(node != NULL && node->val == 10);
    node = find_node_bfs(tree, 5);
    assert(node != NULL && node->val == 5);
    node = find_node_bfs(tree, 15);
    assert(node != NULL && node->val == 15);
    node = find_node_bfs(tree, 3);
    assert(node != NULL && node->val == 3);
    node = find_node_bfs(tree, 7);
    assert(node != NULL && node->val == 7);
    node = find_node_bfs(tree, 12);
    assert(node != NULL && node->val == 12);
    node = find_node_bfs(tree, 18);
    assert(node != NULL && node->val == 18);

    free_tree_bfs(tree);
}

void test_generate_tree_dfs() {
    int values[] = { 10, 5, 15, 3, 7, 12, 18 };
    BinaryTree* tree = generate_tree_bfs(values, 7);

    BinaryTreeNode* node = find_node_dfs(tree, 10);
    assert(node != NULL && node->val == 10);
    node = find_node_dfs(tree, 5);
    assert(node != NULL && node->val == 5);
    node = find_node_dfs(tree, 15);
    assert(node != NULL && node->val == 15);
    node = find_node_dfs(tree, 3);
    assert(node != NULL && node->val == 3);
    node = find_node_dfs(tree, 7);
    assert(node != NULL && node->val == 7);
    node = find_node_dfs(tree, 12);
    assert(node != NULL && node->val == 12);
    node = find_node_dfs(tree, 18);
    assert(node != NULL && node->val == 18);

    free_tree_dfs(tree);
}

void test_find_min_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* min_node = find_min_node_bfs(tree);
    assert(min_node != NULL && min_node->val == 3);

    free_tree_bfs(tree);
}

void test_find_min_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* min_node = find_min_node_bfs(tree);
    assert(min_node != NULL && min_node->val == 3);

    free_tree_bfs(tree);
}

void test_find_max_node_bfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* max_node = find_max_node_bfs(tree);
    assert(max_node != NULL && max_node->val == 18);

    free_tree_bfs(tree);
}

void test_find_max_node_dfs() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    BinaryTreeNode* max_node = find_max_node_dfs(tree);
    assert(max_node != NULL && max_node->val == 18);

    free_tree_dfs(tree);
}

void test_traverse_in_order() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_values[] = { 2, 3, 9, 5, 4, 7, 10, 12, 15, 18 };
    printf("Inorder expected: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", expected_values[i]);
    }
    printf("\n");
    printf("Actual: ");
    traverse_in_order(tree);

    free_tree_bfs(tree);
}

void test_traverse_pre_order() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_values[] = { 10, 5, 3, 2, 9, 7, 4, 15, 12, 18 };
    printf("Pre order expected: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", expected_values[i]);
    }
    printf("\n");
    printf("Actual: ");
    traverse_pre_order(tree);

    free_tree_bfs(tree);
}

void test_traverse_post_order() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_values[] = { 2, 9, 3, 4, 7, 5, 12, 18, 15, 10 };
    printf("Post order expected: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", expected_values[i]);
    }
    printf("\n");
    printf("Actual: ");
    traverse_post_order(tree);

    free_tree_bfs(tree);
}

void test_traverse_level_order() {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_values[] = { 10, 5, 15, 3, 7, 12, 18, 2, 9, 4 };
    printf("Level order expected: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", expected_values[i]);
    }
    printf("\n");
    printf("Actual: ");
    traverse_level_order(tree);

    free_tree_bfs(tree);
}

void test_get_size_bfs() {
    BinaryTree* empty_tree = binary_tree_init();
    assert(get_size_bfs(empty_tree) == 0);
    free_tree_bfs(empty_tree);

    BinaryTree* single_node_tree = binary_tree_init();
    binary_tree_insert_node_bfs(single_node_tree, 10);
    assert(get_size_bfs(single_node_tree) == 1);
    free_tree_bfs(single_node_tree);

    int values1[] = { 10, 5, 15 };
    BinaryTree* small_tree = generate_tree_bfs(values1, 3);
    assert(get_size_bfs(small_tree) == 3);
    free_tree_bfs(small_tree);

    int values2[] = { 10, 5, 15, 3, 7, 12, 18, 2, 9, 4 };
    BinaryTree* large_tree = generate_tree_bfs(values2, 10);
    assert(get_size_bfs(large_tree) == 10);
    free_tree_bfs(large_tree);
}

void test_get_size_dfs() {
    int values[] = { 10, 5, 15, 3, 7, 12, 18, 2, 9, 4 };
    BinaryTree* tree = generate_tree_bfs(values, 10);
    assert(get_size_dfs(tree) == 10);
    free_tree_dfs(tree);
    tree = generate_tree_bfs(values, 0);
    assert(get_size_dfs(tree) == 0);
    free_tree_bfs(tree);
}

void test_get_height() {
    BinaryTree* tree = binary_tree_init();

    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_height = 4;
    int height = get_height(tree->root);

    assert(height == expected_height);

    free_tree_bfs(tree);
}

void test_get_depth() {
    BinaryTree* tree = binary_tree_init();

    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);
    binary_tree_insert_node_bfs(tree, 2);
    binary_tree_insert_node_bfs(tree, 9);
    binary_tree_insert_node_bfs(tree, 4);

    int expected_depth = 0;
    int depth = get_depth(tree->root, find_node_bfs(tree, 10));
    assert(depth == expected_depth);

    expected_depth = 1;
    depth = get_depth(tree->root, find_node_bfs(tree, 5));
    assert(depth == expected_depth);

    expected_depth = 2;
    depth = get_depth(tree->root, find_node_bfs(tree, 12));
    assert(depth == expected_depth);

    expected_depth = 3;
    depth = get_depth(tree->root, find_node_bfs(tree, 4));
    assert(depth == expected_depth);

    expected_depth = -1;
    BinaryTreeNode* non_existent_node = binary_tree_create_node(100);
    depth = get_depth(tree->root, non_existent_node);
    assert(depth == expected_depth);

    free_tree_bfs(tree);
}

void test_is_empty(void) {
    BinaryTree* tree = binary_tree_init();
    assert(is_empty(tree) == true);

    binary_tree_insert_node_bfs(tree, 10);
    assert(is_empty(tree) == false);
}

void test_is_in_tree_bfs(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 10)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 5)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 15)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 3)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 7)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 12)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 18)) == true);
    assert(is_in_tree_bfs(tree, find_node_bfs(tree, 100)) == false);

    BinaryTreeNode* node = binary_tree_create_node(100);
    assert(is_in_tree_bfs(tree, node) == false);
    free(node);

    node = binary_tree_create_node(10);
    assert(is_in_tree_bfs(tree, node) == false);
    free(node);

    free_tree_bfs(tree);
}

void test_is_in_tree_dfs(void) {
BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 10)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 5)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 15)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 3)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 7)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 12)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 18)) == true);
    assert(is_in_tree_dfs(tree, find_node_bfs(tree, 100)) == false);

    BinaryTreeNode* node = binary_tree_create_node(100);
    assert(is_in_tree_dfs(tree, node) == false);
    free(node);

    node = binary_tree_create_node(10);
    assert(is_in_tree_dfs(tree, node) == false);
    free(node);

    free_tree_bfs(tree);
}

void test_is_sibling(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_sibling(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 7)) == true);
    assert(is_sibling(tree, find_node_bfs(tree, 12), find_node_bfs(tree, 18)) == true);
    assert(is_sibling(tree, find_node_bfs(tree, 5), find_node_bfs(tree, 15)) == true);
    assert(is_sibling(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 12)) == false);

    assert(is_sibling(tree, find_node_bfs(tree, 10), find_node_bfs(tree, 7)) == false);
    assert(is_sibling(tree, NULL, find_node_bfs(tree, 7)) == false);
    assert(is_sibling(tree, find_node_bfs(tree, 3), NULL) == false);
    assert(is_sibling(tree, NULL, NULL) == false);
    assert(is_sibling(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 100)) == false);

    free_tree_bfs(tree);
}

void test_is_internal(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    assert(is_internal(tree->root) == false);

    binary_tree_insert_node_bfs(tree, 5);
    assert(is_internal(tree->root) == true);
    assert(is_internal(tree->root->left) == false);

    binary_tree_insert_node_bfs(tree, 15);
    assert(is_internal(tree->root) == true);
    assert(is_internal(tree->root->left) == false);
    assert(is_internal(tree->root->right) == false);

    binary_tree_insert_node_bfs(tree, 3);
    assert(is_internal(tree->root) == true);
    assert(is_internal(tree->root->left) == true);
    assert(is_internal(tree->root->right) == false);
    assert(is_internal(tree->root->left->left) == false);

    binary_tree_insert_node_bfs(tree, 7);
    assert(is_internal(tree->root) == true);
    assert(is_internal(tree->root->left) == true);
    assert(is_internal(tree->root->right) == false);
    assert(is_internal(tree->root->left->left) == false);
    assert(is_internal(tree->root->left->right) == false);

    free_tree_bfs(tree);
}

void test_is_external(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    assert(is_external(tree->root) == true);

    binary_tree_insert_node_bfs(tree, 5);
    assert(is_external(tree->root) == false);
    assert(is_external(tree->root->left) == true);

    binary_tree_insert_node_bfs(tree, 15);
    assert(is_external(tree->root) == false);
    assert(is_external(tree->root->left) == true);
    assert(is_external(tree->root->right) == true);

    binary_tree_insert_node_bfs(tree, 3);
    assert(is_external(tree->root) == false);
    assert(is_external(tree->root->left) == false);
    assert(is_external(tree->root->right) == true);
    assert(is_external(tree->root->left->left) == true);

    binary_tree_insert_node_bfs(tree, 7);
    assert(is_external(tree->root) == false);
    assert(is_external(tree->root->left) == false);
    assert(is_external(tree->root->right) == true);
    assert(is_external(tree->root->left->left) == true);
    assert(is_external(tree->root->left->right) == true);
}

void test_is_parent(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 5)) == true);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 15)) == true);
    assert(is_parent(find_node_bfs(tree, 5), find_node_bfs(tree, 3)) == true);
    assert(is_parent(find_node_bfs(tree, 5), find_node_bfs(tree, 7)) == true);
    assert(is_parent(find_node_bfs(tree, 15), find_node_bfs(tree, 12)) == true);
    assert(is_parent(find_node_bfs(tree, 15), find_node_bfs(tree, 18)) == true);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 3)) == false);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 7)) == false);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 12)) == false);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 18)) == false);
    assert(is_parent(find_node_bfs(tree, 5), find_node_bfs(tree, 10)) == false);
    assert(is_parent(find_node_bfs(tree, 10), find_node_bfs(tree, 10)) == false);
    assert(is_parent(find_node_bfs(tree, 12), find_node_bfs(tree, 12)) == false);

    free_tree_bfs(tree);
}

void test_is_child(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_child(find_node_bfs(tree, 5), find_node_bfs(tree, 10)) == true);
    assert(is_child(find_node_bfs(tree, 15), find_node_bfs(tree, 10)) == true);
    assert(is_child(find_node_bfs(tree, 3), find_node_bfs(tree, 5)) == true);
    assert(is_child(find_node_bfs(tree, 7), find_node_bfs(tree, 5)) == true);
    assert(is_child(find_node_bfs(tree, 12), find_node_bfs(tree, 15)) == true);
    assert(is_child(find_node_bfs(tree, 18), find_node_bfs(tree, 15)) == true);
    assert(is_child(find_node_bfs(tree, 3), find_node_bfs(tree, 10)) == false);
    assert(is_child(find_node_bfs(tree, 7), find_node_bfs(tree, 10)) == false);
    assert(is_child(find_node_bfs(tree, 12), find_node_bfs(tree, 10)) == false);
    assert(is_child(find_node_bfs(tree, 18), find_node_bfs(tree, 10)) == false);
    assert(is_child(find_node_bfs(tree, 10), find_node_bfs(tree, 5)) == false);
    assert(is_child(find_node_bfs(tree, 10), find_node_bfs(tree, 10)) == false);
    assert(is_child(find_node_bfs(tree, 12), find_node_bfs(tree, 12)) == false);

    free_tree_bfs(tree);
}

void test_is_ancestor(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 5)) == true);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 15)) == true);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 3)) == true);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 7)) == true);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 12)) == true);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 18)) == true);
    assert(is_ancestor(find_node_bfs(tree, 5), find_node_bfs(tree, 3)) == true);
    assert(is_ancestor(find_node_bfs(tree, 5), find_node_bfs(tree, 7)) == true);
    assert(is_ancestor(find_node_bfs(tree, 15), find_node_bfs(tree, 12)) == true);
    assert(is_ancestor(find_node_bfs(tree, 15), find_node_bfs(tree, 18)) == true);
    assert(is_ancestor(find_node_bfs(tree, 5), find_node_bfs(tree, 15)) == false);
    assert(is_ancestor(find_node_bfs(tree, 3), find_node_bfs(tree, 7)) == false);
    assert(is_ancestor(find_node_bfs(tree, 7), find_node_bfs(tree, 3)) == false);
    assert(is_ancestor(find_node_bfs(tree, 12), find_node_bfs(tree, 18)) == false);
    assert(is_ancestor(find_node_bfs(tree, 18), find_node_bfs(tree, 12)) == false);
    assert(is_ancestor(find_node_bfs(tree, 18), find_node_bfs(tree, 10)) == false);
    assert(is_ancestor(find_node_bfs(tree, 10), find_node_bfs(tree, 10)) == false);
    assert(is_ancestor(find_node_bfs(tree, 18), find_node_bfs(tree, 18)) == false);

    free_tree_bfs(tree);
}

void test_is_descendant(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_descendant(find_node_bfs(tree, 5), find_node_bfs(tree, 10)) == true);
    assert(is_descendant(find_node_bfs(tree, 15), find_node_bfs(tree, 10)) == true);
    assert(is_descendant(find_node_bfs(tree, 3), find_node_bfs(tree, 10)) == true);
    assert(is_descendant(find_node_bfs(tree, 7), find_node_bfs(tree, 10)) == true);
    assert(is_descendant(find_node_bfs(tree, 12), find_node_bfs(tree, 15)) == true);
    assert(is_descendant(find_node_bfs(tree, 18), find_node_bfs(tree, 15)) == true);
    assert(is_descendant(find_node_bfs(tree, 3), find_node_bfs(tree, 5)) == true);
    assert(is_descendant(find_node_bfs(tree, 7), find_node_bfs(tree, 5)) == true);
    assert(is_descendant(find_node_bfs(tree, 15), find_node_bfs(tree, 5)) == false);
    assert(is_descendant(find_node_bfs(tree, 7), find_node_bfs(tree, 3)) == false);
    assert(is_descendant(find_node_bfs(tree, 3), find_node_bfs(tree, 7)) == false);
    assert(is_descendant(find_node_bfs(tree, 18), find_node_bfs(tree, 12)) == false);
    assert(is_descendant(find_node_bfs(tree, 12), find_node_bfs(tree, 18)) == false);
    assert(is_descendant(find_node_bfs(tree, 10), find_node_bfs(tree, 18)) == false);
    assert(is_descendant(find_node_bfs(tree, 10), find_node_bfs(tree, 10)) == false);
    assert(is_descendant(find_node_bfs(tree, 18), find_node_bfs(tree, 18)) == false);

    free_tree_bfs(tree);
}

void test_is_cousin(void) {
    BinaryTree* tree = binary_tree_init();
    binary_tree_insert_node_bfs(tree, 10);
    binary_tree_insert_node_bfs(tree, 5);
    binary_tree_insert_node_bfs(tree, 15);
    binary_tree_insert_node_bfs(tree, 3);
    binary_tree_insert_node_bfs(tree, 7);
    binary_tree_insert_node_bfs(tree, 12);
    binary_tree_insert_node_bfs(tree, 18);

    assert(is_cousin(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 12)) == true);
    assert(is_cousin(tree, find_node_bfs(tree, 7), find_node_bfs(tree, 18)) == true);
    assert(is_cousin(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 18)) == true);
    assert(is_cousin(tree, find_node_bfs(tree, 5), find_node_bfs(tree, 15)) == false);
    assert(is_cousin(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 7)) == false);
    assert(is_cousin(tree, find_node_bfs(tree, 12), find_node_bfs(tree, 18)) == false);
    assert(is_cousin(tree, find_node_bfs(tree, 10), find_node_bfs(tree, 7)) == false);
    assert(is_cousin(tree, NULL, find_node_bfs(tree, 7)) == false);
    assert(is_cousin(tree, find_node_bfs(tree, 3), NULL) == false);
    assert(is_cousin(tree, NULL, NULL) == false);
    assert(is_cousin(tree, find_node_bfs(tree, 3), find_node_bfs(tree, 100)) == false);

    BinaryTreeNode* node1 = binary_tree_create_node(100);
    BinaryTreeNode* node2 = binary_tree_create_node(200);
    assert(is_cousin(tree, node1, node2) == false);
    free(node1);
    free(node2);

    free_tree_bfs(tree);
}

void test_is_full_bfs(void) {
    BinaryTree* tree = binary_tree_init();
    assert(is_full_bfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 10);
    assert(is_full_bfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 5);
    assert(is_full_bfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 15);
    assert(is_full_bfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 3);
    assert(is_full_bfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 7);
    assert(is_full_bfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 12);
    assert(is_full_bfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 18);
    assert(is_full_bfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 9);
    assert(is_full_bfs(tree) == false);

    free_tree_bfs(tree);
}

void test_is_full_dfs(void) {
    BinaryTree* tree = binary_tree_init();
    assert(is_full_dfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 10);
    assert(is_full_dfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 5);
    assert(is_full_dfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 15);
    assert(is_full_dfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 3);
    assert(is_full_dfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 7);
    assert(is_full_dfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 12);
    assert(is_full_dfs(tree) == false);

    binary_tree_insert_node_bfs(tree, 18);
    assert(is_full_dfs(tree) == true);

    binary_tree_insert_node_bfs(tree, 9);
    assert(is_full_dfs(tree) == false);

    free_tree_dfs(tree);
}

void run_all_test(void) {
    test_insert_node_bfs();
    test_insert_node_bfs();
    test_find_node_bfs();
    test_find_node_dfs();
    test_find_last_node_bfs();
    test_find_last_node_dfs();
    test_find_parent_node_bfs();
    test_find_parent_node_dfs();
    test_delete_node_bfs();
    test_delete_node_dfs();
    test_generate_tree_bfs();
    test_generate_tree_dfs();
    test_find_min_node_bfs();
    test_find_min_node_dfs();
    test_find_max_node_bfs();
    test_find_max_node_dfs();
    test_traverse_in_order();
    test_traverse_pre_order();
    test_traverse_post_order();
    test_traverse_level_order();
    test_get_size_bfs();
    test_get_size_dfs();
    test_get_height();
    test_get_depth();
    test_is_empty();
    test_is_in_tree_bfs();
    test_is_in_tree_dfs();
    test_is_internal();
    test_is_external();
    test_is_parent();
    test_is_child();
    test_is_ancestor();
    test_is_descendant();
    test_is_sibling();
    test_is_cousin();
    test_is_full_bfs();
    test_is_full_dfs();
}

int main(void) {
    run_all_test();
    printf("All tests passed!\n");
    return 0;
}