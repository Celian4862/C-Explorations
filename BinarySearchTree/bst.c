#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void (*display[3]) (NodePtr) = {preorder, inorder, postorder};

void init(BST *tree) {
    *tree = NULL;
}

bool insert(BST *tree, int data) {
    NodePtr *trav = tree;
    while (*trav) {
        trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
    }
    NodePtr temp = (NodePtr) calloc (sizeof(NodeType), 1);
    if (!temp) {
        return false;
    }
    temp->data = data;
    *trav = temp;
    return true;
}

void preorder(BST node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(BST node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(BST node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void allDisplay(NodePtr tree) {
    for (int i = 0; i < 3; i++) {
        display[i](tree);
        printf("\n");
    }
}