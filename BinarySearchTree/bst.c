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
    BST temp = (BST) malloc (sizeof(BST));
    temp->left = temp->right = NULL;
    if (!temp) {
        return false;
    }
    temp->data = data;
    *trav = temp;
    return true;
}

void breadth_first(BST node) {
    QueueADT q = (QueueADT) malloc (sizeof(QueueADT));
    q->head = q->tail = (QueuePtr) malloc (sizeof(QueueNode));
    if (!q->head) {
        printf("Memory allocation failed.");
        return;
    }
    q->tail->node = node;
    q->tail->link = NULL;
    while (q->head) {
        printf("%d ", q->head->node->data);

        QueuePtr temp1, temp2;

        if (q->head->node->left && q->head->node->right) {
            // Create new queue elements for next left child and next right child
            temp1 = (QueuePtr) malloc (sizeof(QueueNode)), temp2 = (QueuePtr) malloc (sizeof(QueueNode));

            // Let temp1's node point to the next left child
            temp1->node = q->head->node->left;
            // Let temp1's link point to temp2 to know the next element in the queue
            temp1->link = temp2;

            // Let temp2's node point to the next right child
            temp2->node = q->head->node->right;
            temp2->link = NULL;

            // Let tail's link point to the next left child
            q->tail->link = temp1;
            // Let tail point to the next right child (last element in queue)
            q->tail = temp2;
        }
        // Let temp1 point to head
        temp1 = q->head;
        // Let head move to the next element in the queue
        q->head = q->head->link;
        // Free the node
        free(temp1);
    }
    free(q);
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
    for (int i = 0; i < 4; i++) {
        display[i](tree);
        printf("\n");
    }
}