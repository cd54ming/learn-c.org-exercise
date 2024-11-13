#ifndef BINARY_TREE_UTILS_H
#define BINARY_TREE_UTILS_H
#include <stdbool.h>
#include "binary_tree_node.h"

typedef struct BinaryTree {
    BinaryTreeNode* root;
} BinaryTree;

BinaryTree* binary_tree_init();
BinaryTreeNode* binary_tree_create_node(int val);
BinaryTreeNode* binary_tree_insert_node_bfs(BinaryTree* tree, int val);
BinaryTreeNode* find_node_bfs(BinaryTree* tree, int val);
BinaryTreeNode* find_node_dfs(BinaryTree* tree, int val);
BinaryTreeNode* find_last_node_bfs(BinaryTree* tree);
BinaryTreeNode* find_last_node_dfs(BinaryTree* tree);
BinaryTreeNode* find_parent_node_bfs(BinaryTree* tree, int val);
BinaryTreeNode* find_parent_node_dfs(BinaryTree* tree, int val);
void delete_node_bfs(BinaryTree* tree, int val);
void delete_node_dfs(BinaryTree* tree, int val);
void free_tree_bfs(BinaryTree* root);
void free_tree_dfs(BinaryTree* root);
BinaryTree* generate_tree_bfs(int arr[], int size);
BinaryTreeNode* find_min_node_bfs(BinaryTree* tree);
BinaryTreeNode* find_min_node_dfs(BinaryTree* node);
BinaryTreeNode* find_max_node_bfs(BinaryTree* node);
BinaryTreeNode* find_max_node_dfs(BinaryTree* node);
void traverse_in_order(BinaryTree* tree);
void traverse_pre_order(BinaryTree* root);
void traverse_post_order(BinaryTree* root);
void traverse_level_order(BinaryTree* root);
int get_size_bfs(BinaryTree* root);
int get_size_dfs(BinaryTree* root);
int get_height(BinaryTreeNode* node);
int get_depth(BinaryTreeNode* root, BinaryTreeNode* node);
bool is_empty(BinaryTree* root);
bool is_in_tree_bfs(BinaryTree* tree, BinaryTreeNode* node);
bool is_in_tree_dfs(BinaryTree* tree, BinaryTreeNode* node);

// a node is internal if it has at least one child
bool is_internal(BinaryTreeNode* node);

// a node is external if it has no children
bool is_external(BinaryTreeNode* node);

// nodes are parents if one is the child of the other
bool is_parent(BinaryTreeNode* parent, BinaryTreeNode* node);

// nodes are children if one is the parent of the other
bool is_child(BinaryTreeNode* child, BinaryTreeNode* node);

// a node is either the parent of the node or the parent of some ancestor of the node
bool is_ancestor(BinaryTreeNode* ancestor, BinaryTreeNode* node);

// a node is either the child of the node or the child of some descendant of the node
bool is_descendant(BinaryTreeNode* descendant, BinaryTreeNode* node);

// nodes are siblings if they have the same parent
bool is_sibling(BinaryTree* tree, BinaryTreeNode* node1, BinaryTreeNode* node2);

// nodes are cousins if they are at the same level and have different parents
bool is_cousin(BinaryTree* tree, BinaryTreeNode* node1, BinaryTreeNode* node2);

// every node has either 0 or 2 children.
bool is_full_bfs(BinaryTree* tree);
bool is_full_dfs(BinaryTree* tree);

// all the levels are completely filled except possibly for the last level, which is filled from left to right.
bool is_complete_bfs(BinaryTree* tree);
bool is_complete_dfs(BinaryTree* tree);

// all the leaf nodes are at the same level, and all the non-leaf nodes have exactly 2 children
bool is_perfect_bfs(BinaryTree* tree);
bool is_perfect_dfs(BinaryTree* tree);

// the difference between the heights of the left and right subtrees of every node is not more than 1
bool is_balanced_bfs(BinaryTree* tree);
bool is_balanced_dfs(BinaryTree* tree);

// a tree where each node has only one child node or none  
bool is_skewed_bfs(BinaryTree* tree);
bool is_skewed_dfs(BinaryTree* tree);

// a tree where each node has only one child node or none and the child is always on the left
bool is_left_skewed_bfs(BinaryTree* tree);
bool is_left_skewed_dfs(BinaryTree* tree);

// a tree where each node has only one child node or none and the child is always on the right
bool is_right_skewed_bfs(BinaryTree* tree);
bool is_right_skewed_dfs(BinaryTree* tree);

bool is_subtree_bfs(BinaryTree* tree, BinaryTree* subtree);
bool is_subtree_dfs(BinaryTree* tree, BinaryTree* subtree);
#endif // BINARY_TREE_UTILS_H
