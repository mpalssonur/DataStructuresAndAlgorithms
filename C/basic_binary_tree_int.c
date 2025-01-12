#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node* parent;
    struct Node* left_child;
    struct Node *right_child;
};

struct BinaryTree {
    struct Node* root;
    int size;
    int depth;
};

struct BinaryTree* init_tree() {
    struct BinaryTree* tree = malloc(sizeof(struct BinaryTree));
    tree->root = NULL;
    tree->size = tree->depth = 0;
    return tree;
}

struct Node* create_node(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->parent = NULL;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

void tree_node_insert(struct Node* node, int value) {
    if (value < node->data) {
        if (node->left_child) {
            tree_node_insert(node->left_child, value);
        }
        else {
            struct Node* new_node = create_node(value);
            new_node->parent = node;
            node->left_child = new_node;
        }
    }
    else {
        if (node->right_child) {
            tree_node_insert(node->right_child, value);
        }
        else {
            struct Node* new_node = create_node(value);
            new_node->parent = node;
            node->right_child = new_node;
        }
    }
}

void tree_insert(struct BinaryTree* tree, int value) {
    if (tree->root) {
        tree_node_insert(tree->root, value);
    }
    else {
        struct Node* new_node = create_node(value);
        tree->root = new_node;
    }
}

bool tree_contains(struct BinaryTree* tree, int value) {
    struct Node* current = tree->root;
    while(current) {
        if (value < current->data) {
            current = current->left_child;
        }
        else if (value > current->data) {
            current = current->right_child;
        }
        else {
            return true;
        }
    }
    return false;
}

void tree_remove_root(struct BinaryTree* tree) {
    if (tree->root == NULL) return;
    struct Node* old_root = tree->root;
    if (old_root->right_child == NULL) {
        tree->root = old_root->left_child;
        if (tree->root) {
            tree->root->parent = NULL;
        }
        //____________________________
        //
        //
        //
        //
        //
    }
}

bool tree_delete_single(struct BinaryTree* tree, int value) {
    struct Node* current = tree->root;
    while(current) {
        
        if (value < current->data) {
            current = current->left_child;
        }
        else if (value > current->data) {
            current = current->right_child;
        }
        else {
            if (current->parent == NULL) {}
            if (current == current->parent->left_child) {}
            if (current == current->parent->right_child) {}
            return true;
        }
    }
    return false;
}











