#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

typedef struct BinaryTreeNode {
    int val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

#endif // BINARY_TREE_NODE_H
