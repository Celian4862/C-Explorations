#ifndef PQ_H
#define PQ_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 16

typedef struct {
    int *arr, max, lastIdx;
} Heap;

bool initHeap(Heap*);
bool resizeHeap(Heap*);
bool insertHeap(Heap*, int);
bool rmHeap(Heap*);
bool heapify(Heap*);

void breadth_first(Heap, int);
void preorder(Heap, int);
void inorder(Heap, int);
void postorder(Heap, int);

#endif