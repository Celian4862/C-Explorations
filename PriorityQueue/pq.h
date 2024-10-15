#ifndef PQ_H
#define PQ_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int *arr, max, count;
} Heap;

bool initHeap(Heap*, int max);
bool resizeHeap(Heap*, int max);
bool insertHeap(Heap*, int data);
bool rmHeap(Heap*);
bool heapify(Heap*);

void breadth_first(Heap, int);
void preorder(Heap, int);
void inorder(Heap, int);
void postorder(Heap, int);

#endif