#ifndef BST_H
#define BST_H
#include <stdbool.h>

// Hidden variable
// void (*display[3])(NodePtr) = {preorder, inorder, postorder};

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

void init(NodePtr*);
bool insert(NodePtr *, int);
void preorder(NodePtr);
void inorder(NodePtr);
void postorder(NodePtr);
void allDisplay(NodePtr);

#endif
