#ifndef AVL_H
#define AVL_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *AVL;

#endif