#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "Queue/binary_tree_node_queue.h"
#include "binary_tree_node.h"

BinaryTreeNode* binary_tree_create_node(int val) {
    BinaryTreeNode* new_node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

static void binary_tree_check_valid(BinaryTree* tree) {
    if (tree == NULL) {
        fprintf(stderr, "tree is not initialized\n");
        exit(EXIT_FAILURE);
    }
}

BinaryTree* binary_tree_init() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

BinaryTreeNode* binary_tree_insert_node_bfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    BinaryTreeNode* new_node = binary_tree_create_node(val);

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        Queue* queue = queue_init();
        queue_enqueue(queue, tree->root);
        while (!queue_is_empty(queue)) {
            BinaryTreeNode* node = queue_dequeue(queue);
            if (node->left == NULL) {
                node->left = new_node;
                break;
            } else {
                queue_enqueue(queue, node->left);
            }
            if (node->right == NULL) {
                node->right = new_node;
                break;
            } else {
                queue_enqueue(queue, node->right);
            }
        }
        queue_free(queue);
    }

    return new_node;
}

BinaryTreeNode* find_node_bfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* node = queue_dequeue(queue);
        if (node->val == val) {
            // queue_free(queue);
            return node;
        }
        if (node->left != NULL) {
            queue_enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            queue_enqueue(queue, node->right);
        }
    }
    // queue_free(queue);

    return NULL;
}

static BinaryTreeNode* find_node_dfs_helper(BinaryTreeNode* node, int val) {
    if (node == NULL) {
        return NULL;
    }
    if (node->val == val) {
        return node;
    }
    BinaryTreeNode* left_result = find_node_dfs_helper(node->left, val);
    if (left_result != NULL) {
        return left_result;
    }
    return find_node_dfs_helper(node->right, val);
}

BinaryTreeNode* find_node_dfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    return find_node_dfs_helper(tree->root, val);
}

BinaryTreeNode* find_last_node_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    Queue* queue = queue_init();
    BinaryTreeNode* last_node = NULL;
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        last_node = queue_dequeue(queue);
        if (last_node->left != NULL) {
            queue_enqueue(queue, last_node->left);
        }
        if (last_node->right != NULL) {
            queue_enqueue(queue, last_node->right);
        }
    }
    queue_free(queue);

    return last_node;
}

static BinaryTreeNode* find_last_node_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return NULL;
    }

    BinaryTreeNode* left_last = find_last_node_dfs_helper(node->left);
    BinaryTreeNode* right_last = find_last_node_dfs_helper(node->right);

    if (right_last != NULL) {
        return right_last;
    }
    if (left_last != NULL) {
        return left_last;
    }

    return node;
}

BinaryTreeNode* find_last_node_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    return find_last_node_dfs_helper(tree->root);
}

BinaryTreeNode* find_parent_node_bfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL || tree->root->val == val) {
        return NULL;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current = queue_dequeue(queue);
        if ((current->left && current->left->val == val) ||
            (current->right && current->right->val == val)) {
            queue_free(queue);
            return current;
        }
        if (current->left != NULL) {
            queue_enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            queue_enqueue(queue, current->right);
        }
    }
    queue_free(queue);
    return NULL;
}

static BinaryTreeNode* find_parent_node_dfs_helper(BinaryTreeNode* current_node, int val) {
    if (current_node == NULL) {
        return NULL;
    }
    if ((current_node->left != NULL && current_node->left->val == val) ||
        (current_node->right != NULL && current_node->right->val == val)) {
        return current_node;
    }

    BinaryTreeNode* left_result = find_parent_node_dfs_helper(current_node->left, val);
    if (left_result != NULL) {
        return left_result;
    }

    return find_parent_node_dfs_helper(current_node->right, val);
}

BinaryTreeNode* find_parent_node_dfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL || tree->root->val == val) {
        return NULL;
    }

    return find_parent_node_dfs_helper(tree->root, val);
}

void delete_node_bfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    BinaryTreeNode* delete_node = find_node_bfs(tree, val);
    if (delete_node == NULL) {
        return;
    }

    BinaryTreeNode* last_node = find_last_node_bfs(tree);
    BinaryTreeNode* last_node_parent = find_parent_node_bfs(tree, last_node->val);

    if (delete_node == last_node) {
        if (delete_node == tree->root) {
            tree->root = NULL;
        } else {
            if (last_node_parent->left == last_node) {
                last_node_parent->left = NULL;
            } else {
                last_node_parent->right = NULL;
            }
        }
        free(delete_node);
        return;
    }

    delete_node->val = last_node->val;

    if (last_node_parent->left == last_node) {
        last_node_parent->left = NULL;
    } else {
        last_node_parent->right = NULL;
    }
    free(last_node);
}

void delete_node_dfs(BinaryTree* tree, int val) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    BinaryTreeNode* delete_node = find_node_dfs(tree, val);
    if (delete_node == NULL) {
        return;
    }

    BinaryTreeNode* last_node = find_last_node_dfs(tree);
    BinaryTreeNode* last_node_parent = find_parent_node_dfs(tree, last_node->val);

    if (delete_node == last_node) {
        if (tree->root == delete_node) {
            tree->root = NULL;
        } else {
            if (last_node_parent->left == last_node) {
                last_node_parent->left = NULL;
            } else {
                last_node_parent->right = NULL;
            }
        }
        free(delete_node);
        return;
    }

    delete_node->val = last_node->val;

    if (last_node_parent->left == last_node) {
        last_node_parent->left = NULL;
    } else {
        last_node_parent->right = NULL;
    }
    free(last_node);
}

void free_tree_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);
    if (tree->root == NULL) {
        return;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current = queue_dequeue(queue);
        if (current->left != NULL) {
            queue_enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            queue_enqueue(queue, current->right);
        }
        free(current);
    }
    queue_free(queue);
    free(tree);
}

static void free_tree_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return;
    }
    free_tree_dfs_helper(node->left);
    free_tree_dfs_helper(node->right);
    free(node);
}

void free_tree_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);
    free_tree_dfs_helper(tree->root);
    free(tree);
}

BinaryTree* generate_tree_bfs(int arr[], int size) {
    BinaryTree* tree = binary_tree_init();
    for (int i = 0; i < size; i++) {
        binary_tree_insert_node_bfs(tree, arr[i]);
    }
    return tree;
}

BinaryTreeNode* find_min_node_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }
    BinaryTreeNode* min_node = tree->root;
    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node->val < min_node->val) {
            min_node = current_node;
        }
        if (current_node->left != NULL) {
            queue_enqueue(queue, current_node->left);
        }
        if (current_node->right != NULL) {
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);

    return min_node;
}

static BinaryTreeNode* find_min_node_dfs_helper(BinaryTreeNode* current_node) {
    if (current_node == NULL) {
        return NULL;
    }

    BinaryTreeNode* min_node = current_node;

    BinaryTreeNode* left_min_node = find_min_node_dfs_helper(current_node->left);
    if (left_min_node != NULL && (left_min_node->val < min_node->val)) {
        min_node = left_min_node;
    }

    BinaryTreeNode* right_min_node = find_min_node_dfs_helper(current_node->right);
    if (right_min_node != NULL && (right_min_node->val < min_node->val)) {
        min_node = right_min_node;
    }

    return min_node;
}

BinaryTreeNode* find_min_node_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    return find_min_node_dfs_helper(tree->root);
}

BinaryTreeNode* find_max_node_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }
    BinaryTreeNode* max_node = tree->root;
    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node->val > max_node->val) {
            max_node = current_node;
        }
        if (current_node->left != NULL) {
            queue_enqueue(queue, current_node->left);
        }
        if (current_node->right != NULL) {
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);

    return max_node;
}

static BinaryTreeNode* find_max_node_dfs_helper(BinaryTreeNode* current_node) {
    if (current_node == NULL) {
        return NULL;
    }

    BinaryTreeNode* left_max_node = find_max_node_dfs_helper(current_node->left);
    if (left_max_node != NULL && (left_max_node->val > current_node->val)) {
        return left_max_node;
    }

    BinaryTreeNode* right_max_node = find_max_node_dfs_helper(current_node->right);
    if (right_max_node != NULL && (right_max_node->val > current_node->val)) {
        return right_max_node;
    }

    return current_node;
}

BinaryTreeNode* find_max_node_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return NULL;
    }

    return find_max_node_dfs_helper(tree->root);
}

static void traverse_in_order_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return;
    }
    traverse_in_order_helper(node->left);
    printf("%d ", node->val);
    traverse_in_order_helper(node->right);
}

void traverse_in_order(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    traverse_in_order_helper(tree->root);
    printf("\n");
}

static void traverse_pre_order_helper(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    traverse_pre_order_helper(root->left);
    traverse_pre_order_helper(root->right);
}

void traverse_pre_order(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    traverse_pre_order_helper(tree->root);
    printf("\n");
}

static void traverse_post_order_helper(BinaryTreeNode* root) {
    if (root == NULL) {
        return;
    }
    traverse_post_order_helper(root->left);
    traverse_post_order_helper(root->right);
    printf("%d ", root->val);
}

void traverse_post_order(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    traverse_post_order_helper(tree->root);
    printf("\n");
}

void traverse_level_order(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current = queue_dequeue(queue);
        printf("%d ", current->val);
        if (current->left != NULL) {
            queue_enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            queue_enqueue(queue, current->right);
        }
    }
    printf("\n");
    queue_free(queue);
}

int get_size_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return 0;
    }

    int size = 0;
    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current = queue_dequeue(queue);
        size++;
        if (current->left != NULL) {
            queue_enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            queue_enqueue(queue, current->right);
        }
    }
    queue_free(queue);
    return size;
}

static int get_size_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + get_size_dfs_helper(node->left) + get_size_dfs_helper(node->right);
}

int get_size_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return 0;
    }

    return get_size_dfs_helper(tree->root);
}

int get_height(BinaryTreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = get_height(node->left);
    int right_height = get_height(node->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}

int get_depth(BinaryTreeNode* root, BinaryTreeNode* node) {
    if (root == NULL) {
        return -1;
    }

    if (root == node) {
        return 0;
    }

    int left_depth = get_depth(root->left, node);
    if (left_depth >= 0) {
        return 1 + left_depth;
    }

    int right_depth = get_depth(root->right, node);
    if (right_depth >= 0) {
        return 1 + right_depth;
    }

    return -1;
}

bool is_empty(BinaryTree* tree) {
    binary_tree_check_valid(tree);
    return tree->root == NULL;
}

bool is_in_tree_bfs(BinaryTree* tree, BinaryTreeNode* node) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL || node == NULL) {
        return false;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node == node) {
            queue_free(queue);
            return true;
        }
        if (current_node->left != NULL) {
            queue_enqueue(queue, current_node->left);
        }
        if (current_node->right != NULL) {
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);

    return false;
}

static bool is_in_tree_dfs_helper(BinaryTreeNode* current_node, BinaryTreeNode* node) {
    if (current_node == NULL) {
        return false;
    }

    if (current_node == node) {
        return true;
    }

    return (is_in_tree_dfs_helper(current_node->left, node)) || is_in_tree_dfs_helper(current_node->right, node);
}

bool is_in_tree_dfs(BinaryTree* tree, BinaryTreeNode* node) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL || node == NULL) {
        return false;
    }

    return is_in_tree_dfs_helper(tree->root, node);
}

bool is_internal(BinaryTreeNode* node) {
    return node != NULL && (node->left != NULL || node->right != NULL);
}

bool is_external(BinaryTreeNode* node) {
    return node != NULL && (node->left == NULL && node->right == NULL);
}

bool is_parent(BinaryTreeNode* parent, BinaryTreeNode* node) {
    if (parent == NULL || node == NULL) {
        return false;
    }
    return parent->left == node || parent->right == node;
}

bool is_child(BinaryTreeNode* child, BinaryTreeNode* node) {
    if (child == NULL || node == NULL) {
        return false;
    }
    return  node->left == child || node->right == child;
}

bool is_ancestor(BinaryTreeNode* ancestor, BinaryTreeNode* node) {
    if (ancestor == NULL || node == NULL) {
        return false;
    }
    if (is_parent(ancestor, node)) {
        return true;
    }
    return is_ancestor(ancestor->left, node) || is_ancestor(ancestor->right, node);
}

bool is_descendant(BinaryTreeNode* descendant, BinaryTreeNode* node) {
    if (descendant == NULL || node == NULL) {
        return false;
    }
    if (is_child(descendant, node)) {
        return true;
    }
    return is_descendant(descendant, node->left) || is_descendant(descendant, node->right);
}

bool is_sibling(BinaryTree* tree, BinaryTreeNode* node1, BinaryTreeNode* node2) {
    binary_tree_check_valid(tree);

    if (node1 == NULL || node2 == NULL || node1 == node2 || tree->root == NULL) {
        return false;
    }

    BinaryTreeNode* parent_node = find_parent_node_bfs(tree, node1->val);
    if (parent_node == NULL) {
        return false;
    }

    return (parent_node->left == node2) || (parent_node->right == node2);
}

bool is_cousin(BinaryTree* tree, BinaryTreeNode* node1, BinaryTreeNode* node2) {
    binary_tree_check_valid(tree);

    if (node1 == NULL || node2 == NULL || node1 == node2 || tree->root == NULL) {
        return false;
    }

    int depth_of_node1 = get_depth(tree->root, node1);
    if (depth_of_node1 == -1) {
        return false;
    }

    int depth_of_node2 = get_depth(tree->root, node2);
    if (depth_of_node2 == -1) {
        return false;
    }

    return (depth_of_node1 == depth_of_node2) && !is_sibling(tree, node1, node2);
}

bool is_full_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return false;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        bool no_child = (current_node->left == NULL) && (current_node->right == NULL);
        bool two_child = (current_node->left != NULL) && (current_node->right != NULL);
        if (!no_child && !two_child) {
            queue_free(queue);
            return false;
        }
        if (current_node->left != NULL) {
            queue_enqueue(queue, current_node->left);
        }
        if (current_node->right != NULL) {
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);
    return true;
}

static bool is_full_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return true;
    }

    bool no_child = (node->left == NULL) && (node->right == NULL);
    if (no_child) {
        return true;
    }

    bool two_child = (node->left != NULL) && (node->right != NULL);
    if (two_child) {
        return is_full_dfs_helper(node->left) && is_full_dfs_helper(node->right);
    }

    return false;
}

bool is_full_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return false;
    }

    return is_full_dfs_helper(tree->root);
}

bool is_complete_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    bool end_of_complete_tree = false;
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node == NULL) {
            end_of_complete_tree = true;
        } else {
            if (end_of_complete_tree) {
                queue_free(queue);
                return false;
            }
            queue_enqueue(queue, current_node->left);
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);

    return true;
}

static bool is_complete_dfs_helper(int height, BinaryTreeNode* node, bool* end_of_complete_tree) {
    if (node == NULL) {
        if (height == 0) {
            return true;
        } else if (height == 1) {
            *end_of_complete_tree = true;
            return  true;
        } else {
            return false;
        }
    }

    if (height == 1) {
        return !(*end_of_complete_tree);
    }

    return is_complete_dfs_helper(height - 1, node->left, end_of_complete_tree) &&
        is_complete_dfs_helper(height - 1, node->right, end_of_complete_tree);
}

bool is_complete_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true; // 空樹被認為是完全二叉樹
    }

    int height = get_height(tree->root);
    bool end_of_complete_tree = false;
    bool result = is_complete_dfs_helper(height, tree->root, &end_of_complete_tree);
    return result;
}

bool is_perfect_bfs_alternative(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    int height = get_height(tree->root);
    int expected_total_nodes = (1 << height) - 1;
    int actual_total_nodes = get_size_bfs(tree);

    return (actual_total_nodes == expected_total_nodes);
}

bool is_perfect_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    int node_counts = 0;
    bool seen_null_child = false;
    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);

        if (current_node == NULL) {
            seen_null_child = true;
        } else {
            if (seen_null_child) {
                queue_free(queue);
                return false;
            }
            node_counts++;
            queue_enqueue(queue, current_node->left);
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);
    return (((node_counts + 1) & node_counts) == 0);
}

static bool is_perfect_dfs_alternative_helper(int height, BinaryTreeNode* node) {
    if (node == NULL) {
        return (height == 0);
    }

    return is_perfect_dfs_alternative_helper(height - 1, node->left) &&
        is_perfect_dfs_alternative_helper(height - 1, node->right);
}

bool is_perfect_dfs_alternative(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return is_perfect_dfs_alternative_helper(get_height(tree->root), tree->root);
}

static int is_perfect_dfs_helper(BinaryTreeNode* current_node, int depth) {
    if (current_node == NULL) {
        return depth;
    }

    int left_depth = is_perfect_dfs_helper(current_node->left, depth + 1);
    if (left_depth == -1) {
        return -1;
    }

    int right_depth = is_perfect_dfs_helper(current_node->right, depth + 1);
    if (right_depth == -1) {
        return -1;
    }

    if (left_depth != right_depth) {
        return -1;
    }

    return left_depth;
}

bool is_perfect_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return (is_perfect_dfs_helper(tree->root, 0) != -1);
}

// not good at performance
bool is_balanced_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);

        int left_height = 0;
        int right_height = 0;

        if (current_node->left != NULL) {
            queue_enqueue(queue, current_node->left);
            left_height = get_height(current_node->left);
        }

        if (current_node->right != NULL) {
            queue_enqueue(queue, current_node->right);
            right_height = get_height(current_node->right);
        }

        if (abs(left_height - right_height) > 1) {
            queue_free(queue);
            return false;
        }
    }
    queue_free(queue);
    return true;
}

static int is_balanced_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int left_height = is_balanced_dfs_helper(node->left);
    if (left_height == -1) {
        return -1; // 左子樹不平衡
    }

    int right_height = is_balanced_dfs_helper(node->right);
    if (right_height == -1) {
        return -1; // 右子樹不平衡
    }

    if (abs(left_height - right_height) > 1) {
        return -1; // 當前節點不平衡
    }

    return 1 + (left_height > right_height ? left_height : right_height);
}

bool is_balanced_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return (is_balanced_dfs_helper(tree->root) != -1);
}

bool is_skewed_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node->left != NULL) {
            if (current_node->right != NULL) {
                queue_free(queue);
                return false;
            }
            queue_enqueue(queue, current_node->left);
        } else {
            if (current_node->right == NULL) {
                break;
            }
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);
    return true;
}

static bool is_skewed_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return true;
    }

    if (node->left) {
        if (node->right) {
            return false;
        }
        return is_skewed_dfs_helper(node->left);
    }

    if (node->right) {
        return is_skewed_dfs_helper(node->right);
    }

    return true;
}

bool is_skewed_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return is_skewed_dfs_helper(tree->root);
}

bool is_left_skewed_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node->right) {
            queue_free(queue);
            return false;
        }
        if (current_node->left) {
            queue_enqueue(queue, current_node->left);
        }
    }
    queue_free(queue);

    return true;
}

static bool is_left_skewed_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return true;
    }
    if (node->right != NULL) {
        return false;
    }
    return is_left_skewed_dfs_helper(node->left);
}

bool is_left_skewed_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return is_left_skewed_dfs_helper(tree->root);
}

bool is_right_skewed_bfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);
    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);
        if (current_node->left) {
            queue_free(queue);
            return false;
        }
        if (current_node->right) {
            queue_enqueue(queue, current_node->right);
        }
    }
    queue_free(queue);

    return true;
}

static bool is_right_skewed_dfs_helper(BinaryTreeNode* node) {
    if (node == NULL) {
        return true;
    }
    if (node->left != NULL) {
        return false;
    }
    return is_right_skewed_dfs_helper(node->right);
}

bool is_right_skewed_dfs(BinaryTree* tree) {
    binary_tree_check_valid(tree);

    if (tree->root == NULL) {
        return true;
    }

    return is_right_skewed_dfs_helper(tree->root);
}

static bool is_subtree_bfs_helper(BinaryTreeNode* tree_node, BinaryTreeNode* subtree_node) {
    Queue* queue_tree = queue_init();
    Queue* queue_subtree = queue_init();

    queue_enqueue(queue_tree, tree_node);
    queue_enqueue(queue_subtree, subtree_node);

    while (!queue_is_empty(queue_tree) && !queue_is_empty(queue_subtree)) {
        BinaryTreeNode* current_tree_node = queue_dequeue(queue_tree);
        BinaryTreeNode* current_subtree_node = queue_dequeue(queue_subtree);

        if (current_tree_node == NULL && current_subtree_node == NULL) {
            continue;
        }

        if (current_tree_node == NULL || current_subtree_node == NULL) {
            queue_free(queue_tree);
            queue_free(queue_subtree);
            return false;
        }

        if (current_tree_node->val != current_subtree_node->val) {
            queue_free(queue_tree);
            queue_free(queue_subtree);
            return false;
        }

        queue_enqueue(queue_tree, current_tree_node->left);
        queue_enqueue(queue_subtree, current_subtree_node->left);

        queue_enqueue(queue_tree, current_tree_node->right);
        queue_enqueue(queue_subtree, current_subtree_node->right);
    }

    bool result = queue_is_empty(queue_tree) && queue_is_empty(queue_subtree);
    queue_free(queue_tree);
    queue_free(queue_subtree);
    return result;
}

bool is_subtree_bfs(BinaryTree* tree, BinaryTree* subtree) {
    binary_tree_check_valid(tree);
    binary_tree_check_valid(subtree);

    if (subtree->root == NULL) {
        return true;
    }

    if (tree->root == NULL) {
        return false;
    }

    Queue* queue = queue_init();
    queue_enqueue(queue, tree->root);

    while (!queue_is_empty(queue)) {
        BinaryTreeNode* current_node = queue_dequeue(queue);

        if (current_node->val == subtree->root->val) {
            if (is_subtree_bfs_helper(current_node, subtree->root)) {
                queue_free(queue);
                return true;
            }
            queue_free(queue);
            return false;
        }

        if (current_node->left) {
            queue_enqueue(queue, current_node->left);
        }

        if (current_node->right) {
            queue_enqueue(queue, current_node->right);
        }
    }

    queue_free(queue);
    return false;
}

static bool is_subtree_dfs_helper(BinaryTreeNode* tree_node, BinaryTreeNode* subtree_node) {
    if (tree_node == NULL && subtree_node == NULL) {
        return true;
    }

    if (tree_node == NULL || subtree_node == NULL) {
        return false;
    }

    if (tree_node->val != subtree_node->val) {
        return false;
    }

    return is_subtree_dfs_helper(tree_node->left, subtree_node->left) &&
        is_subtree_dfs_helper(tree_node->right, subtree_node->right);
}

static BinaryTreeNode* find_subtree_root(BinaryTreeNode* tree_node, BinaryTreeNode* subtree_root) {
    if (subtree_root == NULL || tree_node == NULL) {
        return  NULL;
    }

    if (tree_node->val == subtree_root->val) {
        return tree_node;
    }

    BinaryTreeNode* left_result = find_subtree_root(tree_node->left, subtree_root);
    if (left_result != NULL) {
        return left_result;
    }

    return find_subtree_root(tree_node->right, subtree_root);
}

bool is_subtree_dfs(BinaryTree* tree, BinaryTree* subtree) {
    binary_tree_check_valid(tree);
    binary_tree_check_valid(subtree);

    if (subtree->root == NULL) {
        return true;
    }

    if (tree->root == NULL) {
        return false;
    }

    return is_subtree_dfs_helper(find_subtree_root(tree->root, subtree->root), subtree->root);
}