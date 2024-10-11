#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void (*display[4]) (BST) = {breadth_first, preorder, inorder, postorder};

void init(BST *tree) {
    *tree = NULL;
}

bool insert(BST *tree, int data) {
    BST *trav = tree;
    while (*trav) {
        trav = (data < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
    }
    BST temp = (BST) calloc (sizeof(BST), 1);
    if (!temp) {
        return false;
    }
    temp->data = data;
    *trav = temp;
    return true;
}

// Incomplete
void breadth_first(BST node) {
    QueueADT q = NULL;
    NodePtr head, tail;
    
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

void allDisplay(BST tree) {
    for (int i = 0; i < 3; i++) {
        display[i](tree);
        printf("\n");
    }
}